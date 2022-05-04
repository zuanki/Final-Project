#include <MenuFunction.hpp>

MenuFunction::MenuFunction(GameDataRef data) : data(data)
{
    this->newgame.setRenderer(this->data->window.getRenderer());
    this->newgame.setFont(this->data->assets.getFont("Font40"));
    this->newgame.setColor({255, 255, 0, 0});
    this->newgame.setString("Hello");
    this->newgame.setPosition(0, 0);
}
MenuFunction::~MenuFunction()
{
    //
}
void MenuFunction::init()
{
}
void MenuFunction::handleInput(SDL_Event e)
{
}
void MenuFunction::update(float deltaTime)
{
}
void MenuFunction::draw()
{
    this->data->window.draw(this->newgame);
}