#pragma once
#include <Enemy.hpp>
#include <memory>
#include <algorithm>
#include <vector>

using EnemyRef = std::unique_ptr<Enemy>;

class EnemyManager
{
private:
    GameDataRef data;
    std::vector<EnemyRef> _list;
    int level;

public:
    EnemyManager(GameDataRef data, int level = 1);
    std::vector<EnemyRef> &list();
    void spawnEnemy(const std::string &name, const Vector2f &pos);
    void update(float deltaTime);
    void draw();
};