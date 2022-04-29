#include <GameState.hpp>
#include <Defs.hpp>
GameState::GameState(GameDataRef data) : data(data)
{
}
void GameState::init()
{
    this->data->assets.loadTexture("player", PLAYER_IMAGE_PATH);
    this->data->assets.loadTexture("path_tile", MAP_PATH_IMAGE_PATH);
    this->data->assets.loadTexture("wall_tile", MAP_WALL_IMAGE_PATH);
    this->data->assets.loadTexture("tree_tile", MAP_TREE_IMAGE_PATH);
    this->data->assets.loadTexture("water_tile", MAP_WATER_IMAGE_PATH);
    this->data->assets.loadTexture("bullet_fire", BULLET_IMAGE_PATH);
    this->data->assets.loadTexture("mantis_enemy", MANTIS_IMAGE_PATH);
    this->map = std::make_unique<Map>(this->data);
    this->enemy = std::make_unique<Enemy>(this->data);
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
    this->enemy->update(deltaTime);
    this->map->update(deltaTime);
}
void GameState::draw() const
{
    this->data->window.clear();
    this->map->draw();
    this->enemy->draw();
    this->data->window.display();
}