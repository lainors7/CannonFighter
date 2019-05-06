#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>


class Bullet
{
    public:
        Bullet(bool create);
        virtual ~Bullet();
        sf::CircleShape shape;
        sf::Vector2f currVelocity;
        float maxSpeed;
        void draw(sf::RenderWindow *window, bool disparo, sf::Vector2f, sf::Vector2f, int i);
        void drawEnemy(sf::RenderWindow *window, bool disparo, sf::Vector2f, sf::Vector2f, int i);
        sf::Sprite getSprite();

    protected:

    private:
        int i=0;
        int x=4;
        int y=0;
        sf::Texture *textura;
        sf::Sprite *sprite;

};

#endif // BULLET_H
