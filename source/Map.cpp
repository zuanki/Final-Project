#include <Map.hpp>
#include <Defs.hpp>
#include <fstream>
#include <Utility/Collison.hpp>
#include <WinState.hpp>
#include <GameOverState.hpp>
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
            else if (this->map_text[i][j] == '*')
            {
                auto k = std::make_unique<Tile>(this->data);
                k->setTexture(this->data->assets.getTexture("flower_tile"));
                k->setPosition(32 * j, 32 * i);
                this->map.push_back(std::move(k));
            }
            else if (this->map_text[i][j] == '&')
            {
                auto k = std::make_unique<Tile>(this->data);
                k->setTexture(this->data->assets.getTexture("lotus_tile"));
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
    // this->enemy = std::make_unique<Enemy>(this->data);
    this->Enemies = std::make_unique<EnemyManager>(this->data, level);
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
    // this->enemy->update(deltaTime);
    this->Enemies->update(deltaTime);
    this->checkCollisionPlayerWithWall();
    this->chechCollisionPlayerWithGate();
    this->checkCollisionPlayerWithEnemy();
    this->checkCollisionBulletWithWall();
    this->checkCollisionBulletWithEnemy();
}
void Map::draw()
{
    for (int i = 0; i < this->map.size(); i++)
    {
        map[i]->draw();
    }
    this->gate->draw();
    this->player->draw();
    // this->enemy->draw();
    this->Enemies->draw();
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
        this->data->machine.addState(StateRef(std::make_unique<WinState>(this->data)));
    }
}
// void Map::checkCollisionPlayerWithEnemy()
// {
//     if (Collision::checkCollision(this->player->getGlobalBounds(), this->enemy->getGlobalBounds()))
//     {
//         this->player->takeHit();
//     }
// }
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

// void Map::checkCollisionBulletWithEnemy()
// {
//     for (const auto &bullet : this->player->getBullet())
//     {

//         if (Collision::checkCollision(bullet->getGlobalBounds(), this->enemy->getGlobalBounds()))
//         {
//             bullet->setOut();
//             this->enemy->takeHit();
//             if (this->enemy->getHp() == 0)
//             {
//                 this->enemy->setDeath(true);
//             }
//             break;
//         }
//     }
// }
void Map::checkCollisionPlayerWithEnemy()
{
    for (const auto &enemy : this->Enemies->list())
    {
        if (Collision::checkCollision(enemy->getGlobalBounds(), this->player->getGlobalBounds()))
        {
            this->data->machine.addState(StateRef(std::make_unique<GameOverState>(this->data)));
        }
    }
}
void Map::checkCollisionBulletWithEnemy()
{
    for (const auto &bullet : this->player->getBullet())
    {
        for (const auto &enemy : this->Enemies->list())
        {
            if (Collision::checkCollision(bullet->getGlobalBounds(), enemy->getGlobalBounds()))
            {
                bullet->setOut();
                enemy->takeHit();
                if (enemy->getHp() == 0)
                {
                    enemy->setDeath(true);
                }
                break;
            }
        }
    }
}