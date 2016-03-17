#include "GameObjectManager.h"
#include "GameSprite.h"
#include <iostream>

using namespace std;

void GameObjectManager::tick()
{
	/*
	 * TODO not copy the list!
	 * Required here because GameObjects can be added to the list while iterating, invalidating iterators.
	 */
	auto objects = _objects;
	
	for (auto&& object : objects) {
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
}

void GameObjectManager::addObject(std::shared_ptr<GameObject> object)
{
	_objects.push_back(object);
}

const vector<shared_ptr<GameObject>>& GameObjectManager::getObjects()
{
	return _objects;
}
