#include <GameState.hpp>

GameState::GameState(GameDataRef data) : data(data) {
    
}
void GameState::init(){
    this->player = std::make_unique<Player>(this->data);
    this->map = std::make_unique<Map>(this->data);
}
void GameState::handleInput(){
    SDL_Event e;
    while (this->data->window.pollEvent(&e))
    {
        if (e.type == SDL_QUIT){
            this->data->window.close();
        }
        else {
            this->player->handleInput(e);
        }
    }
    
}
void GameState::update(){
    this->player->update();
}
void GameState::draw() const {
    this->data->window.clear();
    this->map->draw();
    this->player->draw();
    this->data->window.display();
}