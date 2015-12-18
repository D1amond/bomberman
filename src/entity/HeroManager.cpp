#include "HeroManager.h"

#include <iostream>
#include "../reactor/service/MoveReactorService.h"
#include "../collision/Square.h"
#include "../collision/service/CollisionManagerService.h"

using namespace std;
using namespace sf;

HeroManager::HeroManager(kgr::Container& container) : _container{container} {}

void HeroManager::init()
{
	if (charset.loadFromFile("res/texture/hero/hero.png")) {
		sf::Sprite sprite;
		sf::Vector2f position;
		position.x = 32.f;
		position.y = 32.f;
		sprite.setTexture(charset);
		
		sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
		
		sprite.setPosition(position);
		
		Square square{position, 32, 32};
		
		hero.setCharset(charset);
		hero.setSprite(sprite);
		hero.setSquare(square);
	}
}

const Sprite& HeroManager::getSprite()
{
	return hero.getSprite();
}

void HeroManager::tick()
{
	if (reactor != nullptr) {
		if (!reactor->tick()) {
			reactor->finalize();
			reactor.reset();
		}
	}
}

void HeroManager::react(Event event)
{
	if (reactor == nullptr) {
		if (event.type == Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::X) {
				
			} else {
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
				destination += hero.getSprite().getPosition();
				reactor = _container.service<MoveReactorService>(hero, destination);
			}
		}
	}
}
