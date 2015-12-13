#include "WindowManager.h"
#include <src/level/Level.h>

#include <iostream>

using namespace kgr;
using sf::Drawable;
using namespace std;

WindowManager::WindowManager(
	View& view,
	EventManager& eventManager,
	LevelManager& levelManager,
	std::weak_ptr<HeroManager> heroManager
) : window{
	sf::VideoMode{480, 480}, "Bomberman"},
	view{view},
	eventManager{eventManager},
	levelManager{levelManager},
	heroManager{heroManager} {}

void WindowManager::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			else
				eventManager.dispatch(event);
        }

        window.clear();

		if (levelManager.hasLevel()) {
			for (auto layer : levelManager.getCurrentLevel().getLayers()) {
				for (shared_ptr<Drawable> drawable : layer.second.getTiles()) {
					window.draw(*drawable);
				}
			}
		}
		
		if (!heroManager.expired()) {
			window.draw(heroManager.lock()->getSprite());
		}
		
		for (shared_ptr<Drawable> drawable : view.getDrawables()) {
			window.draw(*drawable);
		}
		
        window.display();
    }
}
