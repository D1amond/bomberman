#pragma once

#include <SFML/Graphics.hpp>

struct EventListener
{
	virtual ~EventListener() = default;
	virtual void react(sf::Event event) = 0;
};
