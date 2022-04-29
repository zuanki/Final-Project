#pragma once
#include <StateMachine.hpp>
#include <Render/RenderWindow.hpp>
#include <iostream>
#include <AssetManager.hpp>

class GameData
{
public:
    StateMachine machine;
    RenderWindow window;
    AssetManager assets;
};

using GameDataRef = std::shared_ptr<GameData>;

class Game
{
public:
    Game(int width, int height, std::string title);
    ~Game();

private:
    GameDataRef data = std::make_shared<GameData>();
    void run();
};