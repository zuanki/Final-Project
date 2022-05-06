#pragma once
#include <State.hpp>
#include <Game.hpp>
#include <Render/Text.hpp>
class WinState : public State
{
public:
    WinState(GameDataRef data);
    ~WinState();
    void init() override;
    void handleInput() override;
    void update(float deltaTime) override;
    void draw() override;

private:
    GameDataRef data;
    Text wingame;
    Text play_again;
    Sprite menu_background;
};