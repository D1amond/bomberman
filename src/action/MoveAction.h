#pragma once

#include <SFML/Graphics.hpp>
#include "Action.h"

struct MoveAction : Action
{
    MoveAction(std::weak_ptr<GameObject> gameObject, sf::Vector2f position, std::string direction);
	std::string getType() override;
    bool execute() override;
	std::string getDirection();
private:
	void animate(std::shared_ptr<GameObject> object);
	sf::Vector2f _position;
	std::string _direction;
};
