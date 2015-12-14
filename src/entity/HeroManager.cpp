#include "HeroManager.h"

#include <iostream>
#include "../reactor/MoveReactor.h"

using namespace std;
using namespace sf;

HeroManager::HeroManager() : charset{}, hero{} {}

void HeroManager::init()
{
	if (charset.loadFromFile("res/texture/hero/hero.png")) {
		sf::Vector2f position;
		position.x = 32.f;
		position.y = 32.f;
		hero.setTexture(charset);
		
		hero.setTextureRect(sf::IntRect(32, 0, 32, 32));
		
		hero.setPosition(position);
	}
}

const Sprite& HeroManager::getSprite()
{
	return hero;
}

void HeroManager::tick()
{
	//cout << (reactor != nullptr? "yes" : "no") << endl;
	if (reactor != nullptr) {
		if (!reactor->tick()) {
			reactor->finalize();
			delete reactor.release();
		}
	}
}

void HeroManager::react(Event event)
{
	//cout << (reactor == nullptr? "yes" : "no") << endl;
	if (reactor == nullptr) {
		if (event.type == Event::KeyPressed) {
			Vector2f destination;
			if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
				destination.y = 1*movefactor;
			}
			if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
				destination.y = -1*movefactor;
			}
			if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
				destination.x = 1*movefactor;
			}
			if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) {
				destination.x = -1*movefactor;
			}
			destination += hero.getPosition();
			reactor = unique_ptr<MoveReactor>{new MoveReactor(hero, destination)};
		}
	}
}
