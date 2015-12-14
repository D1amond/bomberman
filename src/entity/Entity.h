#pragma once

#include <SFML/Graphics.hpp>
#include "../collision/Square.h"

struct Entity
{
	Entity();
	void setCharset(sf::Texture charset);
	void setSprite(sf::Sprite sprite);
	void setSquare(Square square);
	sf::Sprite& getSprite();
	Square& getSquare();
private:
	sf::Texture _charset;
	sf::Sprite _sprite;
	Square _square;
};
