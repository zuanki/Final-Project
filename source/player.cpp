#include "player.hpp"


Player::Player(){
    des.x = 0;
    des.y = 0;
    des.w = 32;
    des.h = 48;
    x_pos = 13*32;
    y_pos = 10*32;
    dir = Direction::down;
    is_bullet_move = false;
    flag = true;
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
    if (is_bullet_move){
        for (int i=0;i<bullet.size();i++){
            bullet[i].showBullet();
        }
    }
    player.render(x_pos, y_pos, &des);
}
void Player::handleInputPlayer(SDL_Event e){
    switch (e.key.keysym.sym)
    {
    case SDLK_UP:    
        y_pos -= 8;
        des.y = 48*3;
        des.x+=32;
        dir = Direction::up;
        if (des.x > 32*3){
            des.x = 0;
        }
        break;
    case SDLK_DOWN:
        y_pos += 8;
        des.y = 0;
        des.x+=32;
        dir = Direction::down;
        if (des.x > 32*3){
            des.x = 0;
        }
        break;
    case SDLK_RIGHT:
        x_pos += 8;
        des.y = 48*2;
        des.x+=32;
        dir = Direction::right;
        if (des.x > 32*3){
            des.x = 0;
        }
        break;
    case SDLK_LEFT:
        x_pos -= 8;
        des.y = 48*1;
        des.x+=32;
        dir = Direction::left;
        if (des.x > 32*3){
            des.x = 0;
        }
        break;
    case SDLK_SPACE:
        {
        if (flag){
            Bullet b; 
            if (dir==Direction::down){
                dx = this->getX_pos()-3;
                dy = this->getY_pos()+32;
            }
            else if (dir==Direction::up){
                dx = this->getX_pos()-3;
                dy = this->getY_pos()+10;
            }
            else if (dir==Direction::left){
                dx = this->getX_pos()-30;
                dy = this->getY_pos()+10;
            }
            else if (dir==Direction::right){
                dx = this->getX_pos()+23;
                dy = this->getY_pos()+13;
            }
            is_bullet_move = true;
            b.setXYpos(dx,dy);
            bullet.push_back(b);
            flag = false;
            }
        }
        break;
    default:
        break;
    }
}
void Player::handleMoveBullet(){
    if (dir==Direction::up){
        dy-=5;
        if (dy<y_pos-200){
            is_bullet_move = false;
            dy = this->getY_pos();
            flag = true;
        }
    }
    else if (dir==Direction::down){
        dy+=5;
        if (dy>y_pos+200){
            is_bullet_move = false;
            dy = this->getY_pos();
            flag = true;
        }
    }
    else if (dir==Direction::left){
        dx-=5;
        if (dx<x_pos-200){
            is_bullet_move = false;
            dx = this->getX_pos();
            flag = true;
        }
    }
    else if (dir==Direction::right){
        dx+=5;
        if (dx>x_pos+200){
            is_bullet_move = false;
            dx = this->getX_pos();
            flag = true;
        }
    }
    for (int i=0;i<bullet.size();i++){
        bullet[i].setXYpos(dx,dy);
    }
}