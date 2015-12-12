#pragma once

#include "../../kangaru.h"
#include "SFML/Graphics.hpp"
#include <memory>

#include "View.h"

struct WindowManager
{
	WindowManager(View& view);
	void run();
private:
	sf::RenderWindow window;
	View& view;
};
