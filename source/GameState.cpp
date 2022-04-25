#include <GameState.hpp>
#include <defs.hpp>

GameState::GameState(GameDataRef data) : data(data) {
    
}
GameState::~GameState(){
    //
}
void GameState::init(){
    bool x = m.loadMap();
    if (x){
        std::cout<<"Can't load map"<<std::endl;
    }
}
void GameState::handleInput(){
    SDL_Event e;
    while (SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT){
            this->data->isRunning = false;
        }
        else {
            m.handleEvent(e);
        }
    }
}
void GameState::update(){
    m.update();
}
void GameState::draw(){
    m.draw();
}