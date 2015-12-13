#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

struct Layer
{
	void addTile(std::shared_ptr<sf::Sprite> tile);
	const std::vector<std::shared_ptr<sf::Sprite>>& getTiles();
private:
	std::vector<std::shared_ptr<sf::Sprite>> tiles;
};
