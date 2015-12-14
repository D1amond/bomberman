#pragma once

#include <SFML/Graphics.hpp>

struct Square
{
	Square(sf::Vector2f position, float height, float length);
	bool collides(Square& square);
	const sf::Vector2f getPosition();
	const float getHeight();
	const float getLength();
private:
	sf::Vector2f position;
	float height;
	float length;
};
