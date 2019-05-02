#include "Enemy.h"


Enemy::Enemy()
{

    //ctor
    int i=0;

    textura = new sf::Texture();
    sprite = new sf::Sprite();


    if(i==1)
    {
        textura->loadFromFile("resources/Tanque1.png");
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
         //Horizontal, vertical
        //window->draw(sprite);

}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::draw(sf::RenderWindow *window, sf::Vector2f pos)
{

    sprite->setPosition(pos);
    window->draw(*sprite);


    //sprite->setTexture(*textura);
    //sprite->setScale(0.1f, 0.1f);
    //sprite->setOrigin(textura->getSize().x/2, textura->getSize().y/2);

}
