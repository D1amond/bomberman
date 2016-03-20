#include "BombAction.h"

#include "../loader/GameObjectLoader.h"
#include "../asset/GameSprite.h"

using namespace std;
using namespace sf;

BombAction::BombAction(
	GameObjectLoader& gameObjectLoader,
	weak_ptr<GameObject> gameObject,
	Vector2f position
): Action(gameObject), _gameObjectLoader{gameObjectLoader}, _position{position} {}

string BombAction::getType()
{
	return "bomb";
}

bool BombAction::execute()
{
	auto bomb = _gameObjectLoader.load("bomb");
	bomb->getGameSprite()->getSprite()->setPosition(_position);
	
	return false;
}
