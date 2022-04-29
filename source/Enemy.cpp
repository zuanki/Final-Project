#include <Enemy.hpp>
#include <Defs.hpp>
Enemy::Enemy(GameDataRef data) : data(data)
{
    this->sprite.setTexture(this->data->assets.getTexture("mantis_enemy"));
    this->sprite.setTextureRect({0, 0, 32, 32});
    this->sprite.setPosition(-64, -64);
    this->animation = std::make_unique<Animation>(32 * 7, 32 * 4, ENEMY_NUM_FRAMES, ENEMY_FRAMES_TIME);
    this->animation->setFrameRect(0, 32 * 0);
    this->animation->applyToSprite(this->sprite);
}

Enemy::~Enemy()
{
    //
}
void Enemy::moveRandom()
{
}
void Enemy::draw()
{
    this->data->window.draw(this->sprite);
}
void Enemy::update(float deltaTime)
{
    // this->moveRandom();
    this->animation->update(deltaTime);
    this->animation->applyToSprite(this->sprite);
}