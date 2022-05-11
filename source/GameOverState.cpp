#include <GameOverState.hpp>
#include <MenuState.hpp>
#include <Defs.hpp>

GameOverState::GameOverState(GameDataRef data) : data(data)
{
    this->data->assets.loadTexture("menu_background", BACKGROUND_IMAGE_PATH);
    this->data->assets.loadFont("Font16", FONT_PATH, 16);
    this->data->assets.loadFont("Font20", FONT_PATH, 20);

    this->menu_background.setTexture(this->data->assets.getTexture("menu_background"));
    this->menu_background.setTextureRect({0, 0, 640, 480});
    this->menu_background.setPosition(0, 0);

    this->game_over.setRenderer(this->data->window.getRenderer());
    this->game_over.setFont(this->data->assets.getFont("Font20"));
    this->game_over.setColor({3, 252, 177, 0});
    this->game_over.setString("GAMEOVER !!!");
    this->game_over.setPosition(250, 100);

    this->play_again.setRenderer(this->data->window.getRenderer());
    this->play_again.setFont(this->data->assets.getFont("Font16"));
    this->play_again.setColor({3, 252, 177, 0});
    this->play_again.setString("BACK TO MENU ? [Y] or [N]");
    this->play_again.setPosition(200, 250);
}
GameOverState::~GameOverState()
{
    //
}
void GameOverState::init()
{
    this->data->window.setView(this->data->window.getDefaultView());
}
void GameOverState::handleInput()
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
void GameOverState::update(float deltaTime)
{
    //
}
void GameOverState::draw()
{
    this->data->window.clear();
    this->data->window.draw(this->menu_background);
    this->data->window.draw(this->game_over);
    this->data->window.draw(this->play_again);
    this->data->window.display();
}