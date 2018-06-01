#ifndef HEADERS_WINDOWGESTION
#define HEADERS_WINDOWGESTION

#include <SFML/Graphics.hpp>
#include <iostream>
#include "include/menu/Menus.h"

using namespace sf;

enum WindowType 
{
    StartWindow,
    PlayWindow
};

class WindowGestion
{
    public:
        WindowGestion(RenderWindow &startMenu, RenderWindow &game);
        bool Show(WindowType type);
        RenderWindow* getWindow(WindowType type);
        ~WindowGestion();

    private:
        RenderWindow *StartMenu = NULL;
        RenderWindow *Game = NULL;
};

#endif