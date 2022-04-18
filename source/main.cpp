#include <iostream>
#include <SDL.h>



int main(int argc, char* argv[]){
    SDL_Window* window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 1);
    SDL_SetRenderDrawColor(renderer, 200, 100, 100, 0);
    SDL_RenderDrawLine(renderer, 0,0,500,500);
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    return 0;
}