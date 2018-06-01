#include "include/Player.h"

Player::Player(int maxspeed)
{
    maxSpeed = maxspeed;

    s_player.setPosition(600.0f, 550.0f);

    t_player.loadFromFile("resources/player.png");
    s_player.setTexture(t_player);
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
    //std::cout << "Current speed : " << currentSpeed << " of max " << maxSpeed << std::endl;

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