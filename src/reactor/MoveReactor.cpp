#include "MoveReactor.h"

#include <iostream>

using namespace std;
using namespace sf;

MoveReactor::MoveReactor(Sprite& sprite, Vector2f position) : sprite{sprite}, position{position}, timer{}, direction{} {
	auto diffX = position.x - sprite.getPosition().x;
	auto diffY = position.y - sprite.getPosition().y;
	initialTime = timer.getElapsedTime();
	lastTime = timer.getElapsedTime();
	animationTime = timer.getElapsedTime();
	
	if (diffX != 0) {
		if (diffX > 0) {
			direction.first = "right";
			direction.second = Vector2f{1, 0};
		} else {
			direction.first = "left";
			direction.second = Vector2f{-1, 0};
		}
	} else if (diffY != 0) {
		if (diffY > 0) {
			direction.first = "down";
			direction.second = Vector2f{0, 1};
		} else {
			direction.first = "up";
			direction.second = Vector2f{0, -1};
		}
	}
}

MoveReactor::~MoveReactor() {}

void MoveReactor::finalize()
{
	if (direction.first == "up") {
		sprite.setTextureRect(sf::IntRect(32, 32, 32, 32));
	} else if (direction.first == "down") {
		sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
	} else if (direction.first == "left") {
		sprite.setTextureRect(sf::IntRect(32, 96, 32, 32));
	} else if (direction.first == "right") {
		sprite.setTextureRect(sf::IntRect(32, 64, 32, 32));
	}
	animationCounter = 0;
}

bool MoveReactor::tick()
{
	auto diffX = position.x - sprite.getPosition().x;
	auto diffY = position.y - sprite.getPosition().y;
	Time elapsed = timer.getElapsedTime();
	
	if (diffX != 0 || diffY != 0) {
		if (((elapsed.asMilliseconds() - lastTime.asMilliseconds())/10)*10 == 10) {
			animate(elapsed);
			sprite.move(direction.second);
			lastTime = elapsed;
		}
		
		//fallback
		if (elapsed.asSeconds() - initialTime.asSeconds() > 1.5) {
			sprite.move(diffX, diffY);
		}
		
		return true;
	} else {
		return false;
	}
}

void MoveReactor::animate(Time elapsed)
{
	if (((elapsed.asMilliseconds() - animationTime.asMilliseconds())/10)*10 == 70) {
		if (animationCounter == 0) {
			if (direction.first == "up") {
				sprite.setTextureRect(sf::IntRect(32, 32, 32, 32));
			} else if (direction.first == "down") {
				sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
			} else if (direction.first == "left") {
				sprite.setTextureRect(sf::IntRect(32, 96, 32, 32));
			} else if (direction.first == "right") {
				sprite.setTextureRect(sf::IntRect(32, 64, 32, 32));
			}
			animationCounter++;
		} else if (animationCounter == 1) {
			if (direction.first == "up") {
				sprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
			} else if (direction.first == "down") {
				sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
			} else if (direction.first == "left") {
				sprite.setTextureRect(sf::IntRect(0, 96, 32, 32));
			} else if (direction.first == "right") {
				sprite.setTextureRect(sf::IntRect(0, 64, 32, 32));
			}
			animationCounter++;
		} else {
			if (direction.first == "up") {
				sprite.setTextureRect(sf::IntRect(32, 32, 32, 32));
			} else if (direction.first == "down") {
				sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
			} else if (direction.first == "left") {
				sprite.setTextureRect(sf::IntRect(32, 96, 32, 32));
			} else if (direction.first == "right") {
				sprite.setTextureRect(sf::IntRect(32, 64, 32, 32));
			}
			animationCounter = 0;
		}
		animationTime = elapsed;
	}
}
