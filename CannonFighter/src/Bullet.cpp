#include "Bullet.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Bullet::Bullet(): currVelocity(0.f,0.f), maxSpeed(15.f)
{
    float radius = 5.f;
    this-> shape.setRadius(radius);
    this-> shape.setFillColor(sf::Color::Red);

}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::draw(sf::RenderWindow *window, bool disparo, sf::Vector2f pos, int &i)
{

    if(i==0)
    {
        //shape.setOrigin(pos);
        shape.setPosition(pos);
        std::cout << "origen de la bala: " << pos.x << "--"<<pos.y<<std::endl;
        i++;
    }
    if(disparo==true && i>0)
    {
        //shape.move({1,0});

        shape.move({x,y});
        std::cout << "bala se mueve" << std::endl;
        window->draw(shape);
        i++;
        if(i==200){
            i=-1;
            disparo=false;
        }
    }





    //std::cout << "Y disparo" << std::endl;

}
