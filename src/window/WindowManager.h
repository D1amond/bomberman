#pragma once

#include "../../kangaru.h"
#include "SFML/Graphics.hpp"
#include <memory>

struct WindowManager
{
	WindowManager();
	void run();
	void addDrawable(std::shared_ptr<sf::Drawable> drawable);
private:
	std::vector<std::shared_ptr<sf::Drawable>> drawables;
	sf::RenderWindow window;
};
