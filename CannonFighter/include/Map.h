#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>


class Map
{
    public:
        Map();
        virtual ~Map();
        void Draw(sf::RenderWindow*);

    protected:

    private:
        sf::RenderWindow window;
};

#endif // MAP_H
