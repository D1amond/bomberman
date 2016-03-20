#include "MoveReactor.h"

#include <src/asset/GameObject.h>
#include <src/asset/GameSprite.h>
#include <src/action/MoveAction.h>
#include <iostream>

using namespace std;
using namespace sf;

MoveReactor::MoveReactor(shared_ptr<GameObject> gameObject): Reactor(gameObject) {}

vector<Event::EventType> MoveReactor::getEventTypes()
{
	vector<Event::EventType> eventTypes;
	eventTypes.push_back(Event::EventType::KeyPressed);
	eventTypes.push_back(Event::EventType::KeyReleased);
	
	return eventTypes;
}

void MoveReactor::react(Event event)
{
	if (!_gameObject.expired()) {
		auto object = _gameObject.lock();
		if (event.type == Event::EventType::KeyPressed && !object->hasAction()) {
			keyPressed(object, event);
		} else if (event.type == Event::EventType::KeyReleased && object->hasAction() && object->getAction()->getType() == "move") {
			keyReleased(object, event);
		}
	}
}

void MoveReactor::keyPressed(shared_ptr<GameObject> object, Event event)
{
	Vector2f destination;
	
	float factor = 0.006;
	
	if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
		destination.y = 1*factor;
	}
	if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
		destination.y = -1*factor;
	}
	if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
		destination.x = 1*factor;
	}
	if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) {
		destination.x = -1*factor;
	}
	if (destination.x != 0 || destination.y != 0) {
		auto action = make_shared<MoveAction>(object, destination);
		object->setAction(action);
	}
}

void MoveReactor::keyReleased(shared_ptr<GameObject> object, Event event)
{
	object->stopAction();
	if (object->getGameSprite()->getCurrentAnimation()) {
		object->getGameSprite()->stopAnimation();
	}
}
