#ifndef HEADERS_WINDOWGESTION
#define HEADERS_WINDOWGESTION

#include <SFML/Graphics.hpp>
#include <iostream>
#include "include/menu/Menus.h"

using namespace sf;

enum WindowType 
{
    StartWindow,
    PlayWindow,
    DeathScreenWindow
};

class WindowGestion
{
    public:
        WindowGestion(RenderWindow &startMenu, RenderWindow &game, RenderWindow &deathWindow);
        bool Show(WindowType type);
        RenderWindow* getWindow(WindowType type);
        ~WindowGestion();

    private:
        RenderWindow *StartMenu = nullptr;
        RenderWindow *Game = nullptr;
        RenderWindow *DeathWindow = nullptr;
};

#endif