#include "include/deathScreen.h"

void isDead(FloatRect playerBound, std::vector<Ennemy*>* EnnemyList, RenderWindow &window)
{
    for(unsigned int i = 0; i<EnnemyList->size(); i++)
    {
        if(playerBound.intersects((*EnnemyList)[i]->getBound()))
        {
            Font f;
            f.loadFromFile("resources/arial.ttf");

            Text t;
            t.setFont(f);
            t.setPosition(200.0, 300.0);
            t.setCharacterSize(30);
            t.setFillColor(Color::Red);
            t.setString("YOU DIED !   Press Enter to continue ...");

            keysPressed k = isKeyPressed();

            while(!k.returnKey)
            {
                window.clear(Color::Black);
                window.draw(t);
                window.display();

                k = isKeyPressed();
            }

            /* Destroy Ennemy pointors */
            
            for(unsigned int i = 0; i<EnnemyList->size(); i++)
                delete((*EnnemyList)[i]);

            window.close();
        }
    }

}