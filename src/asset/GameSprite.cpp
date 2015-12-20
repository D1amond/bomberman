#include "GameSprite.h"

#include "GameTexture.h"

using namespace std;
using namespace sf;

GameSprite::GameSprite() {}

weak_ptr<Sprite> GameSprite::getSprite()
{
	return _sprite;
}

void GameSprite::setSprite(shared_ptr< Sprite > sprite)
{
	_sprite = sprite;
}

void GameSprite::setTexture(shared_ptr<GameTexture> texture)
{
	_texture = texture;
}

weak_ptr<Animation> GameSprite::getCurrentAnimation()
{
	return _currentAnimation;
}

void GameSprite::stopAnimation()
{
	_currentAnimation = nullptr;
}

void GameSprite::addAnimation(string name, shared_ptr<Animation> animation)
{
	_animations.emplace(name, animation);
}

void GameSprite::toggleAnimation(string name)
{
	_currentAnimation = _animations.at(name);
}
