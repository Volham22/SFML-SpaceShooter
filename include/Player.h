#ifndef HEADERS_PLAYER
#define HEADERS_PLAYER

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace sf;

struct outOfWindow
{
    bool isLeft = false;
    bool isRight  = false;
};

class Player
{
    public:
        Player(int maxspeed);
        void moveLeft();
        void moveRight();
        void drawPlayer(RenderWindow &window);
        void updateSpeed();
        Vector2f getPosition();
        FloatRect getBound();

    private:
        float currentSpeed = 0.0f;
        int maxSpeed;
        Sprite s_player;
        Texture t_player;
        Clock clockSpeed;
        const Time speedDecrease = milliseconds(10);

        outOfWindow isOutOfWindow();
};

#endif