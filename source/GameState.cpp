#include <GameState.hpp>
#include <defs.hpp>
#include <WinState.hpp>
GameState::GameState(GameDataRef data) : data(data) {
    
}
GameState::~GameState(){
    //
}
void GameState::init(){
    bool x = m.loadMap();
}
void GameState::handleInput(){
    SDL_Event e;
    while (SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT){
            this->data->isRunning = false;
        }
        if (e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym)
            {
            case SDLK_n:
                this->data->machine.addState(StateRef(std::make_unique<WinState>(this->data)));
                break;
            
            default:
                break;
            }
        }
        m.handleEvent(e);
    }
}
void GameState::update(){
    m.update();
}
void GameState::draw(){
    m.draw();
}