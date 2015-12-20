#pragma once

#include <SFML/Graphics.hpp>
#include "Action.h"

struct MoveAction : Action
{
    MoveAction(std::weak_ptr<GameObject> gameObject, sf::Vector2f position);
    bool execute() override;
private:
	sf::Vector2f _position;
	sf::Clock _timer;
	std::pair<std::string, sf::Vector2f> _direction;
	sf::Time _initialTime;
	sf::Time _lastTime;
};
