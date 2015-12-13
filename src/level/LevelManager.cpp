#include "LevelManager.h"

#include "Level.h"

#include <iostream>

using namespace std;

LevelManager::LevelManager(LevelLoader& loader) : loader{loader} {}

LevelManager::~LevelManager() = default;


void LevelManager::goTo(string level)
{
	currentLevel = loader.load(level);
}

const bool LevelManager::hasLevel()
{
	return currentLevel != nullptr;
}

const Level& LevelManager::getCurrentLevel()
{
	return *currentLevel;
}
