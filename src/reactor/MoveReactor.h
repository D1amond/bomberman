#pragma once

#include <SFML/Graphics.hpp>
#include "Reactor.h"

struct MoveReactor : Reactor
{
	~MoveReactor();
	MoveReactor(sf::Sprite& sprite, sf::Vector2f position);
	bool tick() override;
	void finalize() override;
private:
	void animate(sf::Time elapsed);
	sf::Sprite& sprite;
	sf::Vector2f position;
	sf::Clock timer;
	std::pair<std::string, sf::Vector2f> direction;
	sf::Time initialTime;
	sf::Time lastTime;
	sf::Time animationTime;
	int animationCounter{0};
};
