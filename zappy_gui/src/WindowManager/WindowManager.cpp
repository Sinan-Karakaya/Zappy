/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** WindowManager
*/

#include "WindowManager.hpp"

zp::WindowManager::WindowManager(const std::string &title, const sf::Vector2u &size)
{
    spdlog::info("Initializing WindowManager");
    m_window.create(sf::VideoMode(size.x, size.y), title, sf::Style::Default | sf::Style::Resize);
    m_window.setFramerateLimit(60);
    if (!m_gameTexture.create(size.x, size.y))
        throw zp::WindowManagerException("Failed to create game texture");
    m_gameSprite.setTexture(m_gameTexture.getTexture());
    spdlog::info("Initializing ImGui");
    if (!ImGui::SFML::Init(m_window))
        throw zp::WindowManagerException("Failed to initialize ImGui");
    spdlog::info("Initializing style");
    setStyle();
    if (!m_backgroundTexture.loadFromFile(BACKGROUND_PATH))
        throw zp::WindowManagerException("Failed to load background texture");
    m_backgroundSprite.setTexture(m_backgroundTexture);
    m_gameView.setSize(size.x, size.y);
    m_gameView.setCenter(size.x / 2, size.y / 2);
    m_gameTexture.setView(m_gameView);
}

zp::WindowManager::~WindowManager()
{
    spdlog::info("Shutting down WindowManager");
    ImGui::SFML::Shutdown();
}

void zp::WindowManager::update(std::unique_ptr<Map> &map)
{
    handleEvents();
    m_gameTexture.clear();
    m_gameTexture.draw(m_backgroundSprite);
    map->drawMap(m_gameTexture);
    drawImGui();
    render();
}

void zp::WindowManager::handleEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed)
            m_window.close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Q)
                m_gameView.move(-10, 0);
            if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
                m_gameView.move(10, 0);
            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Z)
                m_gameView.move(0, -10);
            if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
                m_gameView.move(0, 10);
        }
    }
}

void zp::WindowManager::drawImGui()
{
    ImGui::SFML::Update(m_window, m_deltaClock.restart());
    ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

    drawChat();
    drawGame();
    drawControlPanel();
}

void zp::WindowManager::drawChat()
{
    ImGui::Begin("Chat");
    ImGui::Text("This is the chat window");
    ImGui::End();
}

void zp::WindowManager::drawGame()
{
    m_gameSprite.setTexture(m_gameTexture.getTexture());

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::Begin("Game", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
    ImGui::Image(m_gameSprite);
    ImGui::End();
    ImGui::PopStyleVar();
}

void zp::WindowManager::drawControlPanel()
{
    ImGui::Begin("Control Panel");
    ImGui::Text("This is the control panel window");
    ImGui::End();
}

void zp::WindowManager::render()
{
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
    }
    m_window.clear();

    ImGui::SFML::Render(m_window);
    m_window.display();
}

void zp::WindowManager::setStyle()
{
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.IniFilename = "assets/imgui.ini";
    io.Fonts->Clear();
    io.Fonts->AddFontFromFileTTF(FONT_PATH, FONT_SIZE);
    if (!ImGui::SFML::UpdateFontTexture())
        throw zp::WindowManagerException("Failed to update font texture");
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows

    ImVec4* colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_WindowBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.25f, 0.25f, 0.25f, 0.54f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.50f, 0.50f, 0.50f, 0.40f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.54f, 0.54f, 0.54f, 0.67f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.97f, 0.97f, 0.97f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.57f, 0.57f, 0.57f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.77f, 0.77f, 0.77f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.26f, 0.26f, 0.26f, 1.00f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.98f, 0.98f, 0.98f, 0.67f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.95f);
    colors[ImGuiCol_Tab] = ImVec4(0.26f, 0.26f, 0.26f, 1.00f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
    colors[ImGuiCol_TabActive] = ImVec4(0.48f, 0.48f, 0.48f, 1.00f);
    colors[ImGuiCol_DockingPreview] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
}

bool zp::WindowManager::isOpen()
{
    return m_window.isOpen();
}


