#include "HeroManager.h"

#include <iostream>

using namespace std;
using namespace sf;

HeroManager::HeroManager() : charset{}, hero{} {}

void HeroManager::init()
{
	if (charset.loadFromFile("res/texture/hero/hero.png")) {
		position.x = 32.f;
		position.y = 32.f;
		hero.setTexture(charset);
		
		hero.setTextureRect(sf::IntRect(0, 0, 32, 32));
		
		hero.setPosition(position);
	}
}

const Sprite& HeroManager::getSprite()
{
	return hero;
}

void HeroManager::react(Event event)
{
	if (event.type == Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
			position.y += 1*movefactor;
		}
		if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
			position.y -= 1*movefactor;
		}
		if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
			position.x += 1*movefactor;
		}
		if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) {
			position.x -= 1*movefactor;
		}
		hero.setPosition(position);
	}

}
