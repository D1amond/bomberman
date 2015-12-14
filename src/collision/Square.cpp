#include "Square.h"

#include <cmath>

using namespace sf;

Square::Square(Vector2f position, float height, float length) : position{position}, height{height}, length{length} {}

bool Square::collides(Square& square)
{
	bool collides = false;
	float totalXA = square.getPosition().x + square.getLength();
	float totalYA = square.getPosition().y + square.getHeight();
	float totalXB = position.x + length;
	float totalYB = position.y + height;
	
	if (abs(totalXB-totalXA) <= (square.getLength())) {
		collides = true;
	}
	
	if (abs(totalYB-totalYA) <= (square.getHeight())) {
		collides = true;
	}
	
	return collides;
}

const Vector2f Square::getPosition()
{
	return position;
}

const float Square::getHeight()
{
	return height;
}

const float Square::getLength()
{
	return length;
}
