#pragma once
#include <Game.hpp>
#include <Animation.hpp>

class Enemy
{
    friend class EnemyManager;

protected:
    Sprite sprite;
    GameDataRef data;
    std::unique_ptr<Animation> animation;
    bool isDeath;
    int hp = 10;

public:
    Enemy(GameDataRef data);
    ~Enemy();
    void moveRandom();
    void setDeath(bool x)
    {
        isDeath = x;
    }
    void setPosition(float x, float y)
    {
        this->sprite.setPosition(x, y);
    }
    void setTexture(SDL_Texture *texture)
    {
        this->sprite.setTexture(texture);
    }
    void update(float deltaTime);
    void draw();
    void takeHit()
    {
        this->hp--;
    }
    int getHp()
    {
        return this->hp;
    }
    SDL_Rect getGlobalBounds()
    {
        return this->sprite.getGlobalBounds();
    }
};