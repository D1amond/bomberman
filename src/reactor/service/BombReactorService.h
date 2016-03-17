#pragma once

#include "kangaru.h"

#include "../BombReactor.h"

struct BombReactorService : kgr::UniqueService<BombReactor> {
	static Self construct(kgr::ContainerService container, std::shared_ptr<GameObject> gameObject) {
		return std::unique_ptr<BombReactor>(new BombReactor{container.forward(), gameObject});
	}
};