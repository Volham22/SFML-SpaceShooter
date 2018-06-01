:: Build script for SpaceShooter on Windows with MinGW compiler
:: Include and MinGW paths have to be updated !
:: Objects names : Player.o gameInputs.o Bullet.o Ennemy.o Background.o Score.o deathScreen.o WindowGestio.o Menus.o
:: Note : It's strongly recommended to use cmake instead of this script under Windows
@echo off
echo Cleaning previous Build Files ...
if exist Player.o del Player.o
if exist gameInputs.o del gameInputs.o
if exist Bullet.o del Bullet.o
if exist Ennemy.o del Ennemy.o
if exist Background.o del Background.o
if exist Score.o del Score.o
if exist deathScreen.o del deathScreen.o
if exist WindowGestion.o del WindowGestion.o
if exist Menus.o del Menus.o
if exist Animation.o del Animation.o

echo Building SpaceShooter ...
D:\MinGW\bin\mingw32-g++.exe -c src/Background.cpp src/Bullet.cpp src/deathScreen.cpp src/Ennemy.cpp src/gameInputs.cpp src/main.cpp src/Player.cpp src/Score.cpp src/WindowGestion.cpp src/Menus.cpp src/Animation.cpp -ID:\Documents\Prog\SFML\SFML-2.4.2\include -ID:\Documents\Prog\SFML-SpaceShooter

echo Finishing ...
D:\MinGW\bin\mingw32-g++.exe -LD:\Documents\Prog\SFML\SFML-2.4.2\lib -o SpaceShooter.exe main.o Background.o Bullet.o deathScreen.o Ennemy.o gameInputs.o Player.o Score.o WindowGestion.o Menus.o Animation.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -static-libstdc++ -static-libgcc

echo Done.
Pause