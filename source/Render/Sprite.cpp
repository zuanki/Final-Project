#include <Render/Sprite.hpp>

Sprite::Sprite()
{
    this->texture = nullptr;
    this->textureRect = {0, 0, 0, 0};
    this->destRect = {0, 0, 0, 0};
}
Sprite::~Sprite(){
    SDL_DestroyTexture(this->texture);
}
Sprite::Sprite(SDL_Texture *texture)
{
    this->setTexture(texture);
    this->setPosition(0, 0);
}

Vector2i Sprite::getSize() const
{
    return {this->destRect.w, this->destRect.h};
}

Vector2i Sprite::getPosition() const
{
    return {this->destRect.x, this->destRect.y};
}

void Sprite::setPosition(int x, int y)
{
    this->destRect.x = x;
    this->destRect.y = y;
}

void Sprite::setPosition(const Vector2i &position)
{
    this->setPosition(position.x, position.y);
}

void Sprite::move(int offsetX, int offsetY)
{
    this->destRect.x += offsetX;
    this->destRect.y += offsetY;
}

void Sprite::move(const Vector2i &offset)
{
    this->move(offset.x, offset.y);
}

void Sprite::setTexture(SDL_Texture *texture)
{
    this->texture = texture;

    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    this->textureRect = {0, 0, w, h};
    this->destRect.w = w;
    this->destRect.h = h;
}

void Sprite::setTextureRect(const SDL_Rect &textureRect)
{
    this->textureRect = textureRect;
    this->destRect.w = this->textureRect.w;
    this->destRect.h = this->textureRect.h;
}