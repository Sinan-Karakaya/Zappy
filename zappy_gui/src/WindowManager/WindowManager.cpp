/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** WindowManager
*/

#include "WindowManager.hpp"

zp::WindowManager::WindowManager(const std::string &title, const sf::Vector2u &size, const std::string &ip, const
std::string &port, bool &isConnected)
    : m_ip(ip), m_port(port), m_isConnected(isConnected)
{
    spdlog::info("Initializing WindowManager");
    m_window.create(sf::VideoMode(size.x, size.y), title, sf::Style::Default | sf::Style::Resize);
    m_window.setFramerateLimit(60);
    m_window.setKeyRepeatEnabled(false);
    if (!m_gameTexture.create(2000, 2000))
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
    m_gameView.setSize(2000, 2000);
    m_gameView.setCenter(m_gameView.getSize().x / 2, m_gameView.getSize().y / 2);
    m_gameTexture.setView(m_gameView);
}

zp::WindowManager::~WindowManager()
{
    spdlog::info("Shutting down WindowManager");
    ImGui::SFML::Shutdown();
}

void zp::WindowManager::update(std::unique_ptr<zp::Map> &map, std::unique_ptr<zp::Chat> &chat)
{
    handleEvents();
    m_gameTexture.clear();
    m_gameTexture.draw(m_backgroundSprite);
    map->drawMap(m_gameTexture);
    drawImGui(*map, *chat);
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
            if (event.mouseWheelScroll.delta > 0)
                m_gameView.zoom(0.9);
            if (event.mouseWheelScroll.delta < 0)
                m_gameView.zoom(1.1);
        }
    }
}

void zp::WindowManager::drawImGui(const zp::Map &map, const zp::Chat &chat)
{
    ImGui::SFML::Update(m_window, m_deltaClock.restart());
    ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

    if (m_isConnected) {
        drawChat(chat, const_cast<zp::Map &>(map));
        drawGame();
        drawControlPanel(map);
    } else {
        drawConnection();
    }
}

void zp::WindowManager::drawChat(const zp::Chat &chat, zp::Map &map)
{
    auto messages = chat.getMessages();
    ImGui::Begin("Chat");
    ImGui::BeginChild("Chat Messages", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));

    auto aliens = map.getAliens();
    auto colors = zp::TeamManager::getTeamsColors();
    for (auto &message : messages) {
        auto it = std::find_if(aliens.begin(), aliens.end(), [&message](const auto &alien) {
            return alien->getId() == std::stoi(message.first);
        });
        if (it != aliens.end()) {
            auto color = colors[(*it)->getTeamName()];
            ImGui::PushStyleColor(ImGuiCol_Text, color);
            ImGui::TextWrapped("%s: %s", message.first.c_str(), message.second.c_str());
            ImGui::PopStyleColor();
        } else {
            ImGui::TextWrapped("%s: %s", message.first.c_str(), message.second.c_str());
        }
    }
    ImGui::EndChild();
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

