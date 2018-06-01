#ifndef HEADERS_DEATHSCREEN
#define HEADERS_DEATHSCREEN

#include <vector>
#include <SFML/Graphics.hpp>
#include "include/gameInputs.h"
#include "include/Ennemy.h"

using namespace sf;

void isDead(FloatRect playerBound, std::vector<Ennemy*>* EnnemyList, RenderWindow &window);

#endif