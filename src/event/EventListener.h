#pragma once

#include <SFML/Graphics.hpp>

struct EventListener
{
	virtual void react(sf::Event event) = 0;
};
