
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Utility/Vector2.hpp>
#include <string>
#include <Render/Sprite.hpp>
#include <Render/View.hpp>

class RenderWindow
{
    public:
        RenderWindow(const std::string& title, int width, int height);
        ~RenderWindow();
        bool isOpen() const;
        Vector2i getSize() const;
        SDL_Renderer* getRenderer() const;
        bool pollEvent(SDL_Event* event);
        void clear();
        void draw(const Sprite& sprite);
        void display();
        void close();
        void setView(const View& view);
        View getView() const;
        View getDefaultView() const;
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool open;
        Vector2i size;
        View view;
};