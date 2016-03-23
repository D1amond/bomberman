#include "MoveReactor.h"

#include <src/asset/GameObject.h>
#include <src/asset/GameSprite.h>
#include <src/action/MoveAction.h>
#include <iostream>

using namespace std;
using namespace sf;

MoveReactor::MoveReactor(shared_ptr<GameObject> gameObject): Reactor(gameObject), _lastAction{nullptr} {
	float factor = 0.006;
	
	_positions.emplace(sf::Keyboard::Down, Vector2f{0, 1*factor});
	_positions.emplace(sf::Keyboard::S, Vector2f{0, 1*factor});
	_positions.emplace(sf::Keyboard::Up, Vector2f{0, -1*factor});
	_positions.emplace(sf::Keyboard::W, Vector2f{0, -1*factor});
	_positions.emplace(sf::Keyboard::Right, Vector2f{1*factor, 0});
	_positions.emplace(sf::Keyboard::D, Vector2f{1*factor, 0});
	_positions.emplace(sf::Keyboard::Left, Vector2f{-1*factor, 0});
	_positions.emplace(sf::Keyboard::A, Vector2f{-1*factor, 0});
	
	_directions.emplace(sf::Keyboard::Down, "down");
	_directions.emplace(sf::Keyboard::S, "down");
	_directions.emplace(sf::Keyboard::Up, "up");
	_directions.emplace(sf::Keyboard::W, "up");
	_directions.emplace(sf::Keyboard::Right, "right");
	_directions.emplace(sf::Keyboard::D, "right");
	_directions.emplace(sf::Keyboard::Left, "left");
	_directions.emplace(sf::Keyboard::A, "left");
	
}

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
		if (_directions.find(event.key.code) != _directions.end()) {
			if (event.type == Event::EventType::KeyPressed && (!object->hasAction() || object->getAction()->getType() == "move")) {
				keyPressed(object, event.key.code);
			} else if (event.type == Event::EventType::KeyReleased && object->hasAction() && object->getAction()->getType() == "move") {
				keyReleased(object, event.key.code);
			}
		}
	}
}

void MoveReactor::keyPressed(shared_ptr<GameObject> object, Keyboard::Key key)
{
	Vector2f position = _positions.at(key);
	string direction = _directions.at(key);
	
	if (!_lastAction || _lastAction->getDirection() != direction) {
			
		_keysPressed.push_back(key);
		auto action = make_shared<MoveAction>(object, position, direction);
		object->setAction(action);
		_lastAction = action;
	}
}

void MoveReactor::keyReleased(shared_ptr<GameObject> object, Keyboard::Key key)
{
	string direction = _directions.at(key);
	_keysPressed.erase(remove(_keysPressed.begin(), _keysPressed.end(), key), _keysPressed.end());
	
	if (_keysPressed.size() == 0) {
		object->stopAction();
		if (object->getGameSprite()->getCurrentAnimation()) {
			object->getGameSprite()->stopAnimation();
		}
		_lastAction = nullptr;
	} else {
		keyPressed(object, _keysPressed.back());
	}
}
