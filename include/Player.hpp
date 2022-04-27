#pragma once 
#include <Game.hpp>
#include <Render/Sprite.hpp>
#include <Utility/Vector2.hpp>
#include <Render/View.hpp>
class Player {
    private:    
        Sprite sprite_player;
        SDL_Rect player_clip;
        GameDataRef data;
        View playerView;
        int moveSpeed;
        Vector2i direction;
    public:
        Player(GameDataRef data);
        ~Player();
        void handleInput(SDL_Event e);
        void update();
        void draw();
        void setPosition(int u, int v);
};