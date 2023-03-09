#include "Enemy.h"

Enemy::Enemy(sf::Texture &texture, float X, float Y, float W, float H)
{
    this->w = W; 
    this->h = H;
    this->x = X; 
    this->y = Y;
    this->dir = rand() % 4;
    this->attackColdown = 0;
    this->initModel(texture);
}

Enemy::~Enemy()
{
}

void Enemy::initModel(sf::Texture &texture){
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(IntRect(0,0,this->w,this->h));
    this->sprite.setPosition(this->x,this->y);

}

void Enemy::update(float time, MapGame &mapGame){
    switch (this->dir){
    case 0: 
        this->dx = this->speed; 
        this->dy = 0;
        this->sprite.setTextureRect(IntRect(88,42,-46,-42));
        break;
    case 1: 
        this->dx = -this->speed; 
        this->dy = 0;
        this->sprite.setTextureRect(IntRect(42,0,46,42));   
        break;
    case 2: 
        this->dx = 0; 
        this->dy =this->speed;
        this->sprite.setTextureRect(IntRect(0,0,42,46));   
        break; 
    case 3: 
        this->dx = 0; 
        this->dy = -this->speed;
        this->sprite.setTextureRect(IntRect(42,46,-42,-46));   
        break;
    }
    this->x += this->dx*time;
    this->y += this->dy*time;
    this->interactionWithMap(mapGame);
    this->updateAttack(time);
    this->sprite.setPosition(this->x,this->y);
}

void Enemy::updateAttack(float time){
    if (this->attackColdown < attackColdownMax) this->attackColdown += 0.005*time;
}


void Enemy::interactionWithMap(MapGame &mapGame){
    for (int i = this->y / 64; i < (this->y + this->h) / 64; i++)
    for (int j = this->x / 64; j<(this->x + this->w) / 64; j++){
        if (mapGame.TileMap[i][j] == '0' || mapGame.TileMap[i][j] == 's'){
            if (this->dy>0){
                this->y = i * 64 - this->h;
                this->dir = rand() % 4;
            }
            if (this->dy<0){
                this->y = i * 64 + 64;
                this->dir = rand() % 4;

            }
            if (this->dx>0){
                this->x = j * 64 - this->w;
                this->dir = rand() % 4;
            }
            if (this->dx < 0){
                this->x = j * 64 + 64;
                this->dir = rand() % 4;
            }
        }
    }
}

const bool Enemy::canAttack(){
    if (this->attackColdown > attackColdownMax) {
        this->attackColdown = 0;
        return true;
    }
    return false;
}

const sf::FloatRect Enemy::getBounds() const{
    return this->sprite.getGlobalBounds();
}

float Enemy::getEnemyX()
{
    return this->x;
}

float Enemy::getEnemyY()
{
    return this->y;
}

void Enemy::render(sf::RenderTarget & target){
    target.draw(this->sprite);
}