#pragma once

#include "Square.h"

struct CollisionManager
{
	bool collides(Square& square);
	void addTile(Square square);
private:
	std::vector<Square> tiles;
};
