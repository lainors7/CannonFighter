#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>


class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();
        void draw(sf::RenderWindow *window, sf::Vector2f pos);

    protected:

    private:
        sf::Texture *textura;
        sf::Sprite *sprite;
};

#endif // ENEMY_H
