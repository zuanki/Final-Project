#pragma once 
#include <Texture.hpp>
#include <vector>
#include <fstream>
#include <defs.hpp>

class Map {
    friend class Player;
    private:
        std::vector<std::string> map;
        LTexture grass;
        LTexture wall;
        LTexture tree;
        LTexture fountain;
    public:
        Map();
        ~Map();
        bool loadMap();
        void update();
        void draw();
};