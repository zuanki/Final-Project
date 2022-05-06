#include <State.hpp>
#include <Game.hpp>
#include <Player.hpp>
#include <Map.hpp>

class GameState : public State
{
public:
    GameState(GameDataRef data, int level = 1);
    void init() override;
    void handleInput() override;
    void update(float deltaTime) override;
    void draw() override;

private:
    GameDataRef data;
    std::unique_ptr<Map> map;
    int level;
};