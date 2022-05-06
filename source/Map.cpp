#include <Map.hpp>
#include <Defs.hpp>
#include <fstream>
#include <Utility/Collison.hpp>
Map::Map(GameDataRef data, int level) : data(data)
{
    std::string xpath = "../resource/maptypes/" + std::to_string(level) + ".txt";
    std::ifstream readmap(xpath);
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
            else if (this->map_text[i][j] == 'O')
            {
                this->gate = std::make_unique<Tile>(this->data);
                this->gate->setTexture(this->data->assets.getTexture("gate_tile"));
                this->gate->setPosition(32 * j, 32 * i);
            }
        }
    }

    this->player = std::make_unique<Player>(this->data);
    this->enemy = std::make_unique<Enemy>(this->data);
    std::cout << this->map_text.size() << " " << this->map_text[0].size() << std::endl;
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
    this->enemy->update(deltaTime);
    this->checkCollisionPlayerWithWall();
    this->chechCollisionPlayerWithGate();
    this->checkCollisionPlayerWithEnemy();
    this->checkCollisionBulletWithWall();
    this->checkCollisionBulletWithEnemy();
    // if (Collision::checkCollision(this->player->getGlobalBounds(), this->wall[0]->getGlobalBounds()))
    // {
    //     std::cout << "He he it works" << std::endl;
    // }
}
void Map::draw()
{
    for (int i = 0; i < this->map.size(); i++)
    {
        map[i]->draw();
    }
    this->gate->draw();
    this->player->draw();
    this->enemy->draw();
}
void Map::checkCollisionPlayerWithWall()
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
void Map::chechCollisionPlayerWithGate()
{
    if (Collision::checkCollision(this->player->getGlobalBounds(), this->gate->getGlobalBounds()))
    {
        std::cout << "Win" << std::endl;
    }
}
void Map::checkCollisionPlayerWithEnemy()
{
    if (Collision::checkCollision(this->player->getGlobalBounds(), this->enemy->getGlobalBounds()))
    {
        this->enemy->setDeath(true);
    }
}
void Map::checkCollisionBulletWithWall()
{
    for (const auto &bullet : this->player->getBullet())
    {
        for (const auto &wall : this->wall)
        {
            if (Collision::checkCollision(bullet->getGlobalBounds(), wall->getGlobalBounds()))
            {
                bullet->setOut();
                break;
            }
        }
    }
}

void Map::checkCollisionBulletWithEnemy()
{
    for (const auto &bullet : this->player->getBullet())
    {

        if (Collision::checkCollision(bullet->getGlobalBounds(), this->enemy->getGlobalBounds()))
        {
            bullet->setOut();
            this->enemy->setDeath(true);
            break;
        }
    }
}