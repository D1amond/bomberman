#include "Layer.h"

void Layer::addTile(std::shared_ptr<sf::Sprite> tile)
{
	tiles.emplace_back(tile);
}

const std::vector<std::shared_ptr<sf::Sprite>>& Layer::getTiles()
{
	return tiles;
}
