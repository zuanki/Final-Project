#include <Map.hpp>

Map::Map(){
    //
}
Map::~Map(){
    //
}
bool Map::loadMap(){
    bool success = true;
    if (!this->grass.loadFromFile(GRASS_IMAGE_PATH)){
        success = false;
    }
    if (!this->wall.loadFromFile(WALL_IMAGE_PATH)){
        success = false;
    }
    if (!this->tree.loadFromFile(TREE_IMAGE_PATH)){
        success = false;
    }
    if (!this->fountain.loadFromFile(FOUNTAIN_IMAGE_PATH)){
        success = false;
    }
    std::ifstream readmap(MAP_TEX_PATH);
    if(readmap.is_open())
    {
        std::string x;
        while(getline(readmap, x))
        {
            this->map.push_back(x);
        }
        readmap.close();
    }
    else
    {
        std::cout<<"Can't load file"<<std::endl;
        success = false;
    }
    return success;
}
void Map::update(){
    //
}
void Map::draw(){
    SDL_Rect _clip;
    _clip.x = _clip.y = 0;
    _clip.w = _clip.h = SIZE_SMALL;
    for (int i=0;i<map.size();i++){
        for (int j=0;j<map[i].size();j++){
            switch (map[i][j])
            {
            case '#':
                this->grass.render(SIZE_SMALL*j, SIZE_SMALL*i, &_clip);
                break;
            case '@':
                this->wall.render(SIZE_SMALL*j, SIZE_SMALL*i, &_clip);
                break;
            case '!':
                this->tree.render(SIZE_SMALL*j, SIZE_SMALL*i, &_clip);
                break;
            case '$':
                this->fountain.render(SIZE_SMALL*j, SIZE_SMALL*i, &_clip);
                break;
            default:
                break;
            }
        }
    }
}