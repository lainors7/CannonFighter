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

void Map::DrawHUD(sf::RenderWindow *window)
{
        sf::Texture Map;

        Map.loadFromFile("resources/HUDcielo.png");
        sf::Sprite sprite(Map);
        window->draw(sprite);

}
void Map::DrawFondo(sf::RenderWindow *window)
{
    sf::Texture Jugable;
    Jugable.loadFromFile("resources/fondo1.png");
    sf::Sprite sprite2(Jugable);
    sprite2.setPosition(sf::Vector2f(-2085,130));

    window->draw(sprite2);
}
