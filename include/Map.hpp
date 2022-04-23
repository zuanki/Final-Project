#pragma once 
#include <Texture.hpp>
#include <vector>
#include <fstream>
#include <defs.hpp>
#include <Player.hpp>
class Map {
    friend class Player;
    private:
        std::vector<std::string> map;
        Player p;
        std::pair<int, int> move_camera;
        std::vector<std::pair<int, int>> obstacle;
        SDL_Rect camera;
        LTexture grass;
        LTexture wall;
        LTexture tree;
        LTexture fountain;
        LTexture water;
    public:
        Map();
        ~Map();
        bool loadMap();
        void handleEvent(SDL_Event e);
        bool checkCollisions(Direction dir);
        void update();
        void draw();
};