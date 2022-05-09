#pragma once
#include <Game.hpp>
#include <Animation.hpp>
class Bullet
{
    friend class BulletManager;

public:
    Bullet(GameDataRef data, const Vector2f &direction);
    void update(float deltaTime);
    void draw() const;
    SDL_Rect getGlobalBounds();
    void setPosition(float x, float y);
    void setOut();

private:
    GameDataRef data;
    Sprite sprite;
    Vector2f direction;
    float moveSpeed;
    bool isOut;
};