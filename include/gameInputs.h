#ifndef HEADERS_GAME_INPUT
#define HEADERS_GAME_INPUT

#include <SFML/Graphics.hpp>

struct keysPressed
{
    bool leftArrow = false;
    bool rightArrow = false;
    bool spaceBar = false;
    bool returnKey = false;
    bool escKey = false;
};

keysPressed isKeyPressed();


#endif