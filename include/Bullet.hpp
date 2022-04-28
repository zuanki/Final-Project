#pragma once 
#include <Game.hpp>
#include <utility>
class Bullet {
    private:
        Sprite bullet_sprite;
        GameDataRef data;
        std::pair<int, int> move_coor;
        int health;
    public:
        Bullet(GameDataRef data);
        ~Bullet();
        void draw();
        void setMoveCoor(int u, int v){
            move_coor = std::make_pair(u, v);
        }
        void setPosition(int u, int v){
            bullet_sprite.setPosition(u, v);
        }
        void move(std::pair<int, int> q){
            bullet_sprite.move(q.first, q.second);
        }
        void setHealth(int x){
            health = x;
        }
        int getHealth() {
            return health;
        }
        std::pair<int, int> getPosition(){
            return std::make_pair(this->bullet_sprite.getPosition().x, this->bullet_sprite.getPosition().y);
        }
};