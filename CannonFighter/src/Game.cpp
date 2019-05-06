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
    int lvl=0;
    menu = new Menu;
    mapa = new Map;
    jugador = new Player;
    enemigo = new Enemy(lvl);
    bool create=false;
    bool jugar =false;
    sf::Clock clock;
    int i=-1;
    bool eliminado=false;
    sf::Vector2f actualf;


    window = new sf::RenderWindow(sf::VideoMode(650, 520), "Cannon Fighter");
    window->setFramerateLimit(60);


    std::cout <<"asdfasdfasdf" << std::endl;

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

                        case sf::Keyboard::F1:
                            std::cout<< "LVL2" <<std::endl;
                            enemigo = new Enemy(1);
                            jugar=true;
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
            if(disparo==false)
            {

                b1 = new Bullet(create);
                std::cout <<"Bala creada" << std::endl;
                create=true;

            }
            else
            {
                create=false;
                //std::cout <<"Bala no creada" << std::endl;
            }

            window->clear();
            jugador->mover();
            jugador->moverflecha();

            if(eliminado==false)
                enemigo->mover(0,0, clock);

            mapa->Draw(window);
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                //jugador->shoot(window, *b1);
                disparo=true;
                i=0;
                actualf = jugador->getPosF();

            }

            jugador->draw(window);
            if(eliminado==false && jugador->getPosF()!= b1->getSprite().getPosition())
            {
                //std::cout <<eliminado << std::endl;
                if(enemigo->getSprite().getGlobalBounds().intersects((b1->getSprite().getGlobalBounds())) && disparo==true )
                {
                    enemigo->~Enemy();
                    b1->~Bullet();
                    eliminado=true;
                    std::cout <<"Bala eliminadda" << std::endl;
                    std::cout <<eliminado << std::endl;
                    disparo=false;
                    i=-1;
                }
                else
                {
                    enemigo->draw(window);
                    b1->draw(window, disparo, jugador->getPos(), actualf, i);
                    i++;
                }
            }
            else
            {
                b1->draw(window, disparo, jugador->getPos(), actualf, i);
                i++;
            }



            window->display();
           if(jugador->getPosF()== b1->getSprite().getPosition())
            {
                disparo=false;
                i=-1;
                b1->~Bullet();
            }
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
