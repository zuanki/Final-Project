#include <Game.hpp>
#include <GameState.hpp>
Game::Game(int width, int height, std::string title){
    this->data->window.create(title, width, height);
    this->data->assets.setRenderer(this->data->window.getRenderer());
    this->data->machine.addState(StateRef(std::make_unique<GameState>(this->data)));
    this->run();
}
void Game::run(){
    while (this->data->window.isOpen())
    {
        this->data->machine.processStateChanges();
        this->data->machine.getActiveState()->handleInput();
        this->data->machine.getActiveState()->update();
        this->data->machine.getActiveState()->draw();
    }
}
Game::~Game(){
    std::cout<<"ShinoAki"<<std::endl;
    SDL_Quit();
}