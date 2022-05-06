#pragma once
#include <Game.hpp>
#include <Tile.hpp>
#include <vector>
#include <Player.hpp>
#include <Enemy.hpp>

class Map
{
private:
    std::vector<std::unique_ptr<Tile>> map;
    std::vector<std::string> map_text;
    std::vector<std::unique_ptr<Tile>> wall;
    std::unique_ptr<Tile> gate;
    std::unique_ptr<Player> player;
    std::unique_ptr<Enemy> enemy;
    GameDataRef data;

public:
    Map(GameDataRef data, int level);
    ~Map();
    void handleInput(SDL_Event e);
    void update(float deltaTime);
    void init();
    void draw();
    void checkCollisionPlayerWithWall();
    void chechCollisionPlayerWithGate();
    void checkCollisionPlayerWithEnemy();
    void checkCollisionBulletWithWall();
    void checkCollisionBulletWithEnemy();
};