void zp::WindowManager::drawControlPanel(const zp::Map &map)
{
    ImGui::Begin("Details");
    if (ImGui::BeginTabBar("Panels")) {
        if (ImGui::BeginTabItem("Control Panel")) {
            ImGui::Text("Connected to %s:%s", m_ip.c_str(), m_port.c_str()); ImGui::SameLine();
            if (ImGui::Button("Disconnect"))
                ImGui::OpenPopup("Disconnect?");

            ImVec2 center = ImGui::GetMainViewport()->GetCenter();
            ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
            ImGui::SetNextWindowSize(ImVec2(90, 65));
            if (ImGui::BeginPopupModal("Disconnect?", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
                if (ImGui::Button("Yes")) {
                    zp::NetworkManager::addMessage("quit\n");
                    ImGui::CloseCurrentPopup();
                }
                ImGui::SameLine();
                if (ImGui::Button("No"))
                    ImGui::CloseCurrentPopup();
                ImGui::EndPopup();
            }

            ImGui::NewLine();
            ImGui::Text("Current time modifier: %d", map.getTimeUnitModifier());
            static int timeModif = 5000;
            ImGui::SliderInt("##", &timeModif, 2, 10000); ImGui::SameLine();
            if (ImGui::Button("Update") && timeModif != 0) {
                zp::NetworkManager::addMessage("sst " + std::to_string(timeModif) + "\n");
            }

            ImGui::NewLine();
            ImGui::Text("Teams:");
            auto teams = map.getTeams();
            for (auto &team : teams) {
                auto teamColor = zp::TeamManager::getTeamColor(team);
                ImVec4 newColor = teamColor;
                std::string labelName = team + " color";

                ImGui::ColorEdit3(labelName.c_str(), (float*)&newColor, ImGuiColorEditFlags_NoInputs |
                ImGuiColorEditFlags_NoLabel);
                if (newColor != teamColor)
                    zp::TeamManager::setTeamColor(team, newColor);
                ImGui::SameLine();

                ImGui::PushStyleColor(ImGuiCol_Text, teamColor);
                ImGui::Text("%s", team.c_str());
                ImGui::PopStyleColor();
            }
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Tiles Panel")) {
            ImGui::Text("Tile Coordinates:");

            std::vector<std::string> xPos;
            std::vector<std::string> yPos;
            static std::size_t x_current_idx = 0;
            static std::size_t y_current_idx = 0;

            for (int i = 0; i < map.getSize().x; i++)
                xPos.push_back(std::to_string(i));
            for (int i = 0; i < map.getSize().y; i++)
                yPos.push_back(std::to_string(i));
            
            std::string x_combo_preview_value = xPos[x_current_idx];
            if (ImGui::BeginCombo("X position", x_combo_preview_value.c_str())) {
                for (std::size_t n = 0; n < xPos.size(); n++) {
                    const bool is_selected = (x_current_idx == n);
                    if (ImGui::Selectable(xPos[n].c_str(), is_selected))
                        x_current_idx = n;
                    if (is_selected)
                        ImGui::SetItemDefaultFocus();
                }
                ImGui::EndCombo();
            }

            std::string y_combo_preview_value = yPos[y_current_idx];
            if (ImGui::BeginCombo("Y position", y_combo_preview_value.c_str())) {
                for (std::size_t n = 0; n < yPos.size(); n++) {
                    const bool is_selected = (y_current_idx == n);
                    if (ImGui::Selectable(yPos[n].c_str(), is_selected))
                        y_current_idx = n;
                    if (is_selected)
                        ImGui::SetItemDefaultFocus();
                }
                ImGui::EndCombo();
            }

            ImGui::NewLine();
            ImGui::Text("Ressources:");
            auto tile = map.getTile(std::stoi(xPos[x_current_idx]), std::stoi(yPos[y_current_idx]));
            auto ressources = tile.get()->getRessources();

            ImGui::Text("\tfood: %d", ressources[Rocks::FOOD]);
            ImGui::Text("\tlinemate: %d", ressources[Rocks::LINEMATE]);
            ImGui::Text("\teraumere: %d", ressources[Rocks::DERAUMERE]);
            ImGui::Text("\tsibur: %d", ressources[Rocks::SIBUR]);
            ImGui::Text("\tmendiane: %d", ressources[Rocks::MENDIANE]);
            ImGui::Text("\tphiras: %d", ressources[Rocks::PHIRAS]);
            ImGui::Text("\tthystame: %d", ressources[Rocks::THYSTAME]);
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Teams Panel")) {
            ImGui::Text("Teams:");
            auto teams = map.getTeams();
            for (auto &team : teams) {
                auto teamColor = zp::TeamManager::getTeamColor(team);
                auto aliens = map.getAliens();
                ImGui::PushStyleColor(ImGuiCol_Text, teamColor);
                ImGui::Text("\t%s:", team.c_str());
                ImGui::PopStyleColor();
                for (auto alien : aliens) {
                    auto al = alien.get();
                    if (team == al->getTeamName())
                        ImGui::Text("\t\tAlien %d", al->getId());
                }
            }
        }
        ImGui::EndTabBar();
    }
    ImGui::End();
}

void zp::WindowManager::drawConnection()
{
    static char ip[16] = "127.0.0.1";
    static int port = 4242;

    ImGui::Begin("Connection");
    ImGui::InputText("IP", ip, 16);
    ImGui::InputInt("Port", &port);
    if (ImGui::Button("Connect")) {
        zp::NetworkManager::connectionInfos(ip, std::to_string(port));
        m_ip = ip;
        m_port = std::to_string(port);
    }
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

    ImGui::GetStyle().WindowMinSize = ImVec2(300, 100);
}

bool zp::WindowManager::isOpen()
{
    return m_window.isOpen();
}
