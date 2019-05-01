#include "Game.h"
#include <vector>
#include <iostream>


Game* Game::pinstance = 0;

Game* Game::Instance(){
    if(pinstance == 0)
        pinstance = new Game;
    return pinstance;
}

Game::Game()
{

    std::cout << "Juego inciado" << std::endl;
    srand(time(0));
    mapa = new Map;

    window = new sf::RenderWindow(sf::VideoMode(650, 520), "Cannon Fighter");
    window->setFramerateLimit(60);
     while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();

            }
        }
        window->clear();
        mapa->Draw(window);
        window->display();
    }
}


Game::~Game()
{
    //dtor
}
