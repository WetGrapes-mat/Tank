#pragma once

#include "MapGame.h"
#include <SFML/Graphics.hpp>

using namespace sf;


class Enemy 
{
private:
    float x, y;
    void initModel(sf::Texture &texture);

public:
    float  w, h, dx, dy; 
    int dir;
    float speed = 0.2f;

    float attackColdown ;
    float attackColdownMax = 10;


    String File; 
    Image image;
    Texture texture;
    Sprite sprite;

    Enemy(sf::Texture &texture,float X, float Y, float W, float H);
    ~Enemy();

    void update(float time, MapGame &mapGame);
    void updateAttack(float time);
    void render(sf::RenderTarget &target);
    void move();
    void interactionWithMap(MapGame &mapGame);
    const bool canAttack();


    const sf::FloatRect getBounds() const;
    float getEnemyX();
    float getEnemyY();



};
