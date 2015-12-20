#include "SimpleAnimation.h"

#include <SFML/Graphics.hpp>
#include "../asset/GameSprite.h"

using namespace std;
using namespace sf;

SimpleAnimation::SimpleAnimation(weak_ptr<GameSprite> sprite) : _sprite{sprite} {
	_lastTime = _clock.getElapsedTime();
}

bool SimpleAnimation::run()
{
	Time elapsed = _clock.getElapsedTime();
	if (((elapsed.asMilliseconds() - _lastTime.asMilliseconds())/10)*10 >= 70) {
		if (!_sprite.expired()) {
			auto gameSprite = _sprite.lock();
			if (!gameSprite->getSprite().expired()) {
				_lastTime = elapsed;
				auto sprite = gameSprite->getSprite().lock();
				sprite->setTextureRect(_states.at(last-1));
				if (last == _states.size()) {
					last = 1;
					return false;
				} else {
					last++;
				}
				return true;
			}
		}
		return false;
	}
	return true;
}

void SimpleAnimation::finalize()
{
	if (!_sprite.expired()) {
		auto gameSprite = _sprite.lock();
		if (!gameSprite->getSprite().expired()) {
			auto sprite = gameSprite->getSprite().lock();
			sprite->setTextureRect(_states.at(last-1));
		}
	}
}

void SimpleAnimation::addState(IntRect state)
{
	_states.push_back(state);
}
