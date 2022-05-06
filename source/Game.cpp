#include <Game.hpp>
#include <MenuState.hpp>

Game::Game(int width, int height, std::string title)
{
    this->data->window.create(title, width, height);
    this->data->assets.setRenderer(this->data->window.getRenderer());
    this->data->machine.addState(StateRef(std::make_unique<MenuState>(this->data)));
    this->run();
}
void Game::run()
{
    float lastTime, curTime, deltaTime;
    lastTime = SDL_GetTicks() / 1000.f;
    while (this->data->window.isOpen())
    {
        curTime = SDL_GetTicks() / 1000.f;
        deltaTime = curTime - lastTime;
        lastTime = curTime;
        this->data->machine.processStateChanges();
        this->data->machine.getActiveState()->handleInput();
        this->data->machine.getActiveState()->update(deltaTime);
        this->data->machine.getActiveState()->draw();
    }
}
Game::~Game()
{
    std::cout << "ShinoAki" << std::endl;
    SDL_Quit();
}