#include <SDL.h>
#include <Render/RenderWindow.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    RenderWindow window("Test", 500, 500);
    SDL_Texture *bgTex = IMG_LoadTexture(window.getRenderer(), "../resource/images/art.jpg");
    Sprite bgSprite(bgTex);
    SDL_Texture *heroSheet = IMG_LoadTexture(window.getRenderer(), "../resource/images/hero.png");
    Sprite heroSprite;
    heroSprite.setTexture(heroSheet);
    heroSprite.setTextureRect({0, 0, 32, 48});
    View heroView(window.getDefaultView());
    int speed = 32;
    while (window.isOpen())
    {
        SDL_Event event;
        while (window.pollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                window.close();
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_W:
                    heroSprite.move(0, -speed);
                    break;

                case SDL_SCANCODE_S:
                    heroSprite.move(0, speed);
                    break;

                case SDL_SCANCODE_A:
                    heroSprite.move(-speed, 0);
                    break;

                case SDL_SCANCODE_D:
                    heroSprite.move(speed, 0);
                    break;

                default:
                    break;
                }
                break;

            default:
                break;
            }
        }
        window.clear();
        heroView.setCenter(heroSprite.getPosition());
        window.setView(heroView);
        window.draw(bgSprite);
        window.draw(heroSprite);
        window.display();
    }
    SDL_DestroyTexture(bgTex);
    SDL_Quit();
    return 0;
}