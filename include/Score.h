#ifndef HEADER_SCORE
#define HEADER_SCORE

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;

class TextScore
{
    public:
        TextScore(unsigned int* score);
        void updateScore();
        void draw(RenderWindow &window);
    
    private:
        unsigned int* Score = nullptr;
        Font t_font;
        Text text;
};

#endif