#pragma once 
#include <Texture.hpp>
#include <Bullet.hpp>
#include <utility>

enum class Direction {
    up,
    down,
    left,
    right
};

class Player {
    private:
        LTexture player;
        SDL_Rect des;//clip player
        Bullet _bullet;
        std::pair<int, int> pos;
        Direction dir;
    public:
        Player();
        ~Player();
        void handleInput(SDL_Event e);
        bool loadPlayer();
        void update();
        void draw();
        void setPosition(int u, int v){
            pos = std::make_pair(u,v);
        }
        Direction getDirection(){
            return dir;
        }
        std::pair<int, int> getPosition(){
            return pos;
        }
        SDL_Rect getRect(){
            return des;
        }
};