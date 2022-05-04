#include <MenuState.hpp>
#include <GameState.hpp>
#include <Defs.hpp>

MenuState::MenuState(GameDataRef data) : data(data)
{
    this->data->assets.loadFont("Font24", FONT_PATH, 24);
    this->data->assets.loadFont("Font40", FONT_PATH, 40);
    this->mf = std::make_unique<MenuFunction>(this->data);
}
MenuState::~MenuState()
{
    //
}
void MenuState::init()
{
}
void MenuState::handleInput()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            this->data->window.close();
        }
        if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.scancode)
            {
            case SDL_SCANCODE_SPACE:
                this->data->machine.addState(StateRef(std::make_unique<GameState>(this->data)));
                break;
            default:
                break;
            }
        }
    }
}
void MenuState::update(float deltaTime)
{
    //
}
void MenuState::draw() const
{
    // this->data->window.draw(this->newgame);
    this->mf->draw();
}