#include "GameObjectManager.h"
#include "GameSprite.h"
#include <iostream>

using namespace std;

void GameObjectManager::tick()
{
	for (auto&& object : _objects) {
		if (object) {
			if (object->hasAction()) {
				auto action = object->getAction();
				if (!action->execute()) {
					object->stopAction();
				}
			}
		}
		if (object) {
			if (object->getGameSprite()) {
				auto animation = object->getGameSprite()->getCurrentAnimation();
				if (animation != nullptr) {
					if (!animation->run()) {
						animation->finalize();
						object->getGameSprite()->stopAnimation();
					}
				}
			}
		}
	}
	
	update();
}

void GameObjectManager::update()
{
	_objects.insert(end(_objects), begin(_newObjects), end(_newObjects));
	_newObjects.clear();
}

void GameObjectManager::addObject(std::shared_ptr<GameObject> object)
{
	_newObjects.push_back(object);
}

const vector<shared_ptr<GameObject>>& GameObjectManager::getObjects()
{
	return _objects;
}
