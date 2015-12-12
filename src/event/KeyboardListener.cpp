#include "KeyboardListener.h"

using namespace std;

KeyboardListener::KeyboardListener(View& view) : view{view} {}

void KeyboardListener::react(sf::Event event)
{
	if (event.key.code == sf::Keyboard::A) {
		auto shape = make_shared<sf::CircleShape>(100.f);
		shape->setFillColor(sf::Color::Green);
		view.addDrawable(shape);
	} else if (event.key.code == sf::Keyboard::B) {
		auto shape = make_shared<sf::CircleShape>(50.f);
		shape->setFillColor(sf::Color::Red);
		view.addDrawable(shape);
	}
}
