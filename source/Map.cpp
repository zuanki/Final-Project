#include <Map.hpp>
#include <Defs.hpp>
#include <fstream>
#include <Utility/Collison.hpp>
Map::Map(GameDataRef data) : data(data)
{
    std::ifstream readmap(MAP_TXT_PATH);
    if (readmap.is_open())
    {
        std::string x;
        while (getline(readmap, x))
        {
            this->map_text.push_back(x);
        }
        readmap.close();
    }
    for (int i = 0; i < this->map_text.size(); i++)
    {
        for (int j = 0; j < this->map_text[i].size(); j++)
        {
            if (this->map_text[i][j] == '#')
            {
                auto k = std::make_unique<Tile>(this->data);
                k->setTexture(this->data->assets.getTexture("path_tile"));
                k->setPosition(32 * j, 32 * i);
                this->map.push_back(std::move(k));
            }
            else if (this->map_text[i][j] == '@')
            {
                auto k = std::make_unique<Tile>(this->data);
                k->setTexture(this->data->assets.getTexture("wall_tile"));
                k->setPosition(32 * j, 32 * i);
                this->map.push_back(std::move(k));
            }
            else if (this->map_text[i][j] == '!')
            {
                auto k = std::make_unique<Tile>(this->data);
                k->setTexture(this->data->assets.getTexture("tree_tile"));
                k->setPosition(32 * j, 32 * i);
                this->map.push_back(std::move(k));
            }
            else if (this->map_text[i][j] == '$')
            {
                auto k = std::make_unique<Tile>(this->data);
                k->setTexture(this->data->assets.getTexture("water_tile"));
                k->setPosition(32 * j, 32 * i);
                this->map.push_back(std::move(k));
            }
        }
    }
    for (int i = 0; i < this->map_text.size(); i++)
    {
        for (int j = 0; j < this->map_text[i].size(); j++)
        {
            if (this->map_text[i][j] == '@')
            {
                auto k = std::make_unique<Tile>(this->data);
                k->setTexture(this->data->assets.getTexture("wall_tile"));
                k->setPosition(32 * j, 32 * i);
                this->wall.push_back(std::move(k));
            }
        }
    }
    this->player = std::make_unique<Player>(this->data);
}
Map::~Map()
{
    //
}
void Map::handleInput(SDL_Event e)
{
    this->player->handleInput(e);
}
void Map::init()
{
    //
}
void Map::update(float deltaTime)
{
    this->player->update(deltaTime);
    this->checkCollisionWithWall();
    // if (Collision::checkCollision(this->player->getGlobalBounds(), this->wall[0]->getGlobalBounds()))
    // {
    //     std::cout << "He he it works" << std::endl;
    // }
}
void Map::draw()
{
    for (int i = 0; i < this->wall.size(); i++)
    {
        wall[i]->draw();
    }
    this->player->draw();
}
void Map::checkCollisionWithWall()
{

    for (int i = 0; i < this->wall.size(); i++)
    {

        if (Collision::checkCollision(this->player->getGlobalBounds(), this->wall[i]->getGlobalBounds()))
        {
            if (this->player->getDirection() == Direction::up)
            {
                this->player->setVelocity(0, 32);
            }
            else if (this->player->getDirection() == Direction::down)
            {
                this->player->setVelocity(0, -32);
            }
            else if (this->player->getDirection() == Direction::left)
            {
                this->player->setVelocity(32, 0);
            }
            else if (this->player->getDirection() == Direction::right)
            {
                this->player->setVelocity(-32, 0);
            }
        }
    }

    // else if (this->player->getDirection()==Direction::down){
    //     for (int i = 0; i < this->wall.size(); i++)
    //     {
    //         if (Collision::checkCollision(this->player->getGlobalBounds(), this->wall[i]->getGlobalBounds()))
    //         {
    //             this->player->setVelocity(0, 0);
    //         }
    //     }
    // }
}