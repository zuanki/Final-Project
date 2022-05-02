#include <AssetManager.hpp>

void AssetManager::loadTexture(const std::string &name, const std::string &filePath)
{
    if (this->textures.find(name) != this->textures.end())
    {
        return;
    }

    SDL_Texture *newTexture = IMG_LoadTexture(this->renderer, filePath.c_str());
    this->textures[name] = newTexture;
}

void AssetManager::loadFont(const std::string &name, const std::string &filePath, int size)
{
    if (this->fonts.find(name) != this->fonts.end())
    {
        return;
    }
    TTF_Font *newFont = TTF_OpenFont(filePath.c_str(), size);
    this->fonts[name] = newFont;
}

SDL_Texture *AssetManager::getTexture(const std::string &name)
{
    return this->textures.at(name);
}
TTF_Font *AssetManager::getFont(const std::string &name)
{
    return this->fonts.at(name);
}
void AssetManager::loadMusic(const std::string &filePath)
{
    this->music = Mix_LoadMUS(filePath.c_str());
}
void AssetManager::loadChuck(const std::string &filePath)
{
    this->bullet = Mix_LoadWAV(filePath.c_str());
}
AssetManager::~AssetManager()
{
    std::map<std::string, SDL_Texture *>::iterator itr;
    for (itr = this->textures.begin(); itr != this->textures.end(); itr++)
    {
        SDL_DestroyTexture(itr->second);
        itr->second = NULL;
    }
    std::map<std::string, TTF_Font *>::iterator i;
    for (i = this->fonts.begin(); i != this->fonts.end(); i++)
    {
        TTF_CloseFont(i->second);
        i->second = NULL;
    }
    Mix_FreeMusic(this->music);
    this->music = NULL;
    Mix_FreeChunk(this->bullet);
    this->bullet = NULL;
    SDL_DestroyRenderer(this->renderer);
    this->renderer = NULL;
}