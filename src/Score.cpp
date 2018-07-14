#include "include/Score.h"

TextScore::TextScore(unsigned int* score)
{
    Score = score;

    t_font.loadFromFile("resources/arial.ttf");

    text.setFont(t_font);
    text.setFillColor(Color::Red);
    text.setString("Killed : 0");

    /* Read best Score from save File */
    std::ifstream saveFile(SAVE_FILE, std::ios::in | std::ios::binary);

    if(saveFile.is_open())
    {
        saveFile.read((char*)&BestScore, sizeof(unsigned int));

        saveFile.close();
    }
    else
    {
        std::cout << "Can't read save file ! Maybe not generated yet?\nNote: A save file will automatically be generated when the player died" << std::endl;
    }
}

void TextScore::updateScore()
{
    if(*Score > BestScore)
        BestScore = *Score;

    text.setString("Killed : " + std::to_string(*Score) + "\nBest Score : " + std::to_string(BestScore));
}

void TextScore::draw(RenderWindow &window)
{
    window.draw(text);
}

void TextScore::saveBestScore()
{
    std::ofstream saveFile(SAVE_FILE, std::ios::out | std::ios::binary);

    saveFile.write((char*)&BestScore, sizeof(unsigned int));

    saveFile.close();
}