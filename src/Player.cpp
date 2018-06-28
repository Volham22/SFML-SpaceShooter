#include "include/Player.h"

Player::Player(int maxspeed)
{
    maxSpeed = maxspeed;

    s_player.setPosition(600.0f, 550.0f);

    if(t_player.loadFromFile("resources/player.png"))
    {
        s_player.setTexture(t_player);
    }
    else
    {
        std::cout << "Can't load player textures, using default values." << std::endl;

        s_player.setColor(Color::Yellow);
        s_player.setScale(50.0f, 50.0f);
    }
}

void Player::moveLeft()
{
    outOfWindow limits = isOutOfWindow();
    if(!limits.isLeft)
    {
        if(currentSpeed == 0 || currentSpeed < maxSpeed)
            currentSpeed++;

        s_player.move(currentSpeed - 2 * currentSpeed, 0.0f);
    }
}

void Player::moveRight()
{
    outOfWindow limits = isOutOfWindow();

    if(!limits.isRight)
    {
        if(currentSpeed == 0 || currentSpeed < maxSpeed)
            currentSpeed++;
        
        s_player.move(currentSpeed, 0.0f);
    }  
}

void Player::drawPlayer(RenderWindow &window)
{
    window.draw(s_player);
}

void Player::updateSpeed()
{
    if(clockSpeed.getElapsedTime() >= speedDecrease && currentSpeed > 0)
    {
        currentSpeed -= 0.5f;
        clockSpeed.restart();
    }
}

outOfWindow Player::isOutOfWindow()
{
    outOfWindow limits;

    if(s_player.getPosition().x >=780.0f || s_player.getPosition().x <= 0.0f)
    {
        if(s_player.getPosition().x >=780.0f)
        {
            s_player.setPosition(780.0f, s_player.getPosition().y);
            limits.isRight = true;
            return limits;
        }
        else if(s_player.getPosition().x <= 0.0f)
        {
            s_player.setPosition(0.0f, s_player.getPosition().y);
            limits.isLeft = true;
            return limits;
        }
    }
    else
        return limits;
}

Vector2f Player::getPosition()
{
    return Vector2f(s_player.getPosition().x, s_player.getPosition().y);
}

FloatRect Player::getBound()
{
    return s_player.getGlobalBounds();
}

bool Player::isDead(std::vector<Ennemy*>* ennemyList)
{
    for(int i = 0; i<ennemyList->size(); i++)
    {
        if((*ennemyList)[i]->getBound().intersects(s_player.getGlobalBounds()))
        {
            delete((*ennemyList)[i]);
            
            return true;
        }
        else
        {
            return false;
        }
    }
}