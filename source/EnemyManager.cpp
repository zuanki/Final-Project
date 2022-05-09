#include <EnemyManager.hpp>

EnemyManager::EnemyManager(GameDataRef data, int level) : data(data), level(level)
{
    if (level == 1)
    {
        this->spawnEnemy("mantis_enemy", Vector2f(17 * 32, 15 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(33 * 32, 34 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(17 * 32, 34 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(13 * 32, 32 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(30 * 32, 34 * 32));
    }
    else if (level == 2)
    {
        this->spawnEnemy("mantis_enemy", Vector2f(102 * 32, 80 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(30 * 32, 16 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(68 * 32, 18 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(67 * 32, 18 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(66 * 32, 18 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(69 * 32, 18 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(70 * 32, 18 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(71 * 32, 18 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(65 * 32, 18 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(64 * 32, 18 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(63 * 32, 18 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(25 * 32, 27 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(103 * 32, 28 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(81 * 32, 28 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(64 * 32, 41 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(63 * 32, 41 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(62 * 32, 41 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(61 * 32, 41 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(60 * 32, 41 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(19 * 32, 80 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(19 * 32, 81 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(59 * 32, 80 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(58 * 32, 80 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(57 * 32, 80 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(56 * 32, 80 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(55 * 32, 80 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(54 * 32, 80 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(53 * 32, 80 * 32));
        this->spawnEnemy("mantis_enemy", Vector2f(52 * 32, 80 * 32));
        this->spawnEnemy("beetle_enemy", Vector2f(89 * 32, 65 * 32));
    }
}

std::vector<EnemyRef> &EnemyManager::list()
{
    return this->_list;
}
void EnemyManager::spawnEnemy(const std::string &name, const Vector2f &pos)
{
    EnemyRef newEnemy = std::make_unique<Enemy>(this->data);
    newEnemy->setPosition(pos.x, pos.y);
    newEnemy->setTexture(this->data->assets.getTexture(name));
    this->_list.push_back(std::move(newEnemy));
}
void EnemyManager::update(float deltaTime)
{
    // Update each enemy
    for (const auto &enemy : this->_list)
    {
        enemy->update(deltaTime);
    }

    // Remove enemies out
    int size = std::remove_if(
                   this->_list.begin(), this->_list.end(),
                   [](const EnemyRef &enemy)
                   {
                       return enemy->isDeath;
                   }) -
               this->_list.begin();

    while ((int)this->_list.size() > size)
    {
        this->_list.pop_back();
    }
}
void EnemyManager::draw()
{
    for (const auto &enemy : this->_list)
    {
        enemy->draw();
    }
}