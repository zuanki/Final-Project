#include <Bullet.hpp>
#include <defs.hpp>
Bullet::Bullet(){
    this->clip.x = 0;
    this->clip.y = 0;
    this->clip.w = BULLET_WIDTH;
    this->clip.h = BULLET_HEIGHT;
    this->setPosition(0,0);
    this->setHealth(0);
}
Bullet::~Bullet(){
    //
}
bool Bullet::loadBullet(){
    bool success = true;
    if(!this->bullet.loadFromFile(BULLET_IMAGE_PATH)){
        success = false;
    }
    return success;
}
void Bullet::draw(){
    this->bullet.render(pos.first, pos.second, &clip);
}