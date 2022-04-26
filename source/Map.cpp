#include <Map.hpp>
#include <Defs.hpp>
Map::Map(GameDataRef data) : data(data){
    this->mapTexture= IMG_LoadTexture(this->data->window.getRenderer(), MAP_IMAGE_PATH);
    if (this->mapTexture == NULL){
        this->data->window.close();
    }
    this->sprite_map.setTexture(this->mapTexture);
    this->sprite_map.setTextureRect({0, 0, 500, 500});
}
Map::~Map(){
    SDL_DestroyTexture(this->mapTexture);
}
void Map::draw(){
    this->data->window.draw(this->sprite_map);
}