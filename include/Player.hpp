#pragma once 
#include <Game.hpp>
#include <memory>
#include <Render/Sprite.hpp>
#include <Utility/Vector2.hpp>
#include <Render/View.hpp>
#include <Bullet.hpp>

enum class Direction {
    up,
    down, 
    right,
    left
};

class Player {
    private:    
        Sprite sprite_player;
        SDL_Rect player_clip;
        std::unique_ptr<Bullet> _bullet;
        GameDataRef data;
        View playerView;
        Direction dir;
        std::pair<int, int> pos;
        std::pair<int, int> coor_bullet;
        int moveSpeed;
        int hp = 3;
    public:
        Player(GameDataRef data);
        ~Player();
        void handleInput(SDL_Event e);
        void update();
        void draw();
        void setPosition(int u, int v);
        SDL_Rect getGlobalBounds() {
            return this->sprite_player.getGlobalBounds();
        }
        void takeHit(){
            --this->hp;
        }
        // return current hp
        int getHP() {
            return this->hp;
        }
};