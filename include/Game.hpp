#pragma once
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <StateMachine.hpp>
#include <SDL_ttf.h>
class GameData {
    public:
        StateMachine machine;
        bool isRunning = true;
};

using GameDataRef = std::shared_ptr<GameData>;

class Game {
    private:
        SDL_Window* window = NULL;
        GameDataRef data = std::make_shared<GameData>();
        void run();
    public:
        Game(int width, int height, std::string title);
        ~Game();
        static SDL_Renderer* renderer;
        static TTF_Font* font;
};