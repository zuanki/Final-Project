#include <WinState.hpp>
#include <MenuState.hpp>
#include <Defs.hpp>

WinState::WinState(GameDataRef data) : data(data)
{
    this->data->assets.loadTexture("menu_background", BACKGROUND_IMAGE_PATH);
    this->data->assets.loadFont("Font35", FONT_PATH, 35);
    this->data->assets.loadFont("Font40", FONT_PATH, 40);

    this->wingame.setRenderer(this->data->window.getRenderer());
    this->wingame.setFont(this->data->assets.getFont("Font40"));
    this->wingame.setColor({3, 252, 177, 0});
    this->wingame.setString("YEAH YOU ARE WINNER !!!");
    this->wingame.setPosition(150, 100);

    this->play_again.setRenderer(this->data->window.getRenderer());
    this->play_again.setFont(this->data->assets.getFont("Font35"));
    this->play_again.setColor({3, 252, 177, 0});
    this->play_again.setString("BACK TO MENU ? [Y] or [N]");
    this->play_again.setPosition(150, 250);

    this->menu_background.setTexture(this->data->assets.getTexture("menu_background"));
    this->menu_background.setTextureRect({0, 0, 640, 480});
    this->menu_background.setPosition(0, 0);
}
WinState::~WinState()
{
    //
}
void WinState::init()
{
    this->data->window.setView(this->data->window.getDefaultView());
}
void WinState::handleInput()
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
            case SDL_SCANCODE_Y:
                this->data->machine.addState(StateRef(std::make_unique<MenuState>(this->data)));
                break;
            case SDL_SCANCODE_N:
                this->data->window.close();
                break;
            default:
                break;
            }
        }
    }
}
void WinState::update(float deltaTime)
{
    //
}
void WinState::draw()
{
    this->data->window.clear();
    this->data->window.draw(this->menu_background);
    this->data->window.draw(this->wingame);
    this->data->window.draw(this->play_again);
    this->data->window.display();
}