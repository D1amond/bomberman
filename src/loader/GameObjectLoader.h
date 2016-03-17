#pragma once

#include "kangaru.h"
#include "../event/EventManager.h"
#include <src/asset/GameObjectManager.h>
#include <memory>

struct GameObject;

struct GameObjectLoader
{
	GameObjectLoader(EventManager& eventManager, GameObjectManager& objectManager, kgr::Container& container);
	std::shared_ptr<GameObject> load(std::string type);
private:
	EventManager& _eventManager;
	GameObjectManager& _objectManager;
	kgr::Container& _container;
};
