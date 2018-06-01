#include "include/menu/Menus.h"

Menu::Menu(std::string mainText, std::string secondText, Color mainTextColor, Color secondTextColor)
{
    /* Setting Up Texts and Fonts */
    MainFont.loadFromFile("resources/arial.ttf");

    MainText.setFont(MainFont);
    MainText.setFillColor(mainTextColor);
    MainText.setCharacterSize(40);
    MainText.setPosition(150.0, 150.0);
    MainText.setString(mainText);

    SecondText.setFont(MainFont);
    SecondText.setFillColor(secondTextColor);
    SecondText.setCharacterSize(30);
    SecondText.setPosition(270.0, 220.0);
    SecondText.setString(secondText);
}

void Menu::drawMenu(RenderWindow &window)
{
    window.draw(MenuBackground);
    window.draw(MainText);
    window.draw(SecondText);
}

bool Menu::doMenu(Menu menu, RenderWindow &window)
{
    keysPressed k = isKeyPressed();

    while(!k.escKey && !k.returnKey)
    {
        Event e;
        window.pollEvent(e);

        if(e.type == Event::Closed)
        {
            window.close();
            break;
        }

        /* Draw menu */
        window.clear(Color::Transparent);
        menu.drawMenu(window);
        window.display();

        k = isKeyPressed();
    }

    if(k.returnKey)
        return true;
    else
        return false;
}