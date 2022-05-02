#include <State.hpp>
#include <Game.hpp>
#include <Player.hpp>
#include <Map.hpp>
#include <Enemy.hpp>

class GameState : public State
{
public:
    GameState(GameDataRef data);
    void init() override;
    void handleInput() override;
    void update(float deltaTime) override;
    void draw() const override;

private:
    GameDataRef data;
    std::unique_ptr<Map> map;
    std::unique_ptr<Enemy> enemy;
};