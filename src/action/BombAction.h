#pragma once

#include "Action.h"
#include <SFML/Graphics.hpp>

struct GameObjectLoader;

struct BombAction : Action
{
	BombAction(GameObjectLoader& gameObjectLoader, std::weak_ptr<GameObject> gameObject, sf::Vector2f position);
	std::string getType() override;
	bool execute() override;
	
private:
	GameObjectLoader& _gameObjectLoader;
	sf::Vector2f _position;
};
