#pragma once

#include <vector>
#include <memory>
#include "GameObject.h"

struct GameObjectManager
{
	void tick();
	void addObject(std::shared_ptr<GameObject> object);
	const std::vector<std::shared_ptr<GameObject>>& getObjects();
private:
	void update();
	std::vector<std::shared_ptr<GameObject>> _objects;
	std::vector<std::shared_ptr<GameObject>> _newObjects;
};
