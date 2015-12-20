#include "EventManager.h"

#include "EventListener.h"

using namespace std;
using namespace sf;

void EventManager::dispatch(Event event)
{
	auto range = _listeners.equal_range(event.type);
	for (auto it = range.first; it != range.second; it++) {
		it->second->react(event);
	}
}

void EventManager::subscribe(Event::EventType type, shared_ptr<EventListener> listener)
{
	_listeners.emplace(type, listener);
}
