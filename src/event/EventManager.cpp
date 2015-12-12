#include "EventManager.h"

#include "EventListener.h"
#include "KeyboardListener.h"

using namespace std;
using namespace sf;

void EventManager::subscribe(Event::EventType type, shared_ptr<EventListener> listener)
{
	listeners.emplace(type, listener);
}

void EventManager::init(shared_ptr<KeyboardListener> keyboardListener)
{
	subscribe(sf::Event::KeyReleased, keyboardListener);
}


void EventManager::dispatch(Event event)
{
	auto range = listeners.equal_range(event.type);
	for (auto it = range.first; it != range.second; it++) {
		it->second->react(event);
	}
}

