#ifndef HEADERS_ANIMATION
#define HEADERS_ANIMATION

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <time.h>

#define MAX_X_TEXTURE 4
#define MAX_Y_TEXTURE 4
#define ANIMATION_WIDTH 64
#define ANIMATION_HEIGHT 64


using namespace sf;

class Animation
{
    public:
        Animation(Sprite* body, RenderWindow* window);
        void drawAnimation();
        bool updateAnimation();
        bool isChanged();
        int getPosition();
        //~Animation();

    private:
        Clock AnimClock;
        Sprite* Body = nullptr;
        RenderWindow* Window = nullptr;
        Texture t;
        unsigned int currentXPosition;
        unsigned int currentYPosition;
        unsigned int States;
        const Time AnimDelay = milliseconds(50); // Animation delay
};

class AnimationGestion
{
    public:
        AnimationGestion(RenderWindow *window = nullptr);
        void updateAnimation();
        void addAnimation(Sprite* body);
        void drawAnimations();

    private:
        std::vector<Animation*> Animated;
        RenderWindow *Window = nullptr;

};

#endif