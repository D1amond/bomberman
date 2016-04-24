#include "TickAction.h"

#include "../loader/GameObjectLoader.h"
#include "../asset/GameSprite.h"

using namespace std;
using namespace sf;

TickAction::TickAction(
	GameObjectLoader& gameObjectLoader,
	weak_ptr<GameObject> gameObject,
	Vector2f position
): Action(gameObject), _gameObjectLoader{gameObjectLoader}, _position{position} {}

string TickAction::getType()
{
	return "tick";
}

bool TickAction::execute()
{

}
