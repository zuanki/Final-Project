#include <Map.hpp>

Map::Map(){
    this->camera.x = 0;
    this->camera.y = 0;
    this->camera.w = SCREEN_WIDTH;
    this->camera.h = SCREEN_HEIGHT;
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
    if(!p.loadPlayer()){
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
    p.update();
    //Keep the camera in bounds
    if( this->camera.x < 0 )
    { 
        this->camera.x = 0;
    }
    if( this->camera.y < 0 )
    {
        this->camera.y = 0;
    }
    if( this->camera.x > LEVEL_WIDTH - this->camera.w)
    {
        this->camera.x = LEVEL_WIDTH - this->camera.w ;
    }
    if( this->camera.y > LEVEL_HEIGHT - this->camera.h )
    {
        this->camera.y = LEVEL_HEIGHT - this->camera.h ;
    }
}
void Map::handleEvent(SDL_Event e){
    p.handleInput(e);
    switch (e.key.keysym.sym)
    {
    case SDLK_UP:    
        this->camera.y -= 32;
        break;
    case SDLK_DOWN:
        this->camera.y += 32;
        break;
    case SDLK_RIGHT:
        this->camera.x += 32;
        break;
    case SDLK_LEFT:
        this->camera.x -= 32;
        break;
    default:
        break;
    }
}
void Map::draw(){
    SDL_Rect _clip;
    _clip.x = _clip.y = 0;
    _clip.w = _clip.h = SIZE_SMALL;
    // for (int i=(this->camera.y/32);i<=this->camera.y/32+5;i++){
    //     for (int j=this->camera.x/32;j<=this->camera.x/32+5;j++){
    //         switch (map[i][j])
    //         {
    //         case '#':
    //             this->grass.render(SIZE_SMALL*j, SIZE_SMALL*i, &_clip);
    //             break;
    //         case '@':
    //             this->wall.render(SIZE_SMALL*j, SIZE_SMALL*i, &_clip);
    //             break;
    //         case '!':
    //             this->tree.render(SIZE_SMALL*j, SIZE_SMALL*i, &_clip);
    //             break;
    //         case '$':
    //             this->fountain.render(SIZE_SMALL*j, SIZE_SMALL*i, &_clip);
    //             break;
    //         default:
    //             break;
    //         }
    //     }
    // }
    for (int i=0+this->camera.y/32;i<=(this->camera.y/32+SCREEN_HEIGHT/32-1);i++){
        for (int j=0+this->camera.x/32;j<=(this->camera.x/32+SCREEN_WIDTH/32-1);j++){
            switch (this->map[i][j])
            {
            case '#':
                this->grass.render(SIZE_SMALL*j-this->camera.x, SIZE_SMALL*i-this->camera.y, &_clip);
                break;
            case '@':
                this->wall.render(SIZE_SMALL*j-this->camera.x, SIZE_SMALL*i-this->camera.y, &_clip);
                break;
            case '!':
                this->tree.render(SIZE_SMALL*j-this->camera.x, SIZE_SMALL*i-this->camera.y, &_clip);
                break;
            case '$':
                this->fountain.render(SIZE_SMALL*j-this->camera.x, SIZE_SMALL*i-this->camera.y, &_clip);
                break;
            default:
                break;
            }
        }
    }
    p.draw();
}