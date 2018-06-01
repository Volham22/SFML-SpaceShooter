#include "include/menu/WindowGestion.h"

WindowGestion::WindowGestion(RenderWindow &startMenu, RenderWindow &game)
{   
    StartMenu = &startMenu;
    Game = &game;

    StartMenu->setFramerateLimit(60);
    
    Game->setFramerateLimit(60);
    Game->setVisible(false); // This window isn't show fisrt
    Game->setActive(false); // So inactive too
}

bool WindowGestion::Show(WindowType type)
{
    switch(type)
    {
        case StartWindow:
        {
            Game->setVisible(false);
            Game->setActive(false);

            StartMenu->setVisible(true);
            StartMenu->setActive(true);

            Menu menu("Welcome to SpaceShooter", "Press Enter to play \nEscape to quit.", Color::Green, Color::White);

            if(menu.doMenu(menu, *StartMenu))
                return true;
            else
                return false;
        }

        case PlayWindow:
        {
            StartMenu->setVisible(false);
            StartMenu->setActive(false);

            Game->setVisible(true);
            Game->setActive(true);

            return true;
        }
    }
}

RenderWindow* WindowGestion::getWindow(WindowType type)
{
    switch(type)
    {
        case StartWindow:
            return StartMenu;

        case PlayWindow:
            return Game;
    }
}

WindowGestion::~WindowGestion()
{
    if(StartMenu->isOpen())
    {
        StartMenu->close();
        StartMenu->~RenderWindow();
    }
    else
    {
        StartMenu->~RenderWindow();
    }

    if(Game->isOpen())
    {
        Game->close();
        Game->~RenderWindow();
    }
    else
    {
        Game->~RenderWindow();
    }
}