#include <WinState.hpp>
#include <GameState.hpp>
#include <defs.hpp>
WinState::WinState(GameDataRef data) : data(data) {
    
}
WinState::~WinState(){
    //
}
void WinState::init(){
    this->text.loadFromRenderText("Yeah you are winner !!!", RED_COLOR);
}
void WinState::handleInput(){
    SDL_Event e;
    while(SDL_PollEvent(&e) != 0){
        if(e.type == SDL_QUIT){
            this->data->isRunning = false;
        }
        if (e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym)
            {
            case SDLK_y:
                this->data->machine.addState(StateRef(std::make_unique<GameState>(this->data)));
                break;
            default:
                break;
            }
        }
    }
}
void WinState::update(){
    //
}
void WinState::draw(){
    this->text.render(100, 100);
}