#include "include/Bullet.h"

Bullet::Bullet(Vector2f playerPosition)
{
    VertexArray coords(Triangles, 3);

    /* Corners Positions */
    coords[0].position = Vector2f(playerPosition.x + 25.0, playerPosition.y + 25.0);
    coords[1].position = Vector2f(playerPosition.x + 30.0, playerPosition.y + 30.0);
    coords[2].position = Vector2f(playerPosition.x + 35.0, playerPosition.y + 25.0);

    coords.resize(5);

    /* Set Red Color for Bullets */
    for(unsigned int i = 0; i<2; i++)
        coords[i].color = Color::Red;

    bulletCoords = coords;

    //std::cout << "Bullet initialised !" << std::endl;
}

bool Bullet::updateBullet()
{
    for(unsigned int i = 0; i<2; i++)
    {
        bulletCoords[i] = Vector2f(bulletCoords[i].position.x, bulletCoords[i].position.y - BULLETS_SPEED);

        if(bulletCoords[i].position.y <= 0 || bulletCoords[i].position.y >= 600)
            return true;
    }

    return false;
}

Vector2f Bullet::getPosition() const
{
    return bulletCoords[1].position;
}

void BulletSystem::addBullet(Vector2f playerPosition)
{
    if(BulletCount < BULLETS_MAX_AMOUNT)
    {
        Bullet b(playerPosition);
        BulletContainer.push_back(b);
        BulletCount++;
        //std::cout << "Bullet n° " << BulletCount << " added" << std::endl;
    }
}

void BulletSystem::updateBulletCount()
{
    for(unsigned int i = 0; i<BulletContainer.size(); i++)
    {
        if(BulletContainer[i].updateBullet())
        {
            BulletContainer.erase(BulletContainer.begin() + i);
            BulletCount--;
            //std::cout << "Bullet deleted" << std::endl;
        }
    }
}

void BulletSystem::drawBullets(RenderWindow &window)
{
    for(unsigned int i = 0; i<BulletContainer.size(); i++)
        window.draw(BulletContainer[i]);
}

unsigned int* BulletSystem::getBulletNumber()
{
    return &BulletCount;
}

std::vector<Bullet>* BulletSystem::getList()
{
    return &BulletContainer;
}

void Bullet::draw(RenderTarget &target, RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = NULL;

    target.draw(bulletCoords, states);
}