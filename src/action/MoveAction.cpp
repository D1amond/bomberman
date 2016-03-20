#include "MoveAction.h"
#include <src/asset/GameObject.h>
#include <src/asset/GameSprite.h>

using namespace std;
using namespace sf;

MoveAction::MoveAction(weak_ptr<GameObject> gameObject, Vector2f position): Action(gameObject), _position{position} {}

string MoveAction::getType()
{
	return "move";
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
	
	if (_position.x > 0 && _position.y == 0) {
		gameSprite->toggleAnimation("MoveRight");
	} else if (_position.x < 0 && _position.y == 0) {
		gameSprite->toggleAnimation("MoveLeft");
	} if (_position.x == 0 && _position.y > 0) {
		gameSprite->toggleAnimation("MoveDown");
	} if (_position.x == 0 && _position.y < 0) {
		gameSprite->toggleAnimation("MoveUp");
	}
}
