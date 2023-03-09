#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include "MapGame.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <map>


using namespace sf;


class TankGame{
private:
    int playerScore = 0;
    float time;
    float timerSpawn;
    std::shared_ptr<RenderWindow> window;
    std::shared_ptr<Clock> clock;
    std::shared_ptr<MapGame> gameMap;
    std::shared_ptr<Player> player;

    std::map <std::string, sf::Texture*> textures;
    std::vector<Bullet> bullets;
    std::vector<Bullet> bulletsEnemy;

    std::vector<Enemy> enemys;


    Font font;
    Text scoreText;
    Text HPText;


    void initGame();
    void initPlayer();
    void initMap();
    void initTexture();
    void initEnemy();
    void initGUI();

public:
    TankGame();
    ~TankGame();
    void run();

    void restartGame();

    void update();
    void updateMovePlayer(); 
    void updateBullets();
    void updateEnemy();
    void updateGUI();
    float updateTime();

    void render();
};