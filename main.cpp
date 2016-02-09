#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "kangaru.h"
#include "src/event/EventManager.h"
#include "src/event/service/EventManagerService.h"
#include "src/level/service/LevelManagerService.h"
#include "src/asset/GameObject.h"
#include "src/asset/service/GameObjectManagerService.h"
#include "src/asset/GameSprite.h"
#include "src/loader/service/GameObjectLoaderService.h"
#include "src/level/Level.h"

using namespace kgr;
using namespace std;

int main(int argc, char **argv) {
	Container container;
	auto &eventManager = container.service<EventManagerService>();
	auto &levelManager = container.service<LevelManagerService>();
	auto &gameObjectManager = container.service<GameObjectManagerService>();
	auto &loader = container.service<GameObjectLoaderService>();
	
	sf::RenderWindow window{sf::VideoMode{480, 480}, "Bomberman"};
	
	auto object = loader.load("hero");
	auto object2 = loader.load("bomb");
	
	levelManager.goTo("level1");

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
				for (shared_ptr<sf::Drawable> drawable : layer.second.getTiles()) {
					window.draw(*drawable);
				}
			}
		}

		for (shared_ptr<GameObject> object : gameObjectManager.getObjects()) {
			if (!object->getGameSprite().expired()) {
				auto gameSprite = object->getGameSprite().lock();
				if (!gameSprite->getSprite().expired()) {
					auto sprite = gameSprite->getSprite().lock();
					window.draw(*sprite);
				}
			}
		}
		
		gameObjectManager.tick();
		
        window.display();
    }

    return 0;
}
