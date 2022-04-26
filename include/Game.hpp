#pragma once 
#include <StateMachine.hpp>
#include <Render/RenderWindow.hpp>
#include <iostream>

struct GameData
{
    StateMachine machine;
    RenderWindow window;
};

using GameDataRef = std::shared_ptr<GameData>;

class Game {
    public:
        Game(int width, int height, std::string title);
        ~Game();
    private:
        GameDataRef data = std::make_shared<GameData>();
        void run();
};