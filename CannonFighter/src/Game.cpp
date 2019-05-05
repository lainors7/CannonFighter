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

    std::cout << "Juego Lanzado al Menu" << std::endl;
    srand(time(0));
    menu = new Menu;
    mapa = new Map;
    jugador = new Player;
    enemigo = new Enemy;
    b1 = new Bullet;
    bool jugar =false;
    sf::Clock clock;
    int i=-1;
    bool eliminado=false;


    window = new sf::RenderWindow(sf::VideoMode(650, 520), "Cannon Fighter");
    window->setFramerateLimit(60);
     while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window->close();
                    break;

                case sf::Event::KeyReleased:

                    switch (event.key.code)
                    {
                        case sf::Keyboard::Space:

                            //JUGAMOS
                            jugar=true;
                            break;
                        case sf::Keyboard::Escape:
                            std::cout<< "Menú" <<std::endl;
                            jugar=false;
                            break;
                    }

                    break;
                default:

                    break;

            }
        }
        if(jugar)
        {
            //std::cout << "Inicicamos Juego" << std::endl;
            window->clear();
            jugador->mover(0,0, menu);
            jugador->moverflecha();
            if(eliminado==false)
                enemigo->mover(0,0, clock);

            mapa->Draw(window);
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                //jugador->shoot(window, *b1);
                disparo=true;
                i=0;

            }

            jugador->draw(window);
            if(eliminado==false)
            {
                if(enemigo->getSprite().getGlobalBounds().intersects((b1->getSprite().getGlobalBounds())))
                {
                    enemigo->~Enemy();
                    b1->~Bullet();
                    eliminado=true;
                }
                else
                {
                    enemigo->draw(window);
                    b1->draw(window, disparo, jugador->getPos(), i);
                }
            }


            window->display();
        }
        else
        {
            window->clear();
            menu->Draw(window);
            window->display();
        }



    }
}


Game::~Game()
{
    //dtor
}
