#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Menu.h"


class Player
{
    public:
        Player();
        virtual ~Player();
        void mover(int x, int y, Menu *menu);
        void draw(sf::RenderWindow *window);

    protected:

    private:
        sf::Texture *textura;
        sf::Sprite *sprite;
        int i=0;
        Menu menu;
};

#endif // PLAYER_H
