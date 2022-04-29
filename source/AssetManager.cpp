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

SDL_Texture *AssetManager::getTexture(const std::string &name)
{
    return this->textures.at(name);
}
AssetManager::~AssetManager()
{
    std::map<std::string, SDL_Texture *>::iterator itr;
    for (itr = this->textures.begin(); itr != this->textures.end(); itr++)
    {
        SDL_DestroyTexture(itr->second);
        itr->second = NULL;
    }
    SDL_DestroyRenderer(this->renderer);
    this->renderer = NULL;
}