#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "kangaru.h"

#include "src/window/WindowManager.h"
#include "src/window/service/ViewService.h"
#include "src/event/service/EventManagerService.h"
#include "src/level/service/LevelManagerService.h"
#include "src/level/Level.h"

using namespace kgr;
using namespace std;

int main(int argc, char **argv) {
	Container container;
	
	auto& view = container.service<ViewService>();
	auto& levelManager = container.service<LevelManagerService>();
	auto manager = make_shared<WindowManager>(view, container.service<EventManagerService>(), levelManager);
	
	levelManager.goTo("level1");
	
	manager->run();

    return 0;
}
