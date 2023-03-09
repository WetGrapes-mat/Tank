#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

sf::View view;

View getPlayerXYView(float x, float y){
    float tempX = x; float tempY = y;
    if(x < 640) tempX = 640;
    if(x > 1088) tempX =1088;
    if(y < 360) tempY = 360;
    if(y > 1368) tempY = 1368;
    view.setCenter(tempX, tempY);
    return view;
}

