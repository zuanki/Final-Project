#pragma once
#include <State.hpp>
#include <Game.hpp>
#include <Texture.hpp>
class MenuState : public State
{
    public:
        MenuState(GameDataRef data);
        ~MenuState();
        void init() override;
        void handleInput() override;
        void update() override;
        void draw() override;

    private:
        GameDataRef data;
        LTexture text;
};