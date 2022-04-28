#pragma once 
#include <Render/Sprite.hpp>
#include <Game.hpp>
class Tile {
    private:
        Sprite p;
        GameDataRef data;
    public:
        Tile(GameDataRef data);
        ~Tile();
        void setTexture(SDL_Texture* tex);
        void setPosition(int u, int v){
            p.setPosition(u, v);
        }
        void draw();
};