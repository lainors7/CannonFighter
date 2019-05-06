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
    //enemigo = new Enemy(lvl);
    enemypos.y=140;
    enemypos.x=560;



    bool create = false;
    bool jugar = false;
    int i =-1;
    bool eliminado = false;
    sf::Vector2f actualf;
    int vidas = 2;
    for (int e=0; e<5; e++)
    {

        ejercito.push_back(new Enemy(lvl, enemypos));
        enemypos.x = enemypos.x + rand()%(-10-100);
        enemypos.y = enemypos.y + 50;
        balas.push_back(new Bullet(true));
        b.push_back(0);
        //c.push_back(sf::Clock);

    }



    window = new sf::RenderWindow(sf::VideoMode(650, 520), "Cannon Fighter");
    window->setFramerateLimit(60);
    std::cout <<balas.size()<< std::endl;

    std::cout <<"asdfasdfasdf"<< std::endl;

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
                            jugar = true;
                            break;
                        case sf::Keyboard::Q:
                            std::cout<< "Menú" <<std::endl;
                            jugar = false;
                            break;

                        case sf::Keyboard::F1:
                            std::cout<< "LVL2" <<std::endl;
                            lvl=2;
                            ejercito.clear();
                            balas.clear();
                            enemypos.y=140;
                            enemypos.x=560;
                            for (int e=0; e<5; e++)
                            {
                                ejercito.push_back(new Enemy(lvl, enemypos));
                                enemypos.x = enemypos.x + rand()%(-10-100);
                                enemypos.y = enemypos.y + 50;
                                std::cout<< "Creando enemigos" << std::endl;
                                balas.push_back(new Bullet(true));
                            }
                            jugar = true;
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
            if(disparo == false)
            {

                b1 = new Bullet(create);
                //std::cout <<"Bala creada" << std::endl;
                create = true;

            }
            else
            {
                create=false;
                //std::cout <<"Bala no creada" << std::endl;
            }

            window->clear();
            jugador->mover();
            jugador->moverflecha();

            if(eliminado == false)
                 mapa->DrawFondo(window);

                    for(int e1=0; e1<ejercito.size(); e1++)
                    {

                        ejercito.at(e1)->mover(0,0, clock);

                           //std::cout<<"enemigo va a disparar"<<std::endl;
                        if(balas.size() > e1 && b.size()>e1)
                        {

                                balas.at(e1)->drawEnemy(window, disparo,
                                                        ejercito.at(e1)->getSprite().getPosition(),
                                                        jugador->getPos(),b.at(e1));
                                //std::cout<<"enemigo ha disparado"<<std::endl;
                                b.at(e1)++;
                        }

                    }





            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && clock.getElapsedTime().asSeconds()>=2)
            {
                //jugador->shoot(window, *b1);
                disparo=true;
                i=0;
                actualf = jugador->getPosF();
                clock.restart();
            }

            for(int b3=0; b3<balas.size(); b3++)
            {

                if(jugador->getSprite().getGlobalBounds().intersects((balas.at(b3)->getSprite().getGlobalBounds())))
                {
                    std::cout<<"pene"<<std::endl;
                    vidas--;
                    delete balas.at(b3);
                    balas.erase(balas.begin()+b3);
                    b.at(b3)=0;

                        if(vidas<=0)
                        {
                            delete jugador;
                            balas.clear();
                            ejercito.clear();
                            window->close();
                        }

                }
                else if (b.at(b3)>0 && balas.at(b3)->getSprite().getPosition().x<=jugador->getSprite().getPosition().x)
                {
                    std::cout<<"pene2"<<std::endl;
                    delete balas.at(b3);
                    balas.erase(balas.begin()+b3);
                    b.at(b3)=0;
                }

            }


            if(jugador->getPosF()!= b1->getSprite().getPosition() && ejercito.size()>0)
            {
                for(int e2=0; e2<ejercito.size(); e2++)
                {
                    if(ejercito.at(e2)->getSprite().getGlobalBounds().intersects((b1->getSprite().getGlobalBounds())) && disparo==true)
                    {
                        delete ejercito.at(e2);
                        ejercito.erase(ejercito.begin()+e2);
                        b1->~Bullet();
                        //eliminado=true;
                        //std::cout <<"Bala eliminadda" << std::endl;
                        //std::cout <<eliminado << std::endl;
                        disparo=false;
                        i=-1;

                    }
                    else
                    {
                        ejercito.at(e2)->draw(window);
                        b1->draw(window, disparo, jugador->getPos(), actualf, i);
                        i++;
                    }
                }
                //std::cout <<eliminado << std::endl;

            }
            else
            {
                b1->draw(window, disparo, jugador->getPos(), actualf, i);
                i++;
            }

            mapa->DrawHUD(window);
            jugador->draw(window, vidas);
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
