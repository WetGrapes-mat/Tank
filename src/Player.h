#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
#include "MapGame.h"

class Player { 
private:
    float x, y;
    void initModel();

public:
    float  w, h, dx, dy, speed; 
    int dir = 2;
    float attackColdown;
    float attackColdownMax = 3;
    int HP = 3;

    String File; 
    Image image;
    Texture texture;
    Sprite sprite;

    Player( float X, float Y, float W, float H); 

    void update(float time, MapGame &mapGame);
    void updateAttack(float time);
    void render(sf::RenderTarget& target);

    void playerSetStart();

    void move();
    const bool canAttack();
    void interactionWithMap(MapGame  &mapGame);

    const sf::FloatRect getBounds() const;
    float getPlayerX();
    float getPlayerY();

};