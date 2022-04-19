#ifndef PLAYER_H
#define PLAYER_H
#include "texture.hpp"


class Player {
    private:
        SDL_Rect des;
        LTexture player;
        float x_pos;
        float y_pos;
    public:
        Player();
        ~Player();
        void setRectPlayer(SDL_Rect rect){
            des = rect;
        }
        SDL_Rect getRectPlayer(){
            return des;
        }
        bool loadImagePlayer(std::string path);
        void showImagePlayer();
        void handleMovePlayer(SDL_Event e);
};

#endif 