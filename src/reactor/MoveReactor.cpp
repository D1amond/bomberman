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
	
	return eventTypes;
}

void MoveReactor::react(Event event)
{
	if (!_gameObject.expired()) {
		auto object = _gameObject.lock();
		if (event.type == Event::EventType::KeyPressed && !object->hasAction()) {
			if (!object->getGameSprite().expired()) {
				auto gameSprite = object->getGameSprite().lock();
				if (!gameSprite->getSprite().expired()) {
					auto sprite = gameSprite->getSprite().lock();
					Vector2f destination;
					if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
						destination.y = 32;
						gameSprite->toggleAnimation("MoveDown");
					}
					if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
						destination.y = -32;
						gameSprite->toggleAnimation("MoveUp");
					}
					if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
						destination.x = 32;
						gameSprite->toggleAnimation("MoveRight");
					}
					if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) {
						destination.x = -32;
						gameSprite->toggleAnimation("MoveLeft");
					}
					destination += sprite->getPosition();
					
					auto action = make_shared<MoveAction>(object, destination);
					object->setAction(action);
				}
			}
		}
	}
}
