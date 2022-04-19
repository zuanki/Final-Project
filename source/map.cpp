#include"map.hpp"

Map::Map()
{
    
}

Map::~Map()
{

}
bool Map::loadMap()
{   
    bool success = true;
    if(!grass.loadFromFile("../images/SAND.png")){
        success = false;
    }
    if(!wall.loadFromFile("../images/wood.png")){
        success = false;
    }
    std::ifstream readmap("../res/1.txt");
    if(readmap.is_open())
    {
        std::string x;
        while(getline(readmap, x))
        {
            map.push_back(x);
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

void Map::showMap()
{
    SDL_Rect grass_clip;
    grass_clip.x = grass_clip.y = 0;
    grass_clip.w = grass_clip.h = 32;
    SDL_Rect wall_clip;
    wall_clip.x = wall_clip.y = 0;
    wall_clip.w = wall_clip.h = 32;
    for (int i=0;i<map.size();i++){
        for (int j=0;j<map[i].size();j++){
            switch (map[i][j])
            {
            case '#':
                grass.render(32*j, 32*i, &grass_clip);
                break;
            case '@':
                wall.render(32*j, 32*i, &wall_clip);
            default:
                break;
            }
        }
    }
}

