#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>


class Bullet
{
    public:
        Bullet();
        virtual ~Bullet();
        sf::CircleShape shape;
        sf::Vector2f currVelocity;
        float maxSpeed;
        void draw(sf::RenderWindow *window, bool disparo);

    protected:

    private:

};

#endif // BULLET_H
