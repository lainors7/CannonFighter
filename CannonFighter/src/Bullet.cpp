#include "Bullet.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Bullet::Bullet(bool create): currVelocity(0.f,0.f), maxSpeed(15.f)
{

        float radius = 5.f;

        textura = new sf::Texture();
        sprite = new sf::Sprite();

        textura->loadFromFile("resources/bullet.png");
        sprite->setTexture(*textura);
        //sprite->setPosition({-500, -500});


       // std::cout << "Hay bala" << std::endl;

}

Bullet::~Bullet()
{
    //dtor
    //delete textura;
    delete sprite;
}

sf::Sprite Bullet::getSprite()
{
    return *sprite;
}

void Bullet::draw(sf::RenderWindow *window, bool disparo, sf::Vector2f pos, sf::Vector2f f, int i)
{

    if(i==0)
    {
        //shape.setOrigin(pos);
        sprite->setPosition(pos);
        //std::cout << "origen de la bala: " << pos.x << "--"<<pos.y<<std::endl;
        i++;
    }
    if(disparo==true && i>0)
    {
        //shape.move({1,0});
        if(sprite->getPosition().x<=f.x)
        {
            sprite->move({x * c.getElapsedTime().asMilliseconds(), y});
        //std::cout << "bala se mueve" << std::endl;
            window->draw(*sprite);
        }

    }
    c.restart();
    //std::cout << "Y disparo" << std::endl;

}

void Bullet::drawEnemy(sf::RenderWindow *window, bool disparo, sf::Vector2f pos, sf::Vector2f f, int i)
{
    int r= rand()%(0-2);
    if(i==0 && r==1)
    {
        //shape.setOrigin(pos);
        sprite->setPosition(pos);
        //std::cout << "origen de la bala: " << pos.x << "--"<<pos.y<<std::endl;
        i++;
    }
    if(i>0)
    {
        //shape.move({1,0});
        if(sprite->getPosition().x>=f.x)
        {
            sprite->move({-5,0});
            //std::cout << "bala se mueve" << std::endl;
            window->draw(*sprite);
        }


    }
    //std::cout << "Y disparo" << std::endl;

}
