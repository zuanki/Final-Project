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
    if (!this->water.loadFromFile(WATER_IMAGE_PATH)){
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
    for (int i=7;i<this->map.size()-6;i++){
        for (int j=9;j<this->map[i].size()-10;j++){
            if (map[i][j] == '@'){
                this->obstacle.push_back(std::make_pair(32*j ,32*i));
            }
        }
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
        {
            if (this->checkCollisions(this->p.getDirection())){
                this->camera.y -= 0;
            }
            else{
                this->camera.y -= 32;
            }
        }
        break;
    case SDLK_DOWN:
        {
            if(this->checkCollisions(this->p.getDirection())){
                this->camera.y += 0;
            }
            else {
                this->camera.y += 32;
            }
        }
        break;
    case SDLK_RIGHT:
        {
            if(this->checkCollisions(this->p.getDirection())){
                this->camera.x += 0;
            }
            else {
                this->camera.x += 32;
            }
        }
        break;
    case SDLK_LEFT:
        {
            if(this->checkCollisions(this->p.getDirection())){
                this->camera.x -= 0;
            }
            else {
                this->camera.x -= 32;
            }
        }
        break;
    default:
        break;
    }
}
void Map::draw(){
    SDL_Rect _clip;
    _clip.x = _clip.y = 0;
    _clip.w = _clip.h = SIZE_SMALL;
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
            case '%':
                this->water.render(SIZE_SMALL*j-this->camera.x, SIZE_SMALL*i-this->camera.y, &_clip);
                break;
            default:
                break;
            }
        }
    }
    p.draw();
}
bool Map::checkCollisions(Direction dir){
    bool check = false;
    for (int i=0;i<this->obstacle.size();i++){
        if (dir == Direction::up){
            std::pair<int, int> k = this->p.getPosition();
            if (k.second == this->obstacle[i].second+32-this->camera.y && k.first == this->obstacle[i].first-this->camera.x){
                check = true;
            }
        }
        else if (dir == Direction::down){
            std::pair<int, int> k = this->p.getPosition();
            if (k.second + 32 == this->obstacle[i].second-this->camera.y && k.first == this->obstacle[i].first-this->camera.x){
                check = true;
            }
        }
        else if (dir == Direction::left){
            std::pair<int, int> k = this->p.getPosition();
            if (k.second == this->obstacle[i].second-this->camera.y && k.first == this->obstacle[i].first + 32 -this->camera.x){
                check = true;
            }
        }
        else if (dir == Direction::right){
            std::pair<int, int> k = this->p.getPosition();
            if (k.second == this->obstacle[i].second-this->camera.y && k.first+32 == this->obstacle[i].first-this->camera.x){
                check = true;
            }
        }
    }
    return check;
}