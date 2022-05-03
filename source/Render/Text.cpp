#include <Render/Text.hpp>
#include <iostream>

void Text::setFont(TTF_Font *font)
{
    this->font = font;
}

void Text::setRenderer(SDL_Renderer *renderer)
{
    this->renderer = renderer;
}

void Text::setString(const std::string &str)
{
    this->str = str;
    this->remakeTexture();
}

void Text::setColor(const SDL_Color &color)
{
    this->color = color;
    this->remakeTexture();
}

void Text::setPosition(int x, int y)
{
    this->destRect.x = x;
    this->destRect.y = y;
}

void Text::remakeTexture()
{
    SDL_Surface *text_surf = TTF_RenderText_Solid(this->font, this->str.c_str(), this->color);
    this->texture = SDL_CreateTextureFromSurface(this->renderer, text_surf);

    this->destRect.w = text_surf->w;
    this->destRect.h = text_surf->h;

    SDL_FreeSurface(text_surf);
}