#include "bullet.hpp"

Bullet::Bullet(){
    des.x = 0;
    des.y = 0;
    des.w = 32;
    des.h = 32;
    x_pos = 0;
    y_pos = 0;
}
Bullet::~Bullet(){
    //
}

void Bullet::showBullet(){
    bu.loadFromFile("../images/fire6.png");
    bu.render(x_pos,y_pos,&des);
}