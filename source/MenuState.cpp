#include <MenuState.hpp>
#include <GameState.hpp>
#include <Defs.hpp>

MenuState::MenuState(GameDataRef data) : data(data)
{
    this->data->assets.loadFont("Font24", FONT_PATH, 24);
    this->data->assets.loadFont("Font40", FONT_PATH, 40);
    this->newgame.setRenderer(this->data->window.getRenderer());
    this->newgame.setFont(this->data->assets.getFont("Font40"));
    this->newgame.setColor({255, 0, 0, 0});
    this->newgame.setString("Hello");
    this->newgame.setPosition(100, 100);
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
            case SDL_SCANCODE_0:
                this->data->machine.addState(StateRef(std::make_unique<GameState>(this->data, 0)));
                break;
            case SDL_SCANCODE_1:
                this->data->machine.addState(StateRef(std::make_unique<GameState>(this->data, 1)));
                break;
            case SDL_SCANCODE_2:
                this->data->machine.addState(StateRef(std::make_unique<GameState>(this->data, 2)));
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
void MenuState::draw()
{
    this->data->window.clear();
    this->data->window.draw(this->newgame);
    this->data->window.display();
}