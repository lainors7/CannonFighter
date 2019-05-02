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
        sf::Texture Map;
        Map.loadFromFile("resources/HUDcielo.png");
        sf::Sprite sprite(Map);
        window->draw(sprite);
}
