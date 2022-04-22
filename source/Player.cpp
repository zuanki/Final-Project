#include <Player.hpp>
#include <defs.hpp>
Player::Player(){
    this->des.x = 0;
    this->des.y = 0;
    this->des.w = PLAYER_WIDTH;
    this->des.h = PLAYER_HEIGHT;
    this->setPosition(100,100);
    this->_bullet.setPosition(-32, -32);
    this->dir = Direction::down;
}
Player::~Player(){
    //
}
bool Player::loadPlayer(){
    bool success = true;
    if(!this->player.loadFromFile(PLAYER_IMAGE_PATH)){
        success = false;
    }
    if(!this->_bullet.loadBullet()){
        success = false;
    }
    return success;
}
void Player::handleInput(SDL_Event e){
    switch (e.key.keysym.sym)
    {
    case SDLK_UP:    
        this->dir = Direction::up;
        this->pos.second -= PLAYER_MOVE_SPEED;
        this->des.y = PLAYER_HEIGHT*3;
        this->des.x+=PLAYER_WIDTH;
        if (this->des.x > PLAYER_WIDTH*3){
            this->des.x = 0;
        }
        break;
    case SDLK_DOWN:
        this->dir = Direction::down;
        this->pos.second += PLAYER_MOVE_SPEED;
        this->des.y = 0;
        this->des.x+=PLAYER_WIDTH;
        if (this->des.x > PLAYER_WIDTH*3){
            this->des.x = 0;
        }
        break;
    case SDLK_RIGHT:
        this->dir = Direction::right;
        this->pos.first += PLAYER_MOVE_SPEED;
        this->des.y = PLAYER_HEIGHT*2;
        this->des.x+=PLAYER_WIDTH;
        if (this->des.x > PLAYER_WIDTH*3){
            this->des.x = 0;
        }
        break;
    case SDLK_LEFT:
        this->dir = Direction::left;
        this->pos.first -= PLAYER_MOVE_SPEED;
        this->des.y = PLAYER_HEIGHT*1;
        this->des.x+=PLAYER_WIDTH;
        if (this->des.x > PLAYER_WIDTH*3){
            this->des.x = 0;
        }
        break;
    case SDLK_SPACE:
        {
            if (dir == Direction::right && this->_bullet.getHealth() == 0){
                this->_bullet.setPosition(pos.first+32, pos.second);
                this->_bullet.setMoveCoor(BULLET_SHOOTING_TIMER, 0);
                this->_bullet.setHealth(1);
            }
            else if (dir == Direction::left && this->_bullet.getHealth() == 0){
                this->_bullet.setPosition(pos.first-32, pos.second);
                this->_bullet.setMoveCoor(-BULLET_SHOOTING_TIMER, 0);
                this->_bullet.setHealth(1);
            }
            else if (dir == Direction::up && this->_bullet.getHealth() == 0){
                
                    this->_bullet.setPosition(pos.first, pos.second-32);
                    this->_bullet.setMoveCoor(0, -BULLET_SHOOTING_TIMER);
                    this->_bullet.setHealth(1);
            }
            else if (dir == Direction::down && this->_bullet.getHealth() == 0){
            
                    this->_bullet.setPosition(pos.first, pos.second+32);
                    this->_bullet.setMoveCoor(0, BULLET_SHOOTING_TIMER);
                    this->_bullet.setHealth(1);
            }
        }
        break;
    default:
        break;
    }
}
void Player::update(){
    this->_bullet.moveBullet();
    if (this->_bullet.getPosition().first > SCREEN_WIDTH-32*2 || this->_bullet.getPosition().first < 0 || this->_bullet.getPosition().second < 0 || this->_bullet.getPosition().second > SCREEN_HEIGHT-32*2){
        this->_bullet.setHealth(0);
    }
}
void Player::draw(){
    this->player.render(pos.first, pos.second, &des);
    if (this->_bullet.getHealth() == 1){
        this->_bullet.draw();
    }
}