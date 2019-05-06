#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Menu.h"



class Player
{
    public:
        Player();
        virtual ~Player();
        void mover();
        void moverflecha();
        void draw(sf::RenderWindow *window);
        sf::Vector2f getPos();
        sf::Vector2f getPosF();

    protected:

    private:
        sf::Texture *textura;
        sf::Sprite *sprite;
        sf::Texture *texturaf;
        sf::Sprite *spritef;
        sf::Texture *texturav;
        sf::Sprite *spritev;
        int i=0;
};

#endif // PLAYER_H
