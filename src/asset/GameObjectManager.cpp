#include "GameObjectManager.h"
#include "GameSprite.h"

using namespace std;

void GameObjectManager::tick()
{
	for (std::shared_ptr<GameObject> object : _objects) {
		if (!object->getAction().expired()) {
			auto action = object->getAction().lock();
			if (!action->execute()) {
				object->stopAction();
			}
		}
		if (!object->getGameSprite().expired()) {
			auto gameSprite = object->getGameSprite().lock();
			if (!gameSprite->getCurrentAnimation().expired()) {
				auto animation = gameSprite->getCurrentAnimation().lock();
				if (animation != nullptr) {
					if (!animation->run()) {
						animation->finalize();
						gameSprite->stopAnimation();
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

const vector< shared_ptr< GameObject > >& GameObjectManager::getObjects()
{
	return _objects;
}
