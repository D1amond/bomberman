#include "MoveReactor.h"

#include <iostream>

using namespace std;
using sf::Vector2f;
using sf::Time;

MoveReactor::MoveReactor(
	CollisionManager& collisionManager,
	Entity& entity,
	Vector2f position
) : entity{entity},
	position{position},
	timer{},
	direction{},
	_collisionManager{collisionManager}
{
	auto diffX = position.x - entity.getSprite().getPosition().x;
	auto diffY = position.y - entity.getSprite().getPosition().y;
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
		entity.getSprite().setTextureRect(sf::IntRect(32, 32, 32, 32));
	} else if (direction.first == "down") {
		entity.getSprite().setTextureRect(sf::IntRect(32, 0, 32, 32));
	} else if (direction.first == "left") {
		entity.getSprite().setTextureRect(sf::IntRect(32, 96, 32, 32));
	} else if (direction.first == "right") {
		entity.getSprite().setTextureRect(sf::IntRect(32, 64, 32, 32));
	}
	animationCounter = 0;
}

bool MoveReactor::tick()
{
	auto diffX = position.x - entity.getSprite().getPosition().x;
	auto diffY = position.y - entity.getSprite().getPosition().y;
	Time elapsed = timer.getElapsedTime();
	/*
	if (_collisionManager.collides(entity.getSquare())) {
		cout << "COLLISION!!!" << endl;
	}*/
	
	if (_collisionManager.hasTile(entity.getSprite().getPosition()+(32.f*direction.second))) {
		return false;
	}
	
	if (diffX != 0 || diffY != 0) {
		if (((elapsed.asMilliseconds() - lastTime.asMilliseconds())/10)*10 == 10) {
			animate(elapsed);
			entity.getSprite().move(direction.second);
			lastTime = elapsed;
		}
		
		//fallback
		if (elapsed.asSeconds() - initialTime.asSeconds() > 1.5) {
			entity.getSprite().move(diffX, diffY);
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
				entity.getSprite().setTextureRect(sf::IntRect(32, 32, 32, 32));
			} else if (direction.first == "down") {
				entity.getSprite().setTextureRect(sf::IntRect(32, 0, 32, 32));
			} else if (direction.first == "left") {
				entity.getSprite().setTextureRect(sf::IntRect(32, 96, 32, 32));
			} else if (direction.first == "right") {
				entity.getSprite().setTextureRect(sf::IntRect(32, 64, 32, 32));
			}
			animationCounter++;
		} else if (animationCounter == 1) {
			if (direction.first == "up") {
				entity.getSprite().setTextureRect(sf::IntRect(0, 32, 32, 32));
			} else if (direction.first == "down") {
				entity.getSprite().setTextureRect(sf::IntRect(0, 0, 32, 32));
			} else if (direction.first == "left") {
				entity.getSprite().setTextureRect(sf::IntRect(0, 96, 32, 32));
			} else if (direction.first == "right") {
				entity.getSprite().setTextureRect(sf::IntRect(0, 64, 32, 32));
			}
			animationCounter++;
		} else {
			if (direction.first == "up") {
				entity.getSprite().setTextureRect(sf::IntRect(32, 32, 32, 32));
			} else if (direction.first == "down") {
				entity.getSprite().setTextureRect(sf::IntRect(32, 0, 32, 32));
			} else if (direction.first == "left") {
				entity.getSprite().setTextureRect(sf::IntRect(32, 96, 32, 32));
			} else if (direction.first == "right") {
				entity.getSprite().setTextureRect(sf::IntRect(32, 64, 32, 32));
			}
			animationCounter = 0;
		}
		animationTime = elapsed;
	}
}
