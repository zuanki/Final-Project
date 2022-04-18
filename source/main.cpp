#include <iostream>
#include <SDL.h>
#include "struct.hpp"



int main(int argc, char* argv[]){
    App newapp;
    newapp.window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
    newapp.renderer = SDL_CreateRenderer(newapp.window, -1, 1);
    SDL_SetRenderDrawColor(newapp.renderer, 200, 100, 100, 0);
    SDL_RenderDrawLine(newapp.renderer, 0,0,500,500);
    SDL_RenderPresent(newapp.renderer);
    SDL_Delay(5000);
    return 0;
}