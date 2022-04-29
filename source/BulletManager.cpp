#include <BulletManager.hpp>

BulletManager::BulletManager(GameDataRef data) : data(data) {}

void BulletManager::update(float deltaTime)
{

    // Update each bullet
    for (const auto &bullet : this->_list)
    {
        bullet->update(deltaTime);
    }

    // Remove bullets out
    // int size = std::remove_if(
    //                this->_list.begin(), this->_list.end(),
    //                [](const BulletRef &bullet)
    //                {
    //                    return bullet->isOut;
    //                }) -
    //            this->_list.begin();

    // while ((int)this->_list.size() > size)
    // {
    //     this->_list.pop_back();
    // }

    this->_list.erase(
        std::remove_if(
            this->_list.begin(), this->_list.end(),
            [](const BulletRef &bullet)
            {
                return bullet->isOut;
            }),
        this->_list.end());
}

void BulletManager::draw() const
{
    for (const auto &bullet : this->_list)
    {
        bullet->draw();
        // std::cout << bullet->getGlobalBounds().y << " ";
    }
    // std::cout << std::endl;
    // std::cout << this->_list.size() << std::endl;
}

std::vector<BulletRef> &BulletManager::list()
{
    return this->_list;
}

void BulletManager::spawnBullet(float x, float y, const Vector2f &direction)
{
    auto newBullet = std::make_unique<Bullet>(this->data, direction);

    newBullet->setPosition(x, y);

    this->_list.push_back(std::move(newBullet));
}