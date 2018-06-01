#include "include/Ennemy.h"

#ifndef _WAVES
#define _WAVES
unsigned int _wavesNumber = 0;
#endif

#warning "Animations are NOT WORKING"

int getRandomInt(int max)
{
    // Return an integer between 0 and max int
    return rand() % max;
}

Ennemy::Ennemy()
{
    if(t_Ennemy.loadFromFile("resources/ennemy.png"))
    {
        s_Ennemy.setTexture(t_Ennemy);
    }
    else
    {
        s_Ennemy.setColor(Color::Blue);
        s_Ennemy.setScale(20.0, 20.0);
    }

    s_Ennemy.setPosition(Vector2f(getRandomInt(800), 50.0));
}

void Ennemy::update()
{
    diff.updateDifficulty();
    s_Ennemy.move(0.0, diff.getSpeed());
}

FloatRect Ennemy::getBound()
{
    return s_Ennemy.getGlobalBounds();
}

Vector2f Ennemy::getPosition()
{
    return s_Ennemy.getPosition();
}

void Ennemy::drawEnnemy(RenderWindow &window)
{
    window.draw(s_Ennemy);
}

Sprite* Ennemy::getBody()
{
    return &s_Ennemy;
}

Difficulty::Difficulty()
{
    if(_wavesNumber > 0)
        wavesNbr = _wavesNumber - 1;
    else
        wavesNbr = _wavesNumber;

    currentSpeed += 2;
}

void Difficulty::updateDifficulty()
{
    if(_wavesNumber > wavesNbr)
    {
        wavesNbr++;
        
        if(wavesNbr < 10)
        {
            currentDifficulty++;
            currentSpeed += 0;
            std::cout << "Difficulty now at " << currentDifficulty << std::endl;
        }
        else if(wavesNbr > 10 && wavesNbr < 50)
        {
            currentDifficulty++;
            currentSpeed += 2;
            std::cout << "Difficulty now at " << currentDifficulty << std::endl;
        }
        else
        {
            currentDifficulty++;
            currentSpeed += 5;
            std::cout << "Difficulty now at " << currentDifficulty << std::endl;
        }
    }
}

int Difficulty::getDifficulty()
{
    return currentDifficulty;
}

int Difficulty::getSpeed()
{
    return currentSpeed;
}

EnnemySystem::EnnemySystem(std::vector<Bullet>* bulletsList, unsigned int* bulletCount, RenderWindow *window)
{
    BulletsList = bulletsList;
    p_BulletCount = bulletCount;

    AnimationGestion a(window);
    Animations = a;
}

void EnnemySystem::update(RenderWindow* window)
{
    for(unsigned int i = 0; i<EnnemyList.size(); i++)
    {
        for(unsigned int j = 0; j<BulletsList->size(); j++)
        {
            if(isCollided(EnnemyList[i]->getBound(), (*BulletsList)[j].getPosition()))
            {
                Killed++;
                
                std::cout << "Bullet collision with an ennemy! Deleting Ennemy" << std::endl;
                deleteEnnemy(EnnemyList[i], i, window, Shooted);
                EnnemyNbr = EnnemyList.size();

                BulletsList->erase(BulletsList->begin() + j);
                *p_BulletCount = BulletsList->size();
                std::cout << EnnemyNbr << " left." << std::endl;

                return;
            }
        }
    }

    for(unsigned int i = 0; i<EnnemyList.size(); i++)
    {
        EnnemyList[i]->update();

        if(EnnemyList[i]->getPosition().y >= 600)
        {
            std::cout << "Ennemy out of window !  Deleting" << std::endl;
            deleteEnnemy(EnnemyList[i], i, window, OutOfWindow);
            EnnemyNbr = EnnemyList.size();
            std::cout << EnnemyNbr << " left." << std::endl;
            return;
        }
    }

    if(EnnemyNbr <= 0)
    {
        _wavesNumber++;
        std::cout << "New waves n° " << _wavesNumber << std::endl;
        
        if(_wavesNumber * 2 > ENNEMY_LIMIT)
            createEnnemy(ENNEMY_LIMIT);
        else
            createEnnemy(_wavesNumber * 2);
    }

    Animations.updateAnimation();
}

void EnnemySystem::createEnnemy(unsigned int number)
{
    for(unsigned int i = 0; i<number; i++)
    {
        Ennemy* e = new(Ennemy);
        EnnemyList.push_back(e);
    }
}

void EnnemySystem::deleteEnnemy(Ennemy* e, unsigned int position, RenderWindow* window, killReason reason)
{
    if(reason == OutOfWindow)
    {
        EnnemyList.erase(EnnemyList.begin() + position);
        delete(e);
    }
    else
    {
        Animations.addAnimation(e->getBody());
        EnnemyList.erase(EnnemyList.begin() + position);
    }
}

void EnnemySystem::drawEnnemies(RenderWindow &window)
{
    for(unsigned int i = 0; i<EnnemyList.size(); i++)
    {
        EnnemyList[i]->drawEnnemy(window);
        EnnemyNbr++;
    }
}

int EnnemySystem::getEnnemyNbr()
{
    return EnnemyNbr;
}

bool EnnemySystem::isCollided(FloatRect a, Vector2f b)
{
    if(a.contains(b))
        return true;
    else
        return false;
}

unsigned int* EnnemySystem::getKilledNbr()
{
    return &Killed;
}

std::vector<Ennemy*>* EnnemySystem::getEnnemyList()
{
    return &EnnemyList;
}