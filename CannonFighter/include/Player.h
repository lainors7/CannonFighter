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
        void mover();
        void moverflecha();
        void draw(sf::RenderWindow *window, int vidas);
        sf::Vector2f getPos();
        sf::Vector2f getPosF();
        int dmg(int vidas, Bullet *b1);
        sf::Sprite getSprite();

    protected:

    private:
        sf::Texture *textura;
        sf::Sprite *sprite;
        sf::Texture *texturaf;
        sf::Sprite *spritef;
        sf::Texture *texturav;
        sf::Sprite *spritev;
        sf::Texture *texturav2;
        sf::Sprite *spritev2;
        int i=0;
};

#endif // PLAYER_H
