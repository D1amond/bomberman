#pragma once

#include "kangaru.h"

#include "../TickAction.h"
#include "../../loader/service/GameObjectLoaderService.h"

struct TickActionService : kgr::UniqueService<TickAction> {
	static Self construct(GameObjectLoaderService& gameObjectLoader, std::weak_ptr<GameObject> gameObject, sf::Vector2f position) {
		return std::unique_ptr<TickAction>(new TickAction{gameObjectLoader.forward(), gameObject, position});
	}
};
