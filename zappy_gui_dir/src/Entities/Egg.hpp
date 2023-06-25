/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Egg
*/

#pragma once

#include "IEntity.hpp"
#include "Utils/Utils.hpp"
#include "Utils/TeamManager.hpp"

#define EGG_PATH "assets/sprites/egg.png"
#define EGG_HEIGHT 95
#define EGG_WIDTH 105
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define TILE_WIDTH_HALF 32
#define TILE_ESCALATION 12

namespace zp
{

class Egg : public IEntity
{
public:
    Egg() = default;
    Egg(const Egg &egg) = default;
    Egg(sf::Vector2i tilePos, Direction dir, const std::string &teamName, int id = -1);
    ~Egg() override = default;

    void draw(sf::RenderTexture &window) override;
    void setTilePosition(int x, int y, int mapHeight) override;
    void setDirection(Direction dir) override;
    int getId() const override { return m_id; }
    const std::string &getTeamName() const override { return m_teamName; }

    void setRockQuantity(Rocks rock, int quantity) override { m_inventory[rock] = quantity; }
    const std::unordered_map<Rocks, int> &getInventory() const override { return m_inventory; }

    void setIncanting(bool incanting) override { (void)incanting; }
    const sf::Vector2i getTilePosition() const override { return m_tilePosition; }

    void setLevel(int level) override { m_level = level; }
    int getLevel() const override { return m_level; }
};

} // zp
