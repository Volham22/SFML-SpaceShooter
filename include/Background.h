#ifndef HEADERS_BACKGROUND
#define HEADERS_BACKGROUND

#include <SFML/Graphics.hpp>

#define WIDTH 600.0
#define HEIGHT 800.0

using namespace sf;

class Background : public Drawable
{
    public:
        Background();
    
    private:
        VertexArray coords;
        Texture texture;

        virtual void draw(RenderTarget &target, RenderStates states) const;
};

#endif