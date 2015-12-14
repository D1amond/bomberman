#include "CollisionManager.h"

using namespace std;

void CollisionManager::addTile(Square square)
{
	tiles.push_back(square);
}

bool CollisionManager::collides(Square& square)
{
	bool collides = false;
	for (Square tile : tiles) {
		if (tile.collides(square)) {
			collides = true;
		}
	}
	return collides;
}
