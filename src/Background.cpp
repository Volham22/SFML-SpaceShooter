#include "include/Background.h"

Background::Background()
{
    /* Set Background Position according to the window size (800, 600) */
    VertexArray arr(Quads, 4);

    arr[0].position = Vector2f(0.0, WIDTH);
    arr[1].position = Vector2f(0.0, 0.0);
    arr[2].position = Vector2f(HEIGHT, 0.0);
    arr[3].position = Vector2f(HEIGHT, WIDTH);

    arr[0].texCoords = Vector2f(0.0, WIDTH);
    arr[1].texCoords = Vector2f(0.0, 0.0);
    arr[2].texCoords = Vector2f(HEIGHT, 0.0);
    arr[3].texCoords = Vector2f(HEIGHT, WIDTH);

    coords = arr;

    if(!texture.loadFromFile("resources/background.jpg"))
        std::cout << "Unable to load background Textures." << std::endl;
}

void Background::draw(RenderTarget &target, RenderStates states) const
{
    //states.transform = NULL;
    states.texture = &texture;

    target.draw(coords, states);
}