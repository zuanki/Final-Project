#include <MenuState.hpp>
#include <GameState.hpp>
#include <defs.hpp>
MenuState::MenuState(GameDataRef data) : data(data) {
    
}
MenuState::~MenuState(){
    //
}
void MenuState::init(){
    this->text.loadFromRenderText("Press Space to continue !!!", GREEN_COLOR);
}
void MenuState::handleInput(){
    SDL_Event e;
    while(SDL_PollEvent(&e) != 0){
        if(e.type == SDL_QUIT){
            this->data->isRunning = false;
        }
        if (e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym)
            {
            case SDLK_SPACE:
                this->data->machine.addState(StateRef(std::make_unique<GameState>(this->data)));
                break;
            default:
                break;
            }
        }
    }
}
void MenuState::update(){
    //
}
void MenuState::draw(){
    this->text.render(100, 100);
}