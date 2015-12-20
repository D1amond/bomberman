#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "kangaru.h"
#include "src/event/EventManager.h"
#include "src/event/service/EventManagerService.h"
#include "src/asset/GameObject.h"
#include "src/asset/service/GameObjectManagerService.h"
#include "src/asset/GameSprite.h"
#include "src/loader/service/GameObjectLoaderService.h"

using namespace kgr;
using namespace std;

int main(int argc, char **argv) {
	Container container;
	auto eventManager = container.service<EventManagerService>();
	auto gameObjectManager = container.service<GameObjectManagerService>();
	auto loader = container.service<GameObjectLoaderService>();
	
	sf::RenderWindow window{sf::VideoMode{480, 480}, "Bomberman"};
	
	auto _object = loader.load("hero");
	//gameObjectManager.addObject(_object);
	while (window.isOpen())
    {
		auto _eventManager = container.service<EventManagerService>();
		auto _gameObjectManager = container.service<GameObjectManagerService>();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			else
				_eventManager.dispatch(event);
        }

        window.clear();

		for (shared_ptr<GameObject> object : _gameObjectManager.getObjects()) {
			if (!object->getGameSprite().expired()) {
				auto gameSprite = object->getGameSprite().lock();
				if (!gameSprite->getSprite().expired()) {
					auto sprite = gameSprite->getSprite().lock();
					window.draw(*sprite);
				}
			}
		}
		
		_gameObjectManager.tick();
		
        window.display();
    }

    return 0;
}
