#pragma once

#include "kangaru.h"

#include "../GameObjectLoader.h"
#include <src/event/service/EventManagerService.h>
#include <src/asset/service/GameObjectManagerService.h>

struct GameObjectLoaderService : kgr::SingleService<GameObjectLoader, kgr::Dependency<EventManagerService, GameObjectManagerService>> {};
