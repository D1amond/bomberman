#pragma once

#include "../entity/Entity.h"
#include <SFML/Graphics.hpp>

struct EntityLoader
{
	EntityLoader();
	EntityLoader(EntityLoader&&) = default;
	EntityLoader& operator=(EntityLoader&&) = default;
	~EntityLoader();
	Entity load(std::string name);
private:
	std::map<std::string, Entity> _entities;
	sf::Texture tileset;
};
