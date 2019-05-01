#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"


class Game
{
    public:
        Game();
        virtual ~Game();
        static Game* Instance();

    protected:

    private:

        static Game* pinstance;
        sf::RenderWindow *window;
        Map *mapa;
};

#endif // GAME_H
