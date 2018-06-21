#include <SFML/Graphics.hpp>
#include <iostream>
#include "include/Player.h"
#include "include/gameInputs.h"
#include "include/Bullet.h"
#include "include/Ennemy.h"
#include "include/Background.h"
#include "include/Score.h"
#include "include/menu/Menus.h"
#include "include/menu/WindowGestion.h"

using namespace sf;

int main()
{
    RenderWindow menu(VideoMode(800, 600), "Space Shooter -> Menu");
    RenderWindow death(VideoMode(800, 600), "Space Shooter -> You died !");
    RenderWindow app(VideoMode(800, 600), "Space Shooter");
    WindowGestion windows(menu, app, death);

    if(!windows.Show(StartWindow))
    {
        windows.~WindowGestion();
        return 0;
    }
    else
    {
        windows.Show(PlayWindow);
    }

    Player player(30);

    BulletSystem bullets;
    EnnemySystem ennemy(bullets.getList(), bullets.getBulletNumber(), &app);

    Background background;
    TextScore score(ennemy.getKilledNbr());


    while(app.isOpen())
    {

        Event ev;

        while(app.pollEvent(ev))
        {
            if(ev.type == sf::Event::Closed)
                app.close();
        }

        /* Control check */
        keysPressed keys = isKeyPressed();

        if(keys.leftArrow)
            player.moveLeft();
        else if(keys.rightArrow)
            player.moveRight();
        else if(keys.spaceBar)
            bullets.addBullet(player.getPosition());

        /* Game updates */
        player.updateSpeed();
        bullets.updateBulletCount();
        ennemy.update(&app);
        score.updateScore();

        /* Drawing */
        app.clear(Color::Transparent);
        app.draw(background);
        player.drawPlayer(app);
        bullets.drawBullets(app);
        score.draw(app);
        ennemy.drawEnnemies(app);
        app.display();

        /* Checking if player is dead
         * And react according to the user's choice
         */
        #warning Not the best way to close
        if(player.isDead(ennemy.getEnnemyList()))
        {
            windows.Show(DeathScreenWindow);
            return 0;
        }
    }
}