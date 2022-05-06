#include <MenuState.hpp>
#include <GameState.hpp>
#include <Defs.hpp>

MenuState::MenuState(GameDataRef data) : data(data)
{
    this->data->assets.loadTexture("menu_background", BACKGROUND_IMAGE_PATH);
    this->data->assets.loadFont("Font35", FONT_PATH, 35);
    this->data->assets.loadFont("Font40", FONT_PATH, 40);

    this->newgame.setRenderer(this->data->window.getRenderer());
    this->newgame.setFont(this->data->assets.getFont("Font40"));
    this->newgame.setColor({3, 252, 177, 0});
    this->newgame.setString("PRESS ESC TO ESCAPE !!!");
    this->newgame.setPosition(150, 50);

    this->easy.setRenderer(this->data->window.getRenderer());
    this->easy.setFont(this->data->assets.getFont("Font35"));
    this->easy.setColor({3, 252, 177, 0});
    this->easy.setString("KEY 1 : EASY");
    this->easy.setPosition(250, 200);

    this->hard.setRenderer(this->data->window.getRenderer());
    this->hard.setFont(this->data->assets.getFont("Font35"));
    this->hard.setColor({3, 252, 177, 0});
    this->hard.setString("KEY 2 : HARD");
    this->hard.setPosition(250, 250);

    this->menu_background.setTexture(this->data->assets.getTexture("menu_background"));
    this->menu_background.setTextureRect({0, 0, 640, 480});
    this->menu_background.setPosition(0, 0);
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
    this->data->window.draw(this->menu_background);
    this->data->window.draw(this->newgame);
    this->data->window.draw(this->easy);
    this->data->window.draw(this->hard);
    this->data->window.display();
}