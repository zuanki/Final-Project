#pragma once 
#include <Texture.hpp>
#include <utility>
class Bullet {
    private:
        LTexture bullet;
        SDL_Rect clip;
        std::pair<int, int> move_coor;//dx dy
        int health;
        std::pair<int, int> pos;
    public:
        Bullet();
        ~Bullet();
        bool loadBullet();
        void setHealth(int x){
            health = x;
        }
        int getHealth(){
            return health;
        }
        std::pair<int, int> getMoveCoor(){
            return move_coor;
        }
        void moveBullet(){
            pos.first += move_coor.first;
            pos.second += move_coor.second;
        }
        void setMoveCoor(int u, int v){
            move_coor = std::make_pair(u, v);
        }
        void setPosition(float u, float v){
            pos = std::make_pair(u,v);
        }
        std::pair<int, int> getPosition(){
            return pos;
        }
        void draw();
};