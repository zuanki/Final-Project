#include <Bullet.hpp>
#include <Defs.hpp>

Bullet::Bullet(GameDataRef data, const Vector2f &direction) : data(data), direction(direction)
{

    this->sprite.setTexture(this->data->assets.getTexture("bullet_fire"));
    this->moveSpeed = BULLET_MOVE_SPEED;
    this->isOut = false;
}

void Bullet::update(float deltaTime)
{
    auto d = this->direction * this->moveSpeed * deltaTime;
    // std::cout << d.x << ' ' << d.y << '\n'
    this->sprite.move(this->direction * this->moveSpeed * deltaTime);
    // std::cout << this->getGlobalBounds().y << '\n';
    if (this->getGlobalBounds().y < 0)
    {
        this->setOut();
        std::cout << "Delete \n";
    }
}

void Bullet::setPosition(float x, float y)
{
    this->sprite.setPosition(x, y);
}

void Bullet::setOut()
{
    this->isOut = true;
}

SDL_Rect Bullet::getGlobalBounds()
{
    return this->sprite.getGlobalBounds();
}

void Bullet::draw() const
{
    this->data->window.draw(this->sprite);
}