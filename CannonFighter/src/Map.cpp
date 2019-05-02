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
        sf::Texture Jugable;
        Jugable.loadFromFile("resources/fondo1.png");
        Map.loadFromFile("resources/HUDcielo.png");
        sf::Sprite sprite(Map);
        sf::Sprite sprite2(Jugable);
        sprite2.setPosition(sf::Vector2f(-2085,130));

        window->draw(sprite2);
        window->draw(sprite);

}
