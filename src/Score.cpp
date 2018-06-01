#include "include/Score.h"

TextScore::TextScore(unsigned int* score)
{
    Score = score;

    t_font.loadFromFile("resources/arial.ttf");

    text.setFont(t_font);
    text.setColor(Color::Red); // Deprecated declaration with the lastest SFML version
    text.setString("Killed : 0");
}

void TextScore::updateScore()
{
    //std::cout << "Killed : " << toascii(*Score) << std::endl;
    text.setString("Killed : " + std::to_string(*Score));
}

void TextScore::draw(RenderWindow &window)
{
    window.draw(text);
}