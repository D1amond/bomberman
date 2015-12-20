#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <map>
#include "../animation/Animation.h"

struct GameTexture;

struct GameSprite
{
	GameSprite();
	void setSprite(std::shared_ptr<sf::Sprite> sprite);
	void setTexture(std::shared_ptr<GameTexture> texture);
	void addAnimation(std::string name, std::shared_ptr<Animation> animation);
	void toggleAnimation(std::string name);
	void stopAnimation();
	std::weak_ptr<Animation> getCurrentAnimation();
	std::weak_ptr<sf::Sprite> getSprite();
private:
	std::shared_ptr<sf::Sprite> _sprite;
	std::shared_ptr<GameTexture> _texture;
	std::shared_ptr<Animation> _currentAnimation;
	std::map<std::string, std::shared_ptr<Animation>> _animations;
};
