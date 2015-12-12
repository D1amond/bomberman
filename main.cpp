#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "kangaru.h"

#include "src/window/WindowManager.h"
#include "src/window/service/ViewService.h"

using namespace kgr;
using namespace std;

int main(int argc, char **argv) {
	Container container;
	
	auto& view = container.service<ViewService>();
	auto manager = make_shared<WindowManager>(view);
	
	auto shape = make_shared<sf::CircleShape>(100.f);
    shape->setFillColor(sf::Color::Green);
	
	auto shape2 = make_shared<sf::CircleShape>(50.f);
    shape2->setFillColor(sf::Color::Red);
	
	view.addDrawable(shape);
	view.addDrawable(shape2);
	
	manager->run();

    return 0;
}
