#pragma once
#include <State.hpp>
#include <Game.hpp>
#include <Render/Text.hpp>
#include <MenuFunction.hpp>
class MenuState : public State
{
public:
    MenuState(GameDataRef data);
    ~MenuState();
    void init() override;
    void handleInput() override;
    void update(float deltaTime) override;
    void draw() const override;

private:
    GameDataRef data;
    std::unique_ptr<MenuFunction> mf;
};