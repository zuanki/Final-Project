#pragma once 
#include <Game.hpp>
#include <Render/Sprite.hpp>

class Map {
    private:    
        Sprite sprite_map;
        SDL_Texture* mapTexture;
        GameDataRef data;
    public:
        Map(GameDataRef data);
        ~Map();
        void draw();
};