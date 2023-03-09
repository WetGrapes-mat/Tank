#pragma once
#include <SFML/Graphics.hpp>
#include "MapGame.h"
using namespace sf;


class Bullet
{
private:
    Sprite sprite;
    float x, y, dx, dy, speed; 
    int dir = 2;
public:
    Bullet(sf::Texture &texture, float x, float y,  float speed, int dir);
    ~Bullet();

    bool interactionWithMap(MapGame& mapGame);
    void update(float time);
    void render(sf::RenderTarget& target);
    const sf::FloatRect getBounds() const;


};

