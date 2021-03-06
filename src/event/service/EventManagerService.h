#pragma once

#include "kangaru.h"

#include "../EventManager.h"

#include "KeyboardListenerService.h"
#include "../../entity/service/HeroManagerService.h"

struct EventManagerService : kgr::SingleService<EventManager> {
	using invoke = kgr::Invoke<
        INVOKE( &EventManagerService::autocall<METHOD(&EventManager::init), KeyboardListenerService, HeroManagerService>)
    >;
};