#ifndef HEADERS_ENNEMY
#define HEADERS_ENNEMY

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include "include/Bullet.h"
#include "include/Animation.h"

#define ENNEMY_LIMIT 10

using namespace sf;


int getRandomInt(int max);
enum killReason {OutOfWindow, Shooted};

class Difficulty
{
    public:
        Difficulty();
        void updateDifficulty();
        void drawEnnemies(RenderWindow &window);
        int getDifficulty();
        int getSpeed();

    private:
        unsigned int wavesNbr = 0;
        unsigned int currentDifficulty = 0;
        unsigned int currentSpeed = 0;
};

class Ennemy
{
    public:
        Ennemy();
        void update();
        void drawEnnemy(RenderWindow &window);
        Sprite* getBody();

        FloatRect getBound();
        Vector2f getPosition();

    private:
        Difficulty diff;
        Texture t_Ennemy;
        Sprite s_Ennemy;

};

class EnnemySystem
{
    public:
        EnnemySystem(std::vector<Bullet>* bulletsList, unsigned int* bulletCount, RenderWindow *window);
        void update(RenderWindow* window);
        int getEnnemyNbr();
        void drawEnnemies(RenderWindow &window);
        unsigned int* getKilledNbr();
        std::vector<Ennemy*>* getEnnemyList();

    private:
        bool isCollided(FloatRect a, Vector2f b);
        void createEnnemy(unsigned int number);
        void deleteEnnemy(Ennemy* e, unsigned int position, RenderWindow* window, killReason reason);

        std::vector<Ennemy*> EnnemyList;
        std::vector<Bullet>* BulletsList = nullptr;
        AnimationGestion Animations;
        unsigned int* p_BulletCount = nullptr;
        int EnnemyNbr = 0;
        unsigned int Killed = 0;

};

#endif