#include <Map.hpp>
#include <Defs.hpp>
#include <fstream>
Map::Map(GameDataRef data) : data(data){
    this->mapTexture = IMG_LoadTexture(this->data->window.getRenderer(), MAP_IMAGE_PATH);
    this->map_sprite.setTexture(this->mapTexture);
    this->map_sprite.setTextureRect({0, 0, 500, 500});
}
Map::~Map(){
    SDL_DestroyTexture(this->mapTexture);
}
// void Map::init(){
//     std::ifstream readmap(MAP_TXT_PATH);
//     if (readmap.is_open()){
//         std::string x;
//         while (getline(readmap, x))
//         {
//             this->map_text.push_back(x);
//         }
//         readmap.close();
//     }
// }
void Map::draw(){
    this->data->window.draw(this->map_sprite);
}