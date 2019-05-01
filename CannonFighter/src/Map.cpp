#include "Map.h"
#include <SFML/Graphics.hpp>

Map::Map()
{
    //ctor

}

Map::~Map()
{
    //dtor
}

void Map::Draw(sf::RenderWindow *window)
{
    sf::Texture map;
    map.loadFromFile("resources/MenuInicio.png");
    sf::Sprite sprite(map);
    window->draw(sprite);
}

