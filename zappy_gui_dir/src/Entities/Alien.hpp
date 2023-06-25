/*
** EPITECH PROJECT, 2023
** src/Entities
** File description:
** Alien
*/

#pragma once

#include <spdlog/spdlog.h>

#include "IEntity.hpp"
#include "Utils/Utils.hpp"
#include "Utils/TeamManager.hpp"

#define ELEVATION_PATH "assets/sprites/elevation.png"
#define ALIEN_PATH "assets/sprites/zeologue.png"
#define ALIEN_WIDTH 84
#define ALIEN_HEIGHT 84
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define TILE_WIDTH_HALF 32
#define TILE_ESCALATION 12

namespace zp
{

class Alien : public IEntity
{
public:
    Alien() = default;
    Alien(const Alien &alien) = default;
    Alien(sf::Vector2i tilePos, Direction dir, const std::string &teamName, int id = -1);
    ~Alien() override = default;

    void drawIncantation(sf::RenderTexture &window);
    void draw(sf::RenderTexture &window) override;
    void setTilePosition(int x, int y, int mapHeight) override;
    void setDirection(Direction dir) override;
    int getId() const override { return m_id; }
    const std::string &getTeamName() const override { return m_teamName; }
    const sf::Vector2i &getPosition() const { return m_position; }
    const sf::Vector2i getTilePosition() const override { return m_tilePosition; }
    void setIncanting(bool incanting) override;

    void setLevel(int level) override { m_level = level; }
    int getLevel() const override { return m_level; }

private:
    sf::Sprite m_elevation_sprite;
    sf::Texture m_elevation_texture;
    sf::IntRect m_elevation_rect;
    sf::Clock m_clock;
    bool m_incanting;

    void setRockQuantity(Rocks rock, int quantity) override { m_inventory[rock] = quantity; }
    const std::unordered_map<Rocks, int> &getInventory() const override { return m_inventory; }
};

} // zp
