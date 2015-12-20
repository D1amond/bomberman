#include "GameObject.h"

#include "GameSprite.h"
#include "../reactor/Reactor.h"

using namespace std;
using namespace sf;

GameObject::GameObject(string type, shared_ptr<GameSprite> gameSprite) : _type{type}, _gameSprite{gameSprite} {}

void GameObject::addReactor(shared_ptr<Reactor> reactor)
{
	_reactors.push_back(reactor);
}

weak_ptr< GameSprite > GameObject::getGameSprite()
{
	return _gameSprite;
}

const string GameObject::getType()
{
	return _type;
}

const bool GameObject::hasAction()
{
	return _action != nullptr;
}

void GameObject::stopAction()
{
	_action = nullptr;
}

weak_ptr<Action> GameObject::getAction()
{
	return _action;
}

void GameObject::setAction(shared_ptr< Action > action)
{
	_action = action;
}
