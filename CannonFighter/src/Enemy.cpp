#include "Enemy.h"
#include <iostream>


Enemy::Enemy()
{

    //ctor
    int i=0;

    textura = new sf::Texture();
    sprite = new sf::Sprite();


    if(i==1)
    {
        textura->loadFromFile("resources/Tanque2.png");
    }
    if(i==2)
    {
        textura->loadFromFile("resources/Tanque3.png");
    }
    if(i==0)
    {
        textura->loadFromFile("resources/Tanque1.png");
    }
        //sf::Sprite sprite(*textura);
        sprite->setTexture(*textura);
        sprite->setPosition(sf::Vector2f(560,140));
         //Horizontal, vertical
        //window->draw(sprite);

}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::mover(int x, int y, sf::Clock c)
{
    sf::Time time = c.getElapsedTime();

    sprite->move(sf::Vector2f{-0.2 , 0});

}

void Enemy::draw(sf::RenderWindow *window)
{

    //sprite->setPosition(pos);
    window->draw(*sprite);


    //sprite->setTexture(*textura);
    //sprite->setScale(0.1f, 0.1f);
    //sprite->setOrigin(textura->getSize().x/2, textura->getSize().y/2);

}

float *Enemy::getPos()
{
    pos[0] = sprite->getPosition().x;
    pos[1] = sprite->getPosition().y;
    return pos;
}
