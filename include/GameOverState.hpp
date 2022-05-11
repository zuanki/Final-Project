#pragma once
#include <State.hpp>
#include <Game.hpp>
#include <Render/Text.hpp>
class GameOverState : public State
{
public:
    GameOverState(GameDataRef data);
    ~GameOverState();
    void init() override;
    void handleInput() override;
    void update(float deltaTime) override;
    void draw() override;

private:
    GameDataRef data;
    Text game_over;
    Text play_again;
    Sprite menu_background;
};