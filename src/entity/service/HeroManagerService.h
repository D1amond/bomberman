#pragma once

#include "kangaru.h"

#include "../HeroManager.h"

struct HeroManagerService : kgr::SharedService<HeroManager> {
	using invoke = kgr::Invoke<INVOKE(&HeroManagerService::autocall<METHOD(&HeroManager::init)>)>;
};

template<> struct ServiceMap<std::shared_ptr<HeroManager>> { using Service = HeroManagerService; };