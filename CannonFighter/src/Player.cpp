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

    spritef->setTexture(*texturaf);
    spritef->setPosition(sf::Vector2f(210,410));
    spritev->setTexture(*texturav);
    spritev->setPosition(sf::Vector2f(23,410));

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

void Player::shoot(sf::RenderWindow *window, Bullet &b1)
{
    std::cout << "Voy a disparar" << std::endl;

    //std::vector<Bullet> bullets;

    //b1.shape.move({0.2,0});

   // b1.shape.setPosition(sprite->getPosition());

            //bullets[i].shape.move(bullets[i].currVelocity);
            //Para borrar los proyectiles
            /*if(bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().x > window->getSize().x ||
               bullets[i].shape.getPosition().y < 0 || bullets[i].shape.getPosition().y > window->getSize().y )
               {
                bullets.erase(bullets.begin()+i);
               }

            /*if (bullets[i].shape.getGlobalBounds().intersects(enemigo.getGlobalBounds()))
            {
                deleteSprite = true;
            }*/


}

sf::Vector2f Player::getPos()
{
    return sprite->getPosition();
}

void Player::draw(sf::RenderWindow *window)
{

    window->draw(*sprite);
    window->draw(*spritev);
    window->draw(*spritef);


    //sprite->setTexture(*textura);
    //sprite->setScale(0.1f, 0.1f);
    //sprite->setOrigin(textura->getSize().x/2, textura->getSize().y/2);

}
