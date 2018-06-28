#ifndef HEADER_SCORE
#define HEADER_SCORE

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>

#define SAVE_FILE "SpaceShooter.sav"

using namespace sf;

class TextScore
{
    public:
        TextScore(unsigned int* score);
        void updateScore();
        void saveBestScore();
        void draw(RenderWindow &window);
    
    private:
        unsigned int* Score = nullptr;
        unsigned int BestScore = 0;
        Font t_font;
        Text text;
};

#endif