#pragma once

#include "SFML/Graphics.hpp"
#include <memory>

struct EventListener;
struct KeyboardListener;

struct EventManager
{
	void dispatch(sf::Event event);
	void subscribe(sf::Event::EventType type, std::shared_ptr<EventListener> listener);
	void init(std::shared_ptr<KeyboardListener> keyboardListener);
private:
	std::multimap<sf::Event::EventType, std::shared_ptr<EventListener>> listeners;
	
};
