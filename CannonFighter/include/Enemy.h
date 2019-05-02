#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>


class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();
        void draw(sf::RenderWindow *window);
        void mover(int x, int y, sf::Clock c);
        float* getPos();
    protected:

    private:
        sf::Texture *textura;
        sf::Sprite *sprite;
        float pos[2];
};

#endif // ENEMY_H
