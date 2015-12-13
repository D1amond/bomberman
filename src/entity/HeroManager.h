#pragma once

#include <SFML/Graphics.hpp>
#include "../event/EventListener.h"

struct HeroManager : EventListener
{
	HeroManager();
	const sf::Sprite& getSprite();
	void react(sf::Event event) override;
	void init();
private:
	sf::Texture charset;
	sf::Sprite hero;
	sf::Vector2f position;
	const float movefactor{32.f};
};
