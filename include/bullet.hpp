#ifndef BULLET_H
#define BULLET_H
#include "texture.hpp"
class Bullet {
    private:
        LTexture bu;
        SDL_Rect des;
        float x_pos;
        float y_pos;
    public:
        Bullet();
        ~Bullet();
        void setXYpos(float u, float v){
            x_pos = u;
            y_pos = v;
        }
        void showBullet();
};

#endif 