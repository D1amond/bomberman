#pragma once

#include "../../kangaru.h"
#include "SFML/Graphics.hpp"
#include <memory>

#include "View.h"
#include "../event/EventManager.h"

struct WindowManager
{
	WindowManager(View& view, EventManager& eventManager);
	void run();
private:
	sf::RenderWindow window;
	View& view;
	EventManager& eventManager;
};
