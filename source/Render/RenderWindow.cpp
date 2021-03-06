#include <Render/RenderWindow.hpp>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

RenderWindow::RenderWindow()
{
    this->open = true;
    this->view = this->getDefaultView();
}
void RenderWindow::create(const std::string &title, int width, int height)
{
    this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    this->size.x = width;
    this->size.y = height;
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (TTF_Init() == -1)
    {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n"
                  << TTF_GetError() << std::endl;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
}
RenderWindow::~RenderWindow()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    TTF_Quit();
    Mix_Quit();
}

bool RenderWindow::isOpen() const
{
    return this->open;
}

Vector2i RenderWindow::getSize() const
{
    return this->size;
}

SDL_Renderer *RenderWindow::getRenderer() const
{
    return this->renderer;
}

bool RenderWindow::pollEvent(SDL_Event *event)
{
    return SDL_PollEvent(event);
}

void RenderWindow::close()
{
    this->open = false;
}

void RenderWindow::clear()
{
    SDL_RenderClear(this->renderer);
}

void RenderWindow::draw(const Sprite &sprite)
{
    SDL_Rect actualRect = sprite.destRect;
    actualRect.x -= this->view.position.x;
    actualRect.y -= this->view.position.y;
    SDL_RenderCopy(this->renderer, sprite.texture, &sprite.textureRect, &actualRect);
}

void RenderWindow::display()
{
    SDL_RenderPresent(this->renderer);
}

void RenderWindow::setView(const View &view)
{
    this->view = view;
}

View RenderWindow::getView() const
{
    return this->view;
}

View RenderWindow::getDefaultView() const
{
    return View({0, 0}, this->size);
}
void RenderWindow::draw(Text &text)
{
    SDL_Rect actualRect = text.destRect;
    actualRect.x -= 0; // this->view.position.x;
    actualRect.y -= 0; // this->view.position.y;
    SDL_RenderCopy(this->renderer, text.texture, NULL, &actualRect);
}