#include <MenuState.hpp>
#include <GameState.hpp>
#include <defs.hpp>
MenuState::MenuState(GameDataRef data) : data(data) {
    this->background_clip.x = 0;
    this->background_clip.y = 0;
    this->background_clip.w = 500;
    this->background_clip.h = 400;
}
MenuState::~MenuState(){
    //
}
void MenuState::init(){
    bool x = background.loadFromFile(BACKGROUND_IMAGE_PATH);
    if (x == false){
        std::cout<<"Can't load background"<<std::endl;
        this->data->isRunning = false;
    }
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
    this->background.render(0,0, &this->background_clip);
}