#include "Bullet.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Bullet::Bullet(): currVelocity(0.f,0.f), maxSpeed(15.f)
{
    float radius = 5.f;

    textura = new sf::Texture();
    sprite = new sf::Sprite();

    textura->loadFromFile("resources/bullet.png");
    sprite->setTexture(*textura);


}

Bullet::~Bullet()
{
    //dtor
    delete textura;
    delete sprite;
}

sf::Sprite Bullet::getSprite()
{
    return *sprite;
}

void Bullet::draw(sf::RenderWindow *window, bool disparo, sf::Vector2f pos, int &i)
{

    if(i==0)
    {
        //shape.setOrigin(pos);
        sprite->setPosition(pos);
        std::cout << "origen de la bala: " << pos.x << "--"<<pos.y<<std::endl;
        i++;
    }
    if(disparo==true && i>0)
    {
        //shape.move({1,0});

        sprite->move({x,y});
        std::cout << "bala se mueve" << std::endl;
        window->draw(*sprite);
        i++;
        if(i==50){
            i=-1;
            disparo=false;
        }
    }





    //std::cout << "Y disparo" << std::endl;

}
