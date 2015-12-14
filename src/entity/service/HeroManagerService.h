#pragma once

#include "kangaru.h"

#include "../HeroManager.h"

struct HeroManagerService : kgr::SharedService<HeroManager, kgr::Dependency<kgr::ContainerService>> {
	using invoke = kgr::Invoke<INVOKE(&HeroManagerService::autocall<METHOD(&HeroManager::init)>)>;
};

template<> struct ServiceMap<std::shared_ptr<HeroManager>> { using Service = HeroManagerService; };