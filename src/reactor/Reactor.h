#pragma once

#include "../event/EventListener.h"
#include <memory>
#include "../event/EventManager.h"
#include "../asset/GameObject.h"

struct Reactor : EventListener
{
	Reactor(std::shared_ptr<GameObject> gameObject);
	virtual std::vector<sf::Event::EventType> getEventTypes() = 0;
    virtual void react(sf::Event event) = 0;
protected:
	std::weak_ptr<GameObject> _gameObject;
};
