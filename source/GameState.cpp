#include <GameState.hpp>
#include <Defs.hpp>
GameState::GameState(GameDataRef data) : data(data) {
    
}
void GameState::init(){
    this->data->assets.loadTexture("player", PLAYER_IMAGE_PATH);
    this->data->assets.loadTexture("path_tile", MAP_PATH_IMAGE_PATH);
    this->data->assets.loadTexture("wall_tile", MAP_WALL_IMAGE_PATH);
    this->data->assets.loadTexture("tree_tile", MAP_TREE_IMAGE_PATH);
    this->data->assets.loadTexture("water_tile", MAP_WATER_IMAGE_PATH);
    this->data->assets.loadTexture("bullet_fire", BULLET_IMAGE_PATH);
    this->player = std::make_unique<Player>(this->data);
    this->map = std::make_unique<Map>(this->data);
    this->map->init();
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