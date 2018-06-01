#ifndef HEADERS_ANIMATION
#define HEADERS_ANIMATION

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#define MAX_X_TEXTURE 4
#define MAX_Y_TEXTURE 4
#define ANIMATION_WIDTH 10
#define ANIMATION_HEIGHT 10

using namespace sf;

class Animation
{
    public:
        Animation(Sprite* body, RenderWindow* window);
        bool updateAnimation();
        int getPosition();
        //~Animation();

    private:
        Sprite* Body = nullptr;
        RenderWindow* Window = nullptr;
        Texture t;
        unsigned int currentXPosition;
        unsigned int currentYPosition;
};

class AnimationGestion
{
    public:
        AnimationGestion(RenderWindow *window = nullptr);
        void updateAnimation();
        void addAnimation(Sprite* body);

    private:
        std::vector<Animation*> Animated;
        RenderWindow *Window = nullptr;
};

#endif