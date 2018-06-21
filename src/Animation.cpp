#include "include/Animation.h"

Animation::Animation(Sprite* body, RenderWindow* window)
{
    currentXPosition = 0;
    currentYPosition = 0;

    States = 0;

    Body = body;
    Window = window;

    /* Load animation texture and Set first frame as texture */
    t.loadFromFile("resources/explosion.png");
    Body->setTexture(t);
    Body->setTextureRect(IntRect(currentXPosition, currentYPosition, ANIMATION_WIDTH, ANIMATION_HEIGHT));
}

void Animation::drawAnimation()
{
    Window->draw(*Body);
}

bool Animation::updateAnimation()
{
    if(currentXPosition >= MAX_X_TEXTURE && currentYPosition >= MAX_Y_TEXTURE)
        return false; // The animations is done

    /* 
     * Select the right part of the texture and apply it to the Sprite 
     * Check the animation delay before change it
     */
    if(AnimClock.getElapsedTime() >= AnimDelay)
    {
        if(currentXPosition >= MAX_X_TEXTURE)
        {
            AnimClock.restart();

            currentXPosition = 0;
            currentYPosition++;
            Body->setTextureRect(IntRect(currentXPosition * ANIMATION_WIDTH, currentYPosition * ANIMATION_HEIGHT, ANIMATION_HEIGHT, ANIMATION_WIDTH));
            
            return true;
        }
        else
        {
            AnimClock.restart();

            currentXPosition++;
            Body->setTextureRect(IntRect(currentXPosition * ANIMATION_WIDTH, currentYPosition * ANIMATION_HEIGHT, ANIMATION_HEIGHT, ANIMATION_WIDTH));

            return true;
        }
    }
    else
    {
        return true;
    }
}

AnimationGestion::AnimationGestion(RenderWindow *window)
{
    Window = window;
}

void AnimationGestion::updateAnimation()
{
    for(int i = 0; i<Animated.size(); i++)
    {
        /* If the Animation is done, free the memory */
        if(!Animated[i]->updateAnimation())
        {
            delete(Animated[i]);
            Animated.erase(Animated.begin() + i);
        }
    }
}

void AnimationGestion::addAnimation(Sprite* body)
{
    /* Initialisation of a new Animations */
    Animation* a = new Animation(body, Window);
    Animated.push_back(a);
}

void AnimationGestion::drawAnimations()
{
    /* Drawing Animations */
    for(unsigned int i = 0; i< Animated.size(); i++)
        Animated[i]->drawAnimation();
}

void AnimationGestion::clearAnimation()
{
    Animated.clear();
}