#include "TankGame.h"
#include "view.h"
#include <iostream>


TankGame::TankGame(){
    initGame();
    initPlayer();
    initTexture();
    initEnemy();
    initGUI();
}

void TankGame::initGame(){
    window = std::make_shared<RenderWindow>(sf::VideoMode(1280, 720), "Tank");
    gameMap  = std::make_shared<MapGame>();
    clock  = std::make_shared<Clock>();
    view.reset(sf::FloatRect(0,0,1280,720));
}


void TankGame::initPlayer(){
    player = std::make_shared<Player>(64*13,64*1,42,46);
}


void TankGame::initTexture(){
    textures["BULLET"] = new Texture();
    textures["BULLET"]->loadFromFile("images/bulletSand.png");
    textures["BULLETENEMY"] = new Texture();
    textures["BULLETENEMY"]->loadFromFile("images/bulletDark.png");
    textures["ENEMY"] = new Texture();
    textures["ENEMY"]->loadFromFile("images/TanksE.png");
}


void TankGame::initEnemy()
{
    enemys.push_back(Enemy(*textures["ENEMY"], 64*6,64*7,42,46));
    enemys.push_back(Enemy(*textures["ENEMY"], 64*20,64*7,42,46));
    enemys.push_back(Enemy(*textures["ENEMY"], 64*9,64*13,42,46));
    enemys.push_back(Enemy(*textures["ENEMY"], 64*17,64*13,42,46));
    enemys.push_back(Enemy(*textures["ENEMY"], 64*11,64*20,42,46));
    enemys.push_back(Enemy(*textures["ENEMY"], 64*15,64*20,42,46));
}

void TankGame::initGUI(){
    font.loadFromFile("fonts/Bighaustitul_extrabold.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::Black);

    HPText.setFont(font);
    HPText.setCharacterSize(50);
    HPText.setFillColor(sf::Color::Black);
 }


TankGame::~TankGame(){
    for (auto &i : textures)
    {
        delete i.second;
    }
    textures.clear();

}

void TankGame::run(){
    while (window->isOpen()){
        update();
        render();
    }
}


void TankGame::update(){
    Event event;
    while (window->pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window->close();
            }
        if (event.KeyPressed && event.key.code == sf::Keyboard::Escape){
            window->close();
        }
    }
    time = updateTime();
    if (player->HP == 0){
        restartGame();
    }
    updateMovePlayer();
    updateBullets();
    updateEnemy();
    updateGUI();
    getPlayerXYView(player->getPlayerX(),player->getPlayerY());
    window->setView(view);
}

float TankGame::updateTime(){
    time = clock->getElapsedTime().asMicroseconds();
    clock->restart();
    time = time / 800;
    timerSpawn += 0.005*time;
    return time;
}


void TankGame::updateMovePlayer(){
    player->update(time, *gameMap);
    for (int i = 0; i < enemys.size(); i++){
        if(enemys[i].getBounds().intersects(player->getBounds())){
            enemys.erase(enemys.begin()+i);
            player->playerSetStart();
            player->HP -= 1;
        }
    }
}

void TankGame::updateBullets(){
    if(Keyboard::isKeyPressed(Keyboard::Space) && player->canAttack()){
        bullets.push_back(Bullet(*textures["BULLET"], player->getPlayerX(),player->getPlayerY(),0.7f, player->dir));
    }
    for (int i = 0; i < bullets.size(); i++){
        bullets[i].update(time);
        if (bullets[i].interactionWithMap(*gameMap)){
            bullets.erase(bullets.begin()+i);
        }
    }
    for (int i = 0; i < bulletsEnemy.size(); i++){
        bulletsEnemy[i].update(time);
        if (bulletsEnemy[i].interactionWithMap(*gameMap)){
            bulletsEnemy.erase(bulletsEnemy.begin()+i);
        }

        if(bulletsEnemy[i].getBounds().intersects(player->getBounds())){
            bulletsEnemy.erase(bulletsEnemy.begin()+i);
            player->playerSetStart();
            player->HP -= 1;
        }
    }

}

void TankGame::updateEnemy(){
    if (timerSpawn > 80.f && enemys.size()<14){
        enemys.push_back(Enemy(*textures["ENEMY"], 64*9,64*14,42,46));
        enemys.push_back(Enemy(*textures["ENEMY"], 64*17,64*14,42,46));
        timerSpawn =0;
    }
    for (int i = 0; i < enemys.size(); i++){
        enemys[i].update(time, *gameMap);
        if (enemys[i].canAttack()){
            bulletsEnemy.push_back(Bullet(*textures["BULLETENEMY"], enemys[i].getEnemyX(),enemys[i].getEnemyY(),0.7f, enemys[i].dir));
        }

        for (int j = 0; j < bullets.size(); j++){
            if(bullets[j].getBounds().intersects(enemys[i].getBounds())){
                bullets.erase(bullets.begin()+j);
                enemys.erase(enemys.begin()+i);
                playerScore += 100;

            }
        }
    }
}

void TankGame::restartGame(){
    player->playerSetStart();
    enemys.clear();
    bullets.clear();
    bulletsEnemy.clear();
    initEnemy();
    gameMap->clearMap();
    timerSpawn =0;
    playerScore = 0;
    player->HP = 3;

}

void TankGame::updateGUI()
{
    std::stringstream strScore;
    strScore << "Score: " << playerScore;
    scoreText.setPosition(view.getCenter().x-620, view.getCenter().y-360);
    scoreText.setString(strScore.str());

    std::stringstream strHP;
    strHP << "HP: " << player->HP;
    HPText.setPosition(view.getCenter().x+500, view.getCenter().y-360);
    HPText.setString(strHP.str());
}

void TankGame::render(){
    window->clear();
    gameMap->render(*window);
    player->render(*window);
    for(Enemy i: enemys){
        i.render(*window);
    }
    for(Bullet i: bullets){
        i.render(*window);
    }
    for(Bullet i: bulletsEnemy){
        i.render(*window);
    }

    window->draw(scoreText);
    window->draw(HPText);

    window->display();

}

