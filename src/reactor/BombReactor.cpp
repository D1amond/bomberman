#include "BombReactor.h"

#include "../action/service/BombActionService.h"
#include <src/asset/GameObject.h>
#include <src/asset/GameSprite.h>

using namespace std;
using namespace sf;

BombReactor::BombReactor(kgr::Container& container, shared_ptr<GameObject> gameObject): Reactor(gameObject), _container{container} {}

vector<Event::EventType> BombReactor::getEventTypes()
{
	vector<Event::EventType> eventTypes;
	eventTypes.push_back(Event::EventType::KeyPressed);
	
	return eventTypes;
}

void BombReactor::react(Event event)
{
	if (!_gameObject.expired()) {
		auto object = _gameObject.lock();
		if (event.type == Event::EventType::KeyPressed && !object->hasAction()) {
			if (event.key.code == sf::Keyboard::Space) {
				object->setAction(_container.service<BombActionService>(object, object->getGameSprite()->getSprite()->getPosition()));
			}
		}
	}
}
