#include <Player.hpp>
#include <Defs.hpp>
Player::Player(GameDataRef data) : data(data)
{
    this->moveSpeed = 300;
    this->sprite_player.setTexture(this->data->assets.getTexture("player"));
    this->player_clip = {0, 0, 32, 48};
    this->sprite_player.setTextureRect(this->player_clip);
    this->pos = std::make_pair(32, 32);
    this->dir = Direction::down;
    this->direction.x = 0.f;
    this->direction.y = 0.f;
    this->shootingTimer = BULLET_SHOOTING_COOLDOWN;
    this->_bullets = std::make_unique<BulletManager>(this->data);
    Mix_PlayMusic(this->data->assets.getMusic(), -1);
}
Player::~Player()
{
}
void Player::handleInput(SDL_Event e)
{
    this->velocity.first = 0;
    this->velocity.second = 0;
    if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.scancode)
        {
        case SDL_SCANCODE_UP:
            this->dir = Direction::up;
            this->velocity.second = -this->moveSpeed;
            this->velocity.first = 0;
            this->player_clip.y = 48 * 3;
            this->player_clip.x += 32;
            if (this->player_clip.x >= 32 * 4)
            {
                this->player_clip.x = 0;
            }
            break;
        case SDL_SCANCODE_DOWN:
            this->dir = Direction::down;
            this->velocity.second = this->moveSpeed;
            this->velocity.first = 0;
            this->player_clip.y = 48 * 0;
            this->player_clip.x += 32;
            if (this->player_clip.x >= 32 * 4)
            {
                this->player_clip.x = 0;
            }
            break;
        case SDL_SCANCODE_LEFT:
            this->dir = Direction::left;
            this->velocity.first = -this->moveSpeed;
            this->velocity.second = 0;
            this->player_clip.y = 48 * 1;
            this->player_clip.x += 32;
            if (this->player_clip.x >= 32 * 4)
            {
                this->player_clip.x = 0;
            }
            break;
        case SDL_SCANCODE_RIGHT:
            this->dir = Direction::right;
            this->velocity.first = this->moveSpeed;
            this->velocity.second = 0;
            this->player_clip.y = 48 * 2;
            this->player_clip.x += 32;
            if (this->player_clip.x >= 32 * 4)
            {
                this->player_clip.x = 0;
            }
            break;
        case SDL_SCANCODE_SPACE:
            // {
            //     if (this->dir == Direction::down && this->_bullet->getHealth() == 0)
            //     {
            //         this->coor_bullet = std::make_pair(0, SHOOTING_SPEED);
            //         this->_bullet->setPosition(pos.first, pos.second + 32);
            //         this->_bullet->setHealth(1);
            //     }
            //     else if (this->dir == Direction::up && this->_bullet->getHealth() == 0)
            //     {
            //         this->coor_bullet = std::make_pair(0, -SHOOTING_SPEED);
            //         this->_bullet->setPosition(pos.first, pos.second - 32);
            //         this->_bullet->setHealth(1);
            //     }
            //     else if (this->dir == Direction::left && this->_bullet->getHealth() == 0)
            //     {
            //         this->coor_bullet = std::make_pair(-SHOOTING_SPEED, 0);
            //         this->_bullet->setPosition(pos.first - 32, pos.second);
            //         this->_bullet->setHealth(1);
            //     }
            //     else if (this->dir == Direction::right && this->_bullet->getHealth() == 0)
            //     {
            //         this->coor_bullet = std::make_pair(SHOOTING_SPEED, 0);
            //         this->_bullet->setPosition(pos.first + 32, pos.second);
            //         this->_bullet->setHealth(1);
            //     }
            // }
            //****************************************************************************
            {
                if (this->shootingTimer > BULLET_SHOOTING_COOLDOWN)
                {
                    this->shootingTimer = 0.f;
                    this->shoot();
                }
                Mix_PlayChannel(-1, this->data->assets.getChuck(), 0);
            }
            break;
        default:
            break;
        }
    }
}
void Player::update(float deltaTime)
{
    this->pos.first += this->velocity.first * deltaTime;
    this->pos.second += this->velocity.second * deltaTime;
    // Update bullets
    this->_bullets->update(deltaTime);
    this->shootingTimer += deltaTime;
    // this->_bullet->move(this->coor_bullet);
    //  if (this->_bullet->getPosition().first > this->pos.first + 350 || this->_bullet->getPosition().first < this->pos.first - 350 || this->_bullet->getPosition().second > this->pos.second + 350 || this->_bullet->getPosition().second < this->pos.second - 350)
    //  {
    //      this->_bullet->setHealth(0);
    //  }
    this->sprite_player.setPosition(pos.first, pos.second);
    this->sprite_player.setTextureRect(this->player_clip);
    this->playerView = this->data->window.getDefaultView();
    this->playerView.setCenter(this->sprite_player.getPosition());
    this->data->window.setView(this->playerView);
}
void Player::setPosition(int u, int v)
{
    this->sprite_player.setPosition(u, v);
}
void Player::draw()
{
    this->data->window.draw(this->sprite_player);
    // if (this->_bullet->getHealth() == 1)
    // {
    //     this->_bullet->draw();
    // }
    this->_bullets->draw();
}
void Player::shoot()
{
    SDL_Rect t = this->getGlobalBounds();

    if (this->dir == Direction::up)
    {
        this->_bullets->spawnBullet(
            t.x, t.y - 32,
            Vector2f(0.f, -1.f));
    }
    else if (this->dir == Direction::down)
    {
        this->_bullets->spawnBullet(
            t.x, t.y + 32,
            Vector2f(0.f, 1.f));
    }
    else if (this->dir == Direction::left)
    {
        this->_bullets->spawnBullet(
            t.x - 32, t.y,
            Vector2f(-1.f, 0.f));
    }
    else if (this->dir == Direction::right)
    {
        this->_bullets->spawnBullet(
            t.x + 32, t.y,
            Vector2f(1.f, 0.f));
    }
}