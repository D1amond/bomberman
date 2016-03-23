#include "MoveAction.h"
#include <src/asset/GameObject.h>
#include <src/asset/GameSprite.h>

using namespace std;
using namespace sf;

MoveAction::MoveAction(weak_ptr<GameObject> gameObject, Vector2f position, string direction): Action(gameObject), _position{position}, _direction{direction} {}

string MoveAction::getType()
{
	return "move";
}

string MoveAction::getDirection()
{
	return _direction;
}

bool MoveAction::execute()
{
	if (!_gameObject.expired()) {
		auto obj = _gameObject.lock();
		auto gameSprite = obj->getGameSprite();
		auto sprite = gameSprite->getSprite();
		
		sprite->move(_position);
		animate(obj);
		
		return true;
	}
	
	return false;
}

void MoveAction::animate(shared_ptr<GameObject> object)
{
	auto gameSprite = object->getGameSprite();
	
	if (_direction == "right") {
		gameSprite->toggleAnimation("MoveRight");
	} else if (_direction == "left") {
		gameSprite->toggleAnimation("MoveLeft");
	} if (_direction == "down") {
		gameSprite->toggleAnimation("MoveDown");
	} if (_direction == "up") {
		gameSprite->toggleAnimation("MoveUp");
	}
}
