#pragma once
#include <Game.hpp>
#include <memory>
#include <Render/Sprite.hpp>
#include <Utility/Vector2.hpp>
#include <Render/View.hpp>
#include <Bullet.hpp>
#include <Direction.hpp>
#include <BulletManager.hpp>

class Player
{
private:
    Sprite sprite_player;
    SDL_Rect player_clip;
    GameDataRef data;
    Vector2f direction;
    std::unique_ptr<BulletManager> _bullets;
    View playerView;
    Direction dir;
    std::pair<float, float> pos;
    std::pair<float, float> velocity;
    float shootingTimer;
    int moveSpeed;
    int hp = 20;
    Text hp_text;

public:
    Player(GameDataRef data);
    ~Player();
    void handleInput(SDL_Event e);
    void update(float deltaTime);
    void draw();
    void setPosition(int u, int v);
    void setVelocity(float u, float v)
    {
        velocity = std::make_pair(u, v);
    }
    SDL_Rect getGlobalBounds()
    {
        return this->sprite_player.getGlobalBounds();
    }
    void takeHit()
    {
        --this->hp;
    }
    // return current hp
    int getHP()
    {
        return this->hp;
    }
    void shoot();
    Direction getDirection()
    {
        return dir;
    }
};