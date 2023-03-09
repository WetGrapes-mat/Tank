#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class MapGame
{
private:
    Image map_image;
    Texture map;
    void initModelMap();
public:
    MapGame();
    ~MapGame();
    Sprite s_map;
    void render(sf::RenderTarget& target);
    void clearMap();
    const int HEIGHT_MAP = 27;
    const int WIDTH_MAP = 27;
    String TileMap[27] = {
    "000000000000000000000000000",
    "0          0   0          0",
    "0 s ss sss s   s sss ss s 0",
    "0 s    s s s 0 s s s    s 0",
    "0 ssss s           s ssss 0",
    "0  s s sssssssssssss s s  0",
    "0s s         s         s s0",
    "0s sss ss ss s ss ss sss s0",
    "0      s  s  s  s  s      0",
    "0000 ssssss sss ssssss 0000",
    "0       s s sss s s       0",
    "0s s ss s    0    s ss s s0",
    "0s sss    s 000 s    sss s0",
    "0s   s ss s     s ss s   s0",
    "0s s s   X0 s s 0X   s s s0",
    "0  s ssss s s s s ssss s  0",
    "0 ss s    s s s s    s ss 0",
    "0  s sss ss     ss sss s  0",
    "0s s        s s        s s0",
    "0  sssss sss000sss sssss  0",
    "0 ss   s     0     s   ss 0",
    "0    s sssss s sssss s    0",
    "0sss s     s   s     s sss0",
    "0    ssss ss s ss ssss    0",
    "0 ssss     s s s     ssss 0",
    "0      0ss   s   ss0      0",
    "000000000000000000000000000",
};
    String copyTileMap[27] = {
   "000000000000000000000000000",
    "0          0   0          0",
    "0 s ss sss s   s sss ss s 0",
    "0 s    s s s 0 s s s    s 0",
    "0 ssss s           s ssss 0",
    "0  s s sssssssssssss s s  0",
    "0s s         s         s s0",
    "0s sss ss ss s ss ss sss s0",
    "0      s  s  s  s  s      0",
    "0000 ssssss sss ssssss 0000",
    "0       s s sss s s       0",
    "0s s ss s    0    s ss s s0",
    "0s sss    s 000 s    sss s0",
    "0s   s ss s     s ss s   s0",
    "0s s s   X0 s s 0X   s s s0",
    "0  s ssss s s s s ssss s  0",
    "0 ss s    s s s s    s ss 0",
    "0  s sss ss     ss sss s  0",
    "0s s        s s        s s0",
    "0  sssss sss000sss sssss  0",
    "0 ss   s     0     s   ss 0",
    "0    s sssss s sssss s    0",
    "0sss s     s   s     s sss0",
    "0    ssss ss s ss ssss    0",
    "0 ssss     s s s     ssss 0",
    "0      0ss   s   ss0      0",
    "000000000000000000000000000",
};

};