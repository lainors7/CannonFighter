#ifndef Map_H
#define Map_H
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

#endif // Map_H
