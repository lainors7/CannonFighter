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
        void draw(sf::RenderWindow *window, bool disparo, sf::Vector2f, int &i);

    protected:

    private:
        int i=0;
        int x=1;
        int y=-1;

};

#endif // BULLET_H
