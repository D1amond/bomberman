#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "../collision/CollisionManager.h"

struct Level;

struct LevelLoader
{
	LevelLoader(CollisionManager& collisionManager);
	LevelLoader(LevelLoader&&) = default;
	LevelLoader& operator=(LevelLoader&&) = default;
	~LevelLoader();
	std::unique_ptr<Level> load(std::string name);
private:
	sf::Texture tileset;
	CollisionManager& _collisionManager;
};
