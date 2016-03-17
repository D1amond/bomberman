#pragma once

#include "Reactor.h"
#include "kangaru.h"

struct BombReactor : Reactor
{
	BombReactor(kgr::Container& container, std::shared_ptr<GameObject> gameObject);
	std::vector<sf::Event::EventType> getEventTypes() override;
	void react(sf::Event event) override;
	
private:
	kgr::Container& _container;
};
