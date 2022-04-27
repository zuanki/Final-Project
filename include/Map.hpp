#pragma once 
#include <Game.hpp>
#include <Render/Sprite.hpp>
#include <vector>
class Map {
    private:    
        Sprite map_sprite;
        SDL_Texture* mapTexture;
        GameDataRef data;
    public:
        Map(GameDataRef data);
        ~Map();
        void draw();
};