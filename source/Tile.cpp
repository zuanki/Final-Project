#include <Tile.hpp>

Tile::Tile(GameDataRef data) : data(data){
    this->p.setPosition(0, 0);
}
Tile::~Tile(){
    //
}

void Tile::setTexture(SDL_Texture* tex){
    this->p.setTexture(tex);
}

void Tile::draw(){
    this->data->window.draw(this->p);
}