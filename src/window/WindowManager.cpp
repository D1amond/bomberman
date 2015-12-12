#include "WindowManager.h"

using namespace kgr;
using namespace sf;
using namespace std;

WindowManager::WindowManager() : window{sf::VideoMode{800, 600}, "Bomberman"} {}

void WindowManager::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		
		for (shared_ptr<Drawable> drawable : drawables) {
			window.draw(*drawable.get());
		}
		
        window.display();
    }
}

void WindowManager::addDrawable(shared_ptr<Drawable> drawable)
{
	drawables.push_back(drawable);
}
