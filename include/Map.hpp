#pragma once
#include <Game.hpp>
#include <Tile.hpp>
#include <vector>
#include <Player.hpp>
class Map
{
private:
    std::vector<std::unique_ptr<Tile>> map;
    std::vector<std::string> map_text;
    std::vector<std::unique_ptr<Tile>> wall;
    std::unique_ptr<Player> player;
    GameDataRef data;

public:
    Map(GameDataRef data);
    ~Map();
    void handleInput(SDL_Event e);
    void update(float deltaTime);
    void init();
    void draw();
    void checkCollisionWithWall();
};