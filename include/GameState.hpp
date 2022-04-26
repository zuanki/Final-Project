#include <State.hpp>
#include <Game.hpp>
#include <Player.hpp>
#include <Map.hpp>
class GameState: public State {
    public:
        GameState(GameDataRef data);
        void init() override;
        void handleInput() override;
        void update() override;
        void draw() const override;
    private:
        GameDataRef data;
        std::unique_ptr<Player> player;
        std::unique_ptr<Map> map;
};