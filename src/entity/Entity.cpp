#include "Entity.h"

using namespace std;
using namespace sf;

Entity::Entity() : _square{Vector2f{0,0}, 0, 0} {}

void Entity::setCharset(Texture charset)
{
	_charset = charset;
}

void Entity::setSprite(Sprite sprite)
{
	_sprite = sprite;
}

void Entity::setSquare(Square square)
{
	_square = square;
}

Sprite& Entity::getSprite()
{
	return _sprite;
}

Square& Entity::getSquare()
{
	return _square;
}
