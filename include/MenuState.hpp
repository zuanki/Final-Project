#pragma once
#include <State.hpp>
#include <Game.hpp>
#include <Render/Text.hpp>
class MenuState : public State
{
public:
    MenuState(GameDataRef data);
    ~MenuState();
    void init() override;
    void handleInput() override;
    void update(float deltaTime) override;
    void draw() override;

private:
    GameDataRef data;
    Text newgame;
    Text easy;
    Text hard;
    Sprite menu_background;
};