#include <Player.hpp>
#include <Defs.hpp>
Player::Player(GameDataRef data) : data(data){
    this->playerTexture = IMG_LoadTexture(this->data->window.getRenderer(), PLAYER_IMAGE_PATH);
    if (this->playerTexture == NULL){
        std::cout<<"Can't load player image"<<std::endl;
        this->data->window.close();
    }
    this->moveSpeed = 32;
    this->sprite_player.setTexture(this->playerTexture);
    this->player_clip = {0, 0, 32, 48};
    this->sprite_player.setTextureRect(this->player_clip);
}
Player::~Player(){
    SDL_DestroyTexture(this->playerTexture);
}
void Player::handleInput(SDL_Event e){
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.scancode)  
        {
        case SDL_SCANCODE_W:
            this->sprite_player.move(0, -this->moveSpeed);
            this->player_clip.y = 48*3;
            this->player_clip.x += 32;
            if (this->player_clip.x >= 32*4){
                this->player_clip.x = 0;
            }
            break;
        case SDL_SCANCODE_S:
            this->sprite_player.move(0, this->moveSpeed);
            this->player_clip.y = 48*0;
            this->player_clip.x += 32;
            if (this->player_clip.x >= 32*4){
                this->player_clip.x = 0;
            }
            break;
        case SDL_SCANCODE_A:
            this->sprite_player.move(-this->moveSpeed, 0);
            this->player_clip.y = 48*1;
            this->player_clip.x += 32;
            if (this->player_clip.x >= 32*4){
                this->player_clip.x = 0;
            }
            break;
        case SDL_SCANCODE_D:
            this->sprite_player.move(this->moveSpeed, 0);
            this->player_clip.y = 48*2;
            this->player_clip.x += 32;
            if (this->player_clip.x >= 32*4){
                this->player_clip.x = 0;
            }
            break;
        default:
            break;
        }
    }
}
void Player::update(){
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
}