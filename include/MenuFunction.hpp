#pragma once
#include <Render/Text.hpp>
#include <Game.hpp>
class MenuFunction
{
private:
    Text newgame;
    GameDataRef data;

public:
    MenuFunction(GameDataRef data);
    ~MenuFunction();
    void init();
    void handleInput(SDL_Event e);
    void update(float delatTime);
    void draw();
};