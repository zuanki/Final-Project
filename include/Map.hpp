#pragma once 
#include <Game.hpp>
#include <Tile.hpp>
#include <vector>
class Map {
    private:    
        std::vector<std::unique_ptr<Tile>> map;
        std::vector<std::string> map_text;
        GameDataRef data;
    public:
        Map(GameDataRef data);
        ~Map();
        void init();
        void draw();
};