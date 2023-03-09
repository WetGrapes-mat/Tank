#include "Player.h"

using namespace sf;

Player::Player(float X, float Y, float W, float H){  
    w = W; 
    h = H;
    x = X; 
    y = Y;
    initModel();
}

void Player::initModel(){
    image.loadFromFile("images/TanksP.png");
    image.createMaskFromColor(Color(0,0,0));
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0,0,w,h));
}


void Player::update(float time, MapGame &mapGame){
    move();
    switch (dir){
    case 0: dx = speed; dy = 0;   break;
    case 1: dx = -speed; dy = 0;   break;
    case 2: dx = 0; dy = speed;   break; 
    case 3: dx = 0; dy = -speed;   break;
    }
    x += dx*time;
    y += dy*time;
    speed = 0;
    sprite.setPosition(x,y);
    updateAttack(time);
    interactionWithMap(mapGame);
}

void Player::updateAttack(float time){
    if (attackColdown < attackColdownMax) attackColdown += 0.005*time;
}

void Player::render(sf::RenderTarget& target){
    target.draw(sprite);
}

void Player::playerSetStart(){
    x = 13*64;
    y = 64;
}

void Player::move(){
if (Keyboard::isKeyPressed(Keyboard::A)){
    dir = 1; speed = 0.2;
    sprite.setTextureRect(IntRect(42,0,46,42));
}
if (Keyboard::isKeyPressed(Keyboard::D)) {
    dir = 0; speed = 0.2;
    sprite.setTextureRect(IntRect(88,42,-46,-42)); 
}
if (Keyboard::isKeyPressed(Keyboard::W)) { 
    dir = 3; speed = 0.2;
    sprite.setTextureRect(IntRect(42,46,-42,-46)); 
}
if (Keyboard::isKeyPressed(Keyboard::S)) { 
    dir = 2; speed = 0.2;
    sprite.setTextureRect(IntRect(0,0,42,46)); 
}
}

const bool Player::canAttack(){
    if (attackColdown > attackColdownMax) {
        attackColdown = 0;
        return true;
    }
    return false;
}

void Player::interactionWithMap(MapGame &mapGame){
    for (int i = y / 64; i < (y + h) / 64; i++)
    for (int j = x / 64; j<(x + w) / 64; j++){
        if (mapGame.TileMap[i][j] == '0'|| mapGame.TileMap[i][j] == 's'){
            if (dy>0){
                y = i * 64 - h;
            }
            if (dy<0){
                y = i * 64 + 64;
            }
            if (dx>0){
                x = j * 64 - w;
            }
            if (dx < 0){
                x = j * 64 + 64;
            }
        }
    }
}

const sf::FloatRect Player::getBounds() const
{
    return sprite.getGlobalBounds();
}

float Player::getPlayerX(){
    return x;
}

float Player::getPlayerY(){
    return y;
}





