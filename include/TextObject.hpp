#pragma once
#include <Render/Sprite.hpp>
#include <SDL_ttf.h>
#include <iostream>
class TextObject
{
private:
    Sprite text;
    SDL_Texture *textTexture;
    SDL_Surface *textSurface;
    SDL_Renderer *renderer;
    std::string content;
    SDL_Color color;
    TTF_Font *font;

public:
    TextObject();
    ~TextObject()
    {
        SDL_DestroyTexture(this->textTexture);
        SDL_FreeSurface(this->textSurface);
        TTF_CloseFont(this->font);
        SDL_DestroyRenderer(this->renderer);
    }
    Sprite getSprite()
    {
        return this->text;
    }
    void setContent(std::string in, TTF_Font *font, SDL_Renderer *render)
    {
        this->content = in;
        this->font = font;
        this->renderer = render;
    }
    void setColor(SDL_Color color)
    {
        this->color = color;
    }
    void setRect(SDL_Rect re)
    {
        this->text.setTextureRect(re);
    }
    void setPosition(int u, int v)
    {
        this->text.setPosition(u, v);
    }
};