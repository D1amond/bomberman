#pragma once

#include "../../kangaru.h"
#include "SFML/Graphics.hpp"
#include <memory>

#include "View.h"
#include "../event/EventManager.h"
#include "../entity/HeroManager.h"

struct WindowManager
{
	WindowManager(
		View& view,
		EventManager& eventManager,
		LevelManager& levelManager,
		std::weak_ptr<HeroManager> heroManager
	);
	void run();
private:
	sf::RenderWindow window;
	View& view;
	EventManager& eventManager;
	LevelManager& levelManager;
	std::weak_ptr<HeroManager> heroManager;
};
