#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"


class Game
{
    public:
        Game();
        virtual ~Game();
        static Game* Instance();
        void update();
    protected:

    private:

        static Game* pinstance;
        sf::RenderWindow *window;
        Menu *menu;
        Map *mapa;
        Player *jugador;
        Enemy *enemigo;
        std::vector<Enemy> ejercito;
        Bullet *b1;
        bool jugar =false;
        bool disparo=false;
};

#endif // GAME_H
