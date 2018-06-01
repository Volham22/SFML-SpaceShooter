#ifndef MENUS_HEADERS
#define MENUS_HEADERS

#include <SFML/Graphics.hpp>
#include <string>
#include "include/Background.h"
#include "include/gameInputs.h"

using namespace sf;

class Menu
{
    public:
        Menu(std::string mainText, std::string secondText, Color mainTextColor, Color secondTextColor);
        void drawMenu(RenderWindow &window);
        bool doMenu(Menu menu, RenderWindow &window);

    private:
        Background MenuBackground;
        Font MainFont;
        Text MainText;
        Text SecondText;
};

#endif