#include "player.hpp"


Player::Player(){
    des.x = 0;
    des.y = 0;
    des.w = 32;
    des.h = 48;
    x_pos = 13*32;
    y_pos = 10*32;
}
Player::~Player(){
    //
}
bool Player::loadImagePlayer(std::string path){
    bool success = true;
    if (!player.loadFromFile(path)){
        success = false;
    }
    return success;
}
void Player::showImagePlayer(){
    player.render(x_pos, y_pos, &des);
}
void Player::handleMovePlayer(SDL_Event e){
    switch (e.key.keysym.sym)
    {
    case SDLK_UP:    
        y_pos -= 8;
        des.y = 48*3;
        des.x+=32;
        if (des.x > 32*3){
            des.x = 0;
        }
        break;
    case SDLK_DOWN:
        y_pos += 8;
        des.y = 0;
        des.x+=32;
        if (des.x > 32*3){
            des.x = 0;
        }
        break;
    case SDLK_RIGHT:
        x_pos += 8;
        des.y = 48*2;
        des.x+=32;
        if (des.x > 32*3){
            des.x = 0;
        }
        break;
    case SDLK_LEFT:
        x_pos -= 8;
        des.y = 48*1;
        des.x+=32;
        if (des.x > 32*3){
            des.x = 0;
        }
        break;
    default:
        break;
    }
}