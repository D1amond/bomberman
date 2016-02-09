#pragma once

#include <string>
#include <memory>
#include <map>

#include "src/loader/LevelLoader.h"

struct Level;

struct LevelManager
{
	LevelManager(LevelLoader& loader);
	LevelManager(LevelManager&&) = default;
	LevelManager& operator=(LevelManager&&) = default;
	~LevelManager();
	void goTo(std::string level);
	const Level& getCurrentLevel();
	const bool hasLevel();
private:
	std::unique_ptr<Level> currentLevel;
	std::map<std::string, std::unique_ptr<Level>> loadedLevels;
	LevelLoader& loader;
};
