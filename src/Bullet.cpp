#include "Bullet.h"

Bullet::Bullet(sf::Texture &texture, float x, float y, float speed, int dir)
{   this->dir = dir;
    this->speed = speed;
    this->sprite.setTexture(texture);
    switch (this->dir){
    case 0: 
        this->x = x+42;
        this->y = y+18;
        this->sprite.setOrigin(6,8); 
        this->sprite.setPosition(this->x, this->y);
        this->sprite.rotate(90);   
        break;
    case 1: 
        this->x = x;
        this->y = y+19;
        this->sprite.setOrigin(6,8); 
        this->sprite.setPosition(this->x, this->y);
        this->sprite.rotate(270);  
        break;
    case 2: 
        this->x = x+17;
        this->y = y+42;
        this->sprite.setScale(1.f, -1.f);  
        this->sprite.setPosition(this->x, this->y);
        break; 
    case 3: 
        this->x = x+12;
        this->y = y;
        this->sprite.setPosition(this->x, this->y);
        break; 
    }
}



Bullet::~Bullet()
{
}

void Bullet::update(float time)
{
    switch (this->dir){
    case 0: this->dx = this->speed; this->dy = 0;   break;
    case 1: this->dx = -this->speed; this->dy = 0;   break;
    case 2: this->dx = 0; this->dy = this->speed;   break; 
    case 3: this->dx = 0; this->dy = -this->speed;   break;
    }
    this->x += this->dx*time;
    this->y += this->dy*time;
    this->sprite.setPosition(this->x,this->y);
}

bool Bullet::interactionWithMap(MapGame &mapGame){
    for (int i = this->y / 64; i < (this->y + 16.f) / 64; i++)
    for (int j = this->x / 64; j<(this->x + 12.f) / 64; j++){
        if (mapGame.TileMap[i][j] == '0'){
            return true;
        }
        if (mapGame.TileMap[i][j] == 's'){
            mapGame.TileMap[i][j] = ' ';
            return true;
        }
    }
    return false;
}

void Bullet::render(sf::RenderTarget & target){
    target.draw(this->sprite);
}

const sf::FloatRect Bullet::getBounds() const{
    return this->sprite.getGlobalBounds();
}
