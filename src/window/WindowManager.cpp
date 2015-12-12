#include "WindowManager.h"

using namespace kgr;
using sf::Drawable;
using namespace std;

WindowManager::WindowManager(View& view, EventManager& eventManager) : window{sf::VideoMode{800, 600}, "Bomberman"}, view{view}, eventManager{eventManager} {}

void WindowManager::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			else
				eventManager.dispatch(event);
        }

        window.clear();
		
		for (shared_ptr<Drawable> drawable : view.getDrawables()) {
			window.draw(*drawable);
		}
		
        window.display();
    }
}
