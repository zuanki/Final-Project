#include <TextObject.hpp>

TextObject::TextObject()
{
    this->color = {255, 255, 255};
    this->textSurface = TTF_RenderText_Solid(font, content.c_str(), color);
    this->textTexture = SDL_CreateTextureFromSurface(this->renderer, this->textSurface);
    this->text.setTexture(this->textTexture);
}