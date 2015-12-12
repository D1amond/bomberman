#pragma once

#include "SFML/Graphics.hpp"

struct EventManager
{
	void dispatch(sf::Event event);
};
