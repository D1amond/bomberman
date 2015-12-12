#pragma once

#include "EventListener.h"
#include "EventManager.h"
#include "../window/View.h"

struct KeyboardListener : EventListener
{
	KeyboardListener(View& view);
	void react(sf::Event event) override;
private:
	View& view;
};
