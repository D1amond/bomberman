#pragma once

#include "Square.h"

struct CollisionManager
{
	bool collides(Square& square);
	bool hasTile(sf::Vector2f position);
	void addTile(Square square);
private:
	std::vector<Square> tiles;
};
