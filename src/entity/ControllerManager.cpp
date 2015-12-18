#include "ControllerManager.h"

using namespace std;

void ControllerManager::tick()
{
	for (Controller controller : _controllers) {
		if (!controller.tick()) {
			_controllers.erase(remove<Controller>(_controllers.begin(), _controllers.end(), controller), _controllers.end());
		}
	}
}

vector<Controller>& ControllerManager::getControllers()
{
	return _controllers;
}


void ControllerManager::addController(Controller controller)
{
	_controllers.push_back(controller);
}
