#include <Enemy.hpp>
#include <Defs.hpp>
Enemy::Enemy(GameDataRef data) : data(data) {
    this->sprite.setTexture(this->data->assets.getTexture("mantis_enemy"));
    this->sprite.setTextureRect({0, 0, 32, 32});
    this->sprite.setPosition(-64, -64);
    this->animation = std::make_unique<Animation>(32*7, 32*4, ENEMY_NUM_FRAMES, ENEMY_FRAMES_TIME);
    this->animation->setFrameRect(0, 32*0);
    this->animation->applyToSprite(this->sprite);
}
    
Enemy::~Enemy(){
    //
}
void Enemy::moveRandom(){
    if (this->sprite.getGlobalBounds().x > 200){
        k = 2;
    }
    else if (this->sprite.getGlobalBounds().x < 32){
        k = 1;
    }
    if (k == 0){
        this->animation->setFrameRect(0, 0);
        this->sprite.move(0, 10);
    }
    else if (k == 1){
        this->animation->setFrameRect(0, 32);
        this->sprite.move(10, 0);
    }
    else if (k == 2){
        this->animation->setFrameRect(0, 32*2);
        this->sprite.move(-10, 0);
    }
    else {
        this->animation->setFrameRect(0, 32*3);
        this->sprite.move(0, -10);
    }
}
void Enemy::draw(){
    this->data->window.draw(this->sprite);
}
void Enemy::update(){
    this->moveRandom();
    this->animation->update();
    this->animation->applyToSprite(this->sprite);
}