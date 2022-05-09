#include <WinState.hpp>
#include <MenuState.hpp>
#include <Defs.hpp>

WinState::WinState(GameDataRef data) : data(data)
{
    this->data->assets.loadTexture("menu_background", BACKGROUND_IMAGE_PATH);
    this->data->assets.loadFont("Font16", FONT_PATH, 16);
    this->data->assets.loadFont("Font20", FONT_PATH, 20);

    this->wingame.setRenderer(this->data->window.getRenderer());
    this->wingame.setFont(this->data->assets.getFont("Font20"));
    this->wingame.setColor({3, 252, 177, 0});
    this->wingame.setString("VICTORY !!!");
    this->wingame.setPosition(250, 100);

    this->play_again.setRenderer(this->data->window.getRenderer());
    this->play_again.setFont(this->data->assets.getFont("Font16"));
    this->play_again.setColor({3, 252, 177, 0});
    this->play_again.setString("BACK TO MENU ? [Y] or [N]");
    this->play_again.setPosition(200, 250);

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