#pragma once 
#include <State.hpp>
#include <Game.hpp>
#include <Map.hpp>
class GameState : public State {
    private:
        Map m;
        GameDataRef data;
    public:
        GameState(GameDataRef data);
        ~GameState();
        void init() override;
        void handleInput() override;
        void update() override;
        void draw() override;
};