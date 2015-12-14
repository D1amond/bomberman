#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "kangaru.h"
#include "../event/EventListener.h"

#include "../reactor/Reactor.h"
#include "Entity.h"

struct HeroManager : EventListener
{
	HeroManager(kgr::Container& container);
	const sf::Sprite& getSprite();
	void react(sf::Event event) override;
	void tick();
	void init();
private:
	kgr::Container& _container;
	sf::Texture charset;
	Entity hero;
	std::unique_ptr<Reactor> reactor{nullptr};
	const float movefactor{32.f};
};
