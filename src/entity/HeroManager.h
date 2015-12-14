#pragma once

#include <SFML/Graphics.hpp>
#include "../event/EventListener.h"

#include "../reactor/Reactor.h"

struct HeroManager : EventListener
{
	HeroManager();
	const sf::Sprite& getSprite();
	void react(sf::Event event) override;
	void tick();
	void init();
private:
	sf::Texture charset;
	sf::Sprite hero;
	std::unique_ptr<Reactor> reactor{nullptr};
	const float movefactor{32.f};
};
