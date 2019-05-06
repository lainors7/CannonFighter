#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define vel 0.2


Player::Player()
{
    //ctor
    int i=0;

    textura = new sf::Texture();
    sprite = new sf::Sprite();

    texturaf = new sf::Texture();
    spritef = new sf::Sprite();

    texturav = new sf::Texture();
    spritev = new sf::Sprite();

    texturav2 = new sf::Texture();
    spritev2 = new sf::Sprite();


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
    texturaf->loadFromFile("resources/flechita.png");
    texturav->loadFromFile("resources/vidas.png");
    texturav2->loadFromFile("resources/vidas.png");

    spritef->setTexture(*texturaf);
    spritef->setPosition(sf::Vector2f(230,410));
    spritev->setTexture(*texturav);
    spritev->setPosition(sf::Vector2f(23,410));
    spritev2->setTexture(*texturav);
    spritev2->setPosition(sf::Vector2f(46,410));

    //sf::Sprite sprite(*textura);
    sprite->setTexture(*textura);
    sprite->setPosition(sf::Vector2f(200,300)); //Horizontal, vertical
    //window->draw(sprite);
}

Player::~Player()
{

    //dtor

}

void Player::mover()
{
    //mover
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sprite->getPosition().y>=150)
    {
        //sprite->setScale(-0.1, 0.1);
        sprite->move({-0.2, -2});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sprite->getPosition().y<=355)
    {
        //sprite->setScale(-0.1, 0.1);
        sprite->move({0.2, 2});
    }
}

void Player::moverflecha()
{
    //mover
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && spritef->getPosition().x<=625)
    {
        //sprite->setScale(-0.1, 0.1);
        spritef->move({2,0 });
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && spritef->getPosition().x>=210)
    {
        //sprite->setScale(-0.1, 0.1);
        spritef->move({-2, 0 });
    }
}


sf::Vector2f Player::getPos()
{
    return sprite->getPosition();
}

sf::Vector2f Player::getPosF()
{
    return spritef->getPosition();
}

void Player::draw(sf::RenderWindow *window, int vidas)
{


        window->draw(*sprite);
        if(vidas==0)
        {
             window->draw(*spritev);
        }

        if(vidas==1)
        {
             window->draw(*spritev);
        }

        if(vidas==2)
        {
            window->draw(*spritev);
            window->draw(*spritev2);
        }


    window->draw(*spritef);


    //sprite->setTexture(*textura);
    //sprite->setScale(0.1f, 0.1f);
    //sprite->setOrigin(textura->getSize().x/2, textura->getSize().y/2);

}

sf::Sprite Player::getSprite()
{
    return *sprite;
}

int Player::dmg(int vidas, Bullet *b1)
{
    if(b1->getSprite().getGlobalBounds().intersects((sprite->getGlobalBounds())) && vidas>0)
    {
        vidas--;
    }
    else
    {
        delete this;
    }
}
