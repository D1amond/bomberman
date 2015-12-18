#pragma once

#include "Controller.h"

struct ControllerManager
{
	void tick();
	void addController(Controller controller);
	std::vector<Controller>& getControllers();
private:
	std::vector<Controller> _controllers;
};
