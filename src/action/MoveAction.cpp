#include "MoveAction.h"
#include <src/asset/GameObject.h>
#include <src/asset/GameSprite.h>

using namespace std;
using namespace sf;

MoveAction::MoveAction(weak_ptr<GameObject> gameObject, Vector2f position): Action(gameObject), _position{position}
{
	if (!_gameObject.expired()) {
		auto obj = _gameObject.lock();
		auto gameSprite = obj->getGameSprite();
		auto sprite = gameSprite->getSprite();
		auto diffX = position.x - sprite->getPosition().x;
		auto diffY = position.y - sprite->getPosition().y;
		_initialTime = _timer.getElapsedTime();
		_lastTime = _timer.getElapsedTime();
		
		if (diffX != 0) {
			if (diffX > 0) {
				_direction.first = "right";
				_direction.second = Vector2f{1, 0};
			} else {
				_direction.first = "left";
				_direction.second = Vector2f{-1, 0};
			}
		} else if (diffY != 0) {
			if (diffY > 0) {
				_direction.first = "down";
				_direction.second = Vector2f{0, 1};
			} else {
				_direction.first = "up";
				_direction.second = Vector2f{0, -1};
			}
		}
	}
}

bool MoveAction::execute()
{
	if (!_gameObject.expired()) {
		auto obj = _gameObject.lock();
		auto gameSprite = obj->getGameSprite();
		auto sprite = gameSprite->getSprite();
		auto diffX = _position.x - sprite->getPosition().x;
		auto diffY = _position.y - sprite->getPosition().y;
		Time elapsed = _timer.getElapsedTime();

		/*if (_collisionManager.hasTile(entity.getSprite().getPosition()+(32.f*direction.second))) {
			return false;
		}*/
		
		if (diffX != 0 || diffY != 0) {
			if (((elapsed.asMilliseconds() - _lastTime.asMilliseconds())/10)*10 == 10) {
				sprite->move(_direction.second);
				_lastTime = elapsed;
			}
			
			//fallback
			if (elapsed.asSeconds() - _initialTime.asSeconds() > 1.5) {
				sprite->move(diffX, diffY);
			}
			
			return true;
		} else {
			return false;
		}
	}
	
	return false;
}
