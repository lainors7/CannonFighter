#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Bullet.h"


class Player
{
    public:
        Player();
        virtual ~Player();
        void mover(int x, int y, Menu *menu);
        void draw(sf::RenderWindow *window);
        void shoot(sf::RenderWindow *window, Bullet &);
        sf::Vector2f getPos();

    protected:

    private:
        sf::Texture *textura;
        sf::Sprite *sprite;
        sf::Texture *texturaf;
        sf::Sprite *spritef;
        sf::Texture *texturav;
        sf::Sprite *spritev;
        int i=0;
        Menu menu;
        Bullet b1;
};

#endif // PLAYER_H
