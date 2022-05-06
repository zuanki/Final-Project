#pragma once
#include <Game.hpp>
#include <Animation.hpp>

class Enemy
{
private:
    Sprite sprite;
    GameDataRef data;
    std::unique_ptr<Animation> animation;
    bool isDeath;

public:
    Enemy(GameDataRef data);
    ~Enemy();
    void moveRandom();
    void setDeath(bool x)
    {
        isDeath = x;
    }
    void update(float deltaTime);
    void draw();
    SDL_Rect getGlobalBounds()
    {
        return this->sprite.getGlobalBounds();
    }
};