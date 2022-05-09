#include <GameState.hpp>
#include <Defs.hpp>
GameState::GameState(GameDataRef data, int level) : data(data), level(level)
{
}
void GameState::init()
{
    this->data->assets.loadTexture("player", PLAYER_IMAGE_PATH);
    this->data->assets.loadTexture("path_tile", MAP_PATH_IMAGE_PATH);
    this->data->assets.loadTexture("wall_tile", MAP_WALL_IMAGE_PATH);
    this->data->assets.loadTexture("tree_tile", MAP_TREE_IMAGE_PATH);
    this->data->assets.loadTexture("water_tile", MAP_WATER_IMAGE_PATH);
    this->data->assets.loadTexture("gate_tile", MAP_GATE_IMAGE_PATH);
    this->data->assets.loadTexture("bullet_fire", BULLET_IMAGE_PATH);
    this->data->assets.loadTexture("mantis_enemy", MANTIS_IMAGE_PATH);
    this->data->assets.loadTexture("beetle_enemy", BEETLE_IMAGE_PATH);
    this->data->assets.loadFont("Font16", FONT_PATH, 16);
    this->data->assets.loadFont("Font20", FONT_PATH, 20);
    this->data->assets.loadMusic(MUSIC_PATH);
    this->data->assets.loadChuck(CHUCK_PATH);
    this->map = std::make_unique<Map>(this->data, this->level);
    this->map->init();
}
void GameState::handleInput()
{
    SDL_Event e;
    while (this->data->window.pollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            this->data->window.close();
        }
        else
        {
            this->map->handleInput(e);
        }
    }
}
void GameState::update(float deltaTime)
{
    this->map->update(deltaTime);
}
void GameState::draw()
{
    this->data->window.clear();
    this->map->draw();
    this->data->window.display();
}