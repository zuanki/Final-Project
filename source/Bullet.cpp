#include <Bullet.hpp>

Bullet::Bullet(GameDataRef data) : data(data) {
    this->health = 0;
    this->bullet_sprite.setTexture(this->data->assets.getTexture("bullet_fire"));
}
Bullet::~Bullet(){
    
}
void Bullet::draw(){
    this->data->window.draw(this->bullet_sprite);
}