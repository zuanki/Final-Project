#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Utility/Vector2.hpp>

class Sprite
{
        friend class RenderWindow;
    public:
        Sprite();
        ~Sprite();
        Sprite(SDL_Texture* texture);
        Vector2i getSize() const;
        Vector2i getPosition() const;
        void setPosition(int x, int y);
        void setPosition(const Vector2i& position);
        void move(int offsetX, int offsetY);
        void move(const Vector2i& offset);
        void setTexture(SDL_Texture* texture);
        void setTextureRect(const SDL_Rect& textureRect);
        SDL_Rect getGlobalBounds(){
            return destRect;
        }
    private:
        SDL_Texture* texture;
        SDL_Rect textureRect;
        SDL_Rect destRect;
};