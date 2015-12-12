#include "EventManager.h"

using namespace std;
using namespace sf;

void EventManager::dispatch(Event event)
{
	if (event.type == sf::Event::Closed) {
		//window.close();
	}
}
