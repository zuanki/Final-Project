#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Text
{
    friend class RenderWindow;

public:
    Text() {}
    ~Text() { SDL_DestroyTexture(this->texture); }
    void setRenderer(SDL_Renderer *renderer);
    void setFont(TTF_Font *font);
    void setColor(const SDL_Color &color);
    void setString(const std::string &str);
    void setPosition(int x, int y);

private:
    void remakeTexture();

private:
    TTF_Font *font = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    std::string str = "Default";
    SDL_Rect destRect = {0, 0, 0, 0};
    SDL_Color color = {0, 0, 0, 0};
};