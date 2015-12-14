#include "CollisionManager.h"

using namespace std;

void CollisionManager::addTile(Square square)
{
	tiles.push_back(square);
}

bool CollisionManager::hasTile(sf::Vector2f position)
{
	bool has = false;
	for (Square tile : tiles) {
		if (tile.getPosition() == position) {
			has = true;
		}
	}
	return has;
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
