#include "include/Animation.h"

Animation::Animation(Sprite* body, RenderWindow* window)
{
    currentXPosition = 0;
    currentYPosition = 0;

    Body = body;
    Window = window;

    /* Load animation texture and Set first frame as texture */
    t.loadFromFile("resources/explosion.png");
    Body->setTexture(t);
    Body->setTextureRect(IntRect(Vector2i(currentXPosition, currentYPosition), Vector2i(ANIMATION_WIDTH, ANIMATION_HEIGHT)));
}

bool Animation::updateAnimation()
{
    if(currentXPosition >= MAX_X_TEXTURE && currentYPosition >= MAX_Y_TEXTURE)
        return false;

    if(currentXPosition >= MAX_X_TEXTURE)
    {
        currentXPosition = 0;
        currentYPosition++;
        Body->setTextureRect(IntRect(Vector2i(currentXPosition, currentYPosition), Vector2i(ANIMATION_WIDTH, ANIMATION_HEIGHT)));
        Window->draw(*Body);
        
        return true;
    }
    else
    {
        currentXPosition++;
        Body->setTextureRect(IntRect(Vector2i(currentXPosition, currentYPosition), Vector2i(ANIMATION_WIDTH, ANIMATION_HEIGHT)));
        Window->draw(*Body);

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
        if(!Animated[i]->updateAnimation())
        {
            delete(Animated[i]);
            Animated.erase(Animated.begin() + i);
            std::cout << "Animations finished and deleted" << std::endl; 
        }
    }
}

void AnimationGestion::addAnimation(Sprite* body)
{
    Animation* a = new Animation(body, Window);
    Animated.push_back(a);
    std::cout << "Init new Animation" << std::endl;
}