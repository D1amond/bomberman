#pragma once

#include "kangaru.h"

#include "../MoveReactor.h"
#include "../../collision/service/CollisionManagerService.h"

//struct MoveReactorService : kgr::UniqueService<MoveReactor, kgr::Dependency<CollisionManagerService>> {};

struct MoveReactorService : kgr::UniqueService<MoveReactor> {
	using Self::Self;
	static MoveReactorService construct(CollisionManagerService& collisionManager, Entity& entity, sf::Vector2f position) {
		return std::unique_ptr<MoveReactor>{new MoveReactor{collisionManager.forward(), entity, position}};
	}
};