#include "SimpleAnimation.h"

#include <SFML/Graphics.hpp>
#include "../asset/GameSprite.h"

using namespace std;
using namespace sf;

SimpleAnimation::SimpleAnimation(weak_ptr<GameSprite> sprite) : _sprite{sprite}, _finished{false} {
	_lastTime = _clock.getElapsedTime();
}

bool SimpleAnimation::run()
{
	Time elapsed = _clock.getElapsedTime();
	if (((elapsed.asMilliseconds() - _lastTime.asMilliseconds())/10)*10 >= 70) {
		if (!_sprite.expired()) {
			auto gameSprite = _sprite.lock();
			_lastTime = elapsed;
			auto sprite = gameSprite->getSprite();
			sprite->setTextureRect(_states.at(last-1));
			if (last == _states.size()) {
				last = 1;
			} else {
				last++;
			}
		}
	}
	return !_finished;
}

void SimpleAnimation::finalize()
{
	if (!_sprite.expired()) {
		auto gameSprite = _sprite.lock();
		auto sprite = gameSprite->getSprite();
		sprite->setTextureRect(_states.at(last-1));
		_finished = true;
	}
}

void SimpleAnimation::addState(IntRect state)
{
	_states.push_back(state);
}
