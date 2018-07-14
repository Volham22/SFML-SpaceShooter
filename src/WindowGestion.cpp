#include "include/menu/WindowGestion.h"

WindowGestion::WindowGestion(RenderWindow &startMenu, RenderWindow &game, RenderWindow &deathWindow)
{
    StartMenu = &startMenu;
    Game = &game;
    DeathWindow = &deathWindow;

    StartMenu->setFramerateLimit(60);
    
    Game->setFramerateLimit(60);
    Game->setVisible(false); // This window isn't show fisrt
    Game->setActive(false); // So inactive too

    DeathWindow->setFramerateLimit(60);
    DeathWindow->setVisible(false); // Same thing for the Death Window
    DeathWindow->setActive(false);
}

bool WindowGestion::Show(WindowType type)
{
    switch(type)
    {
        case StartWindow:
        {
            Game->setVisible(false);
            Game->setActive(false);

            DeathWindow->setVisible(false);
            DeathWindow->setActive(false);

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

            DeathWindow->setVisible(false);
            DeathWindow->setActive(false);

            Game->setVisible(true);
            Game->setActive(true);

            return true;
        }

        case DeathScreenWindow:
        {
            Game->setVisible(false);
            Game->setActive(false);

            DeathWindow->setVisible(true);
            DeathWindow->setActive(true);

            Menu menu("You died !", "Press Enter to play again \nEscape to quit.", Color::Green, Color::White);

            if(menu.doMenu(menu, *DeathWindow))
                return true;
            else
                return false;
        }

        default:
            return true;
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
        
        case DeathScreenWindow:
            return DeathWindow;

        default:
            return NULL;
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

    if(DeathWindow->isOpen())
    {
        DeathWindow->close();
        DeathWindow->~RenderWindow();
    }
    else
    {
        DeathWindow->~RenderWindow();
    }
}