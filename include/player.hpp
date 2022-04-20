#ifndef PLAYER_H
#define PLAYER_H
#include "texture.hpp"
#include <vector>
#include "bullet.hpp"
enum class Direction {
    up,
    down,
    right,
    left
};
class Player {
    private:
        SDL_Rect des;
        LTexture player;
        float x_pos;
        float y_pos;
        std::vector<Bullet> bullet;
        Direction dir;
        int dx; //move bullet
        int dy; //move bullet
        bool is_bullet_move;
        bool flag;
    public:
        Player();
        ~Player();
        void setRectPlayer(SDL_Rect rect){
            des = rect;
        }
        SDL_Rect getRectPlayer(){
            return des;
        }
        void setXYpos(float u, float v){
            x_pos = u;
            y_pos = v;
        }
        float getX_pos(){return x_pos;}
        float getY_pos(){return y_pos;}
        bool loadImagePlayer(std::string path);
        void showImagePlayer();
        void handleInputPlayer(SDL_Event e);
        void handleMoveBullet();
};

#endif 