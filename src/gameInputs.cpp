#include "include/gameInputs.h"

keysPressed isKeyPressed()
{
    keysPressed keys;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        keys.rightArrow = true;
        return keys;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        keys.leftArrow = true;
        return keys;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        keys.spaceBar = true;
        return keys;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        keys.returnKey = true;
        return keys;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        keys.escKey = true;
        return keys;
    }
}