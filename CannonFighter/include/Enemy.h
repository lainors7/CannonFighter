#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>


class Enemy
{
    public:
        Enemy(int);
        virtual ~Enemy();
        void draw(sf::RenderWindow *window);
        void mover(int x, int y, sf::Clock c);
        float* getPos();
        sf::Sprite getSprite();
    protected:

    private:
        sf::Texture *textura;
        sf::Sprite *sprite;
        float pos[2];
        int vida=0;
        int vel=1;
};

#endif // ENEMY_H
