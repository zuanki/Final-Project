#ifndef Game_h
#define Game_h
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Game{
private:
    int cnt =0;
    bool isRunning = true;
    SDL_Window* gWindow = NULL;

public:
    Game();
    ~Game();
    bool init();
    bool loadMedia();
    void handleEvents();
    void update();
    void render();
    void close();

    bool getGameState(){ return isRunning; }

    static SDL_Renderer* gRenderer;

    //static TTF_Font* gFont;
};

#endif