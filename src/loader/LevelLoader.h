#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

struct Level;

struct LevelLoader
{
	LevelLoader() = default;
	LevelLoader(LevelLoader&&) = default;
	LevelLoader& operator=(LevelLoader&&) = default;
	~LevelLoader();
	std::unique_ptr<Level> load(std::string name);
private:
	sf::Texture tileset;
};
