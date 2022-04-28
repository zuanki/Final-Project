#include <Map.hpp>
#include <Defs.hpp>
#include <fstream>
Map::Map(GameDataRef data) : data(data){
    std::ifstream readmap(MAP_TXT_PATH);
    if (readmap.is_open()){
        std::string x;
        while (getline(readmap, x))
        {
            this->map_text.push_back(x);
        }
        readmap.close();
    }
    for (int i=0;i<this->map_text.size();i++){
        for (int j=0;j<this->map_text[i].size();j++){
            if (this->map_text[i][j] == '#'){
                auto k = std::make_unique<Tile>(this->data);
                k->setTexture(this->data->assets.getTexture("path_tile"));
                k->setPosition(32*j, 32*i);
                this->map.push_back(std::move(k));
            }
            else if (this->map_text[i][j] == '@'){
                auto k = std::make_unique<Tile>(this->data);
                k->setTexture(this->data->assets.getTexture("wall_tile"));
                k->setPosition(32*j, 32*i);
                this->map.push_back(std::move(k));
            }
            else if (this->map_text[i][j] == '!'){
                auto k = std::make_unique<Tile>(this->data);
                k->setTexture(this->data->assets.getTexture("tree_tile"));
                k->setPosition(32*j, 32*i);
                this->map.push_back(std::move(k));
            }
            else if (this->map_text[i][j] == '$'){
                auto k = std::make_unique<Tile>(this->data);
                k->setTexture(this->data->assets.getTexture("water_tile"));
                k->setPosition(32*j, 32*i);
                this->map.push_back(std::move(k));
            }
        }
    }
}
Map::~Map(){
    
}
void Map::init(){
    //
}
void Map::draw(){
    for (int i=0;i<this->map.size();i++){
        map[i]->draw();
    }
}