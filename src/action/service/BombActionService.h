#pragma once

#include "kangaru.h"

#include "../BombAction.h"
#include "../../loader/service/GameObjectLoaderService.h"

struct BombActionService : kgr::UniqueService<BombAction> {
	static Self construct(GameObjectLoaderService& gameObjectLoader, std::weak_ptr<GameObject> gameObject, sf::Vector2f position) {
		return std::unique_ptr<BombAction>(new BombAction{gameObjectLoader.forward(), gameObject, position});
	}
};