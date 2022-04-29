#pragma once
#include <Game.hpp>
#include <Animation.hpp>

class Enemy
{
private:
    Sprite sprite;
    GameDataRef data;
    std::unique_ptr<Animation> animation;
    int k = 1;

public:
    Enemy(GameDataRef data);
    ~Enemy();
    void moveRandom();
    void update(float deltaTime);
    void draw();
};