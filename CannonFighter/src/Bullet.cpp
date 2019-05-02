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

void Bullet::draw(sf::RenderWindow *window, bool disparo)
{
    int i=0;
    if(i==0)
    {
        //shape.setOrigin();
    }
    if(disparo==true)
    {
        shape.move({1,0});
    }
    window->draw(shape);
    std::cout << "Y disparo" << std::endl;

}
