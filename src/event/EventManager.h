#pragma once

#include "SFML/Graphics.hpp"
#include <memory>

#include "../entity/HeroManager.h"

struct EventListener;
struct KeyboardListener;

struct EventManager
{
	void dispatch(sf::Event event);
	void subscribe(sf::Event::EventType type, std::shared_ptr<EventListener> listener);
	void init(std::shared_ptr<KeyboardListener> keyboardListener, std::shared_ptr<HeroManager> heroManager);
private:
	std::multimap<sf::Event::EventType, std::shared_ptr<EventListener>> listeners;
	
};
