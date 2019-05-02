#include "Player.h"
#include <iostream>

#define vel 0.2


Player::Player()
{
    //ctor
    int i=0;

    textura = new sf::Texture();
    sprite = new sf::Sprite();


    if(i==1)
    {
        textura->loadFromFile("resources/Player2.png");
    }
    if(i==2)
    {
        textura->loadFromFile("resources/Player3.png");
    }
    if(i==0)
    {
        textura->loadFromFile("resources/Player1.png");
    }

        //sf::Sprite sprite(*textura);
        sprite->setTexture(*textura);
        sprite->setPosition(sf::Vector2f(200,300)); //Horizontal, vertical
        //window->draw(sprite);
}

Player::~Player()
{

    //dtor

}

void Player::mover(int x, int y, Menu *menu)
{
    //mover



    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) /*&& sprite->getGlobalBounds().intersects(menu->getSprite().getGlobalBounds())==true*/)
    {
        //sprite->setScale(-0.1, 0.1);
        sprite->move({-0.3, -2});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) /*&& sprite->getGlobalBounds().intersects(menu->getSprite().getGlobalBounds())==true*/)
    {
        //sprite->setScale(-0.1, 0.1);
        sprite->move({0.3, 2});
    }
}

void Player::draw(sf::RenderWindow *window)
{

    window->draw(*sprite);


    //sprite->setTexture(*textura);
    //sprite->setScale(0.1f, 0.1f);
    //sprite->setOrigin(textura->getSize().x/2, textura->getSize().y/2);

}
