#pragma once

#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
class AssetManager
{
public:
    AssetManager() = default;
    ~AssetManager();
    void setRenderer(SDL_Renderer *render)
    {
        renderer = render;
    }
    void loadTexture(const std::string &name, const std::string &filePath);
    SDL_Texture *getTexture(const std::string &name);
    void loadFont(const std::string &name, const std::string &filePath, int size);
    TTF_Font *getFont(const std::string &name);
    void loadMusic(const std::string &filePath);
    Mix_Music *getMusic()
    {
        return this->music;
    }
    void loadChuck(const std::string &filePath);
    Mix_Chunk *getChuck()
    {
        return this->bullet;
    }

private:
    std::map<std::string, SDL_Texture *> textures;
    std::map<std::string, TTF_Font *> fonts;
    Mix_Music *music;
    Mix_Chunk *bullet;
    SDL_Renderer *renderer;
};