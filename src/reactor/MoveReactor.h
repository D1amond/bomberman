#pragma once

#include <SFML/Graphics.hpp>
#include "Reactor.h"

#include "../entity/Entity.h"
#include "../collision/CollisionManager.h"

struct MoveReactor : Reactor
{
	~MoveReactor();
	MoveReactor(CollisionManager& collisionManager, Entity& entity, sf::Vector2f position);
	bool tick() override;
	void finalize() override;
private:
	void animate(sf::Time elapsed);
	Entity& entity;
	CollisionManager& _collisionManager;
	sf::Vector2f position;
	sf::Clock timer;
	std::pair<std::string, sf::Vector2f> direction;
	sf::Time initialTime;
	sf::Time lastTime;
	sf::Time animationTime;
	int animationCounter{0};
};
