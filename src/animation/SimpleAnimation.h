#pragma once

#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

struct GameSprite;

struct SimpleAnimation : Animation
{
	SimpleAnimation(std::weak_ptr<GameSprite> sprite);
	void addState(sf::IntRect state);
    bool run() override;
	void finalize() override;
private:
	std::weak_ptr<GameSprite> _sprite;
	std::vector<sf::IntRect> _states;
	std::size_t last{1};
	sf::Clock _clock;
	sf::Time _lastTime;
	bool _finished;
};
