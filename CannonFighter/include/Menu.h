#ifndef Menu_H
#define Menu_H
#include <SFML/Graphics.hpp>


class Menu
{
    public:
        Menu();
        virtual ~Menu();
        void Draw(sf::RenderWindow*);
        sf::Sprite getSprite();

    protected:

    private:
        sf::Texture *textura;
        sf::Sprite *sprite;
        sf::RenderWindow window;
};

#endif // Menu_H
