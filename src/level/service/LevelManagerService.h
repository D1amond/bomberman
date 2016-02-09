#pragma once

#include "kangaru.h"
#include "../../loader/service/LevelLoaderService.h"
#include "../LevelManager.h"

struct LevelManagerService : kgr::SingleService<LevelManager, kgr::Dependency<LevelLoaderService>> {};
