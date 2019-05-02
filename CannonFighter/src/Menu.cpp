#include "Menu.h"
#include <SFML/Graphics.hpp>

Menu::Menu()
{
    //ctor
    textura = new sf::Texture();
    sprite = new sf::Sprite();
    textura->loadFromFile("resources/MenuInicio.png");
    sprite->setTexture(*textura);


}

Menu::~Menu()
{
    //dtor
}

void Menu::Draw(sf::RenderWindow *window)
{
    window->draw(*sprite);


}

sf::Sprite Menu::getSprite()
{
    return *sprite;
}
