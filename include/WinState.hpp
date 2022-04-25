#pragma once
#include <State.hpp>
#include <Game.hpp>
#include <Texture.hpp>
class WinState : public State
{
    public:
        WinState(GameDataRef data);
        ~WinState();
        void init() override;
        void handleInput() override;
        void update() override;
        void draw() override;

    private:
        GameDataRef data;
        LTexture text;
};