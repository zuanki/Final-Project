#include <Player.hpp>
#include <Defs.hpp>
Player::Player(GameDataRef data) : data(data){
    this->moveSpeed = 32;
    this->sprite_player.setTexture(this->data->assets.getTexture("player"));
    this->player_clip = {0, 0, 32, 48};
    this->_bullet = std::make_unique<Bullet>(this->data);
    this->sprite_player.setTextureRect(this->player_clip);
    this->pos = std::make_pair(32, 32);
    this->dir = Direction::down;
    this->coor_bullet = std::make_pair(0, 0);
}
Player::~Player(){
    
}
void Player::handleInput(SDL_Event e){
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.scancode)  
        {
        case SDL_SCANCODE_W:
            this->dir = Direction::up;
            this->pos.second -= this->moveSpeed;
            this->player_clip.y = 48*3;
            this->player_clip.x += 32;
            if (this->player_clip.x >= 32*4){
                this->player_clip.x = 0;
            }
            break;
        case SDL_SCANCODE_S:
            this->dir = Direction::down;
            this->pos.second += this->moveSpeed;
            this->player_clip.y = 48*0;
            this->player_clip.x += 32;
            if (this->player_clip.x >= 32*4){
                this->player_clip.x = 0;
            }
            break;
        case SDL_SCANCODE_A:
            this->dir = Direction::left;
            this->pos.first -= this->moveSpeed;
            this->player_clip.y = 48*1;
            this->player_clip.x += 32;
            if (this->player_clip.x >= 32*4){
                this->player_clip.x = 0;
            }
            break;
        case SDL_SCANCODE_D:
            this->dir = Direction::right;
            this->pos.first += this->moveSpeed;
            this->player_clip.y = 48*2;
            this->player_clip.x += 32;
            if (this->player_clip.x >= 32*4){
                this->player_clip.x = 0;
            }
            break;
        case SDL_SCANCODE_SPACE:
            {
                if (this->dir == Direction::down && this->_bullet->getHealth() == 0){
                    this->coor_bullet = std::make_pair(0, 1);
                    this->_bullet->setPosition(pos.first, pos.second+32);
                    this->_bullet->setHealth(1);
                }
                else if (this->dir == Direction::up && this->_bullet->getHealth() == 0){
                    this->coor_bullet = std::make_pair(0, -1);
                    this->_bullet->setPosition(pos.first, pos.second-32);
                    this->_bullet->setHealth(1);
                }
                else if (this->dir == Direction::left && this->_bullet->getHealth() == 0){
                    this->coor_bullet = std::make_pair(-1, 0);
                    this->_bullet->setPosition(pos.first-32, pos.second);
                    this->_bullet->setHealth(1);
                }
                else if (this->dir == Direction::right && this->_bullet->getHealth() == 0){
                    this->coor_bullet = std::make_pair(1, 0);
                    this->_bullet->setPosition(pos.first+32, pos.second);
                    this->_bullet->setHealth(1);
                }
                
            }
            break;
        default:
            break;
        }
    }
}
void Player::update(){
    this->_bullet->move(this->coor_bullet);
    if (this->_bullet->getPosition().first > this->pos.first + 200 || this->_bullet->getPosition().first < this->pos.first-200 || this->_bullet->getPosition().second > this->pos.second +200 || this->_bullet->getPosition().second < this->pos.second -200){
        this->_bullet->setHealth(0);
    }
    this->sprite_player.setPosition(pos.first, pos.second);
    this->sprite_player.setTextureRect(this->player_clip);
    this->playerView = this->data->window.getDefaultView();
    this->playerView.setCenter(this->sprite_player.getPosition());
    this->data->window.setView(this->playerView);

}
void Player::setPosition(int u, int v){
    this->sprite_player.setPosition(u, v);
}
void Player::draw(){
    this->data->window.draw(this->sprite_player);
    if (this->_bullet->getHealth() == 1){
        this->_bullet->draw();
    }
}