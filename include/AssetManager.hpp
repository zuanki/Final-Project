#pragma once

#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class AssetManager {
    public:
        AssetManager() = default;
        ~AssetManager();
        void setRenderer(SDL_Renderer* render){
            renderer = render;
        }
        void loadTexture(const std::string& name, const std::string& filePath);
        SDL_Texture* getTexture(const std::string& name);

    private:
        std::map<std::string, SDL_Texture*> textures;
        SDL_Renderer* renderer;
};