#pragma once

#include "kangaru.h"
#include "../LevelLoader.h"
#include "../../collision/service/CollisionManagerService.h"

struct LevelLoaderService : kgr::SingleService<LevelLoader, kgr::Dependency<CollisionManagerService>> {};