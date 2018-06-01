#ifndef HEADERS_BULLETS
#define HEADERS_BULLETS

#define BULLETS_SPEED 25
#define BULLETS_MAX_AMOUNT 1000

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>

using namespace sf;

class Bullet : public Drawable, public Transformable
{
    public:
        Bullet(Vector2f playerPosition);
        bool updateBullet();
        //~Bullet();
        virtual Vector2f getPosition() const;

    private:
        VertexArray bulletCoords;

        virtual void draw(RenderTarget &target, RenderStates states) const;
};

class BulletSystem
{
    public:
        //BulletSystem();
        void addBullet(Vector2f playerPosition);
        void updateBulletCount();
        void drawBullets(RenderWindow &window);
        unsigned int* getBulletNumber();
        std::vector<Bullet>* getList();

    private:
        std::vector<Bullet> BulletContainer;
        unsigned int BulletCount = 0;
};

#endif