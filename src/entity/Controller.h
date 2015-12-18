#pragma once

#include "Entity.h"

struct Controller
{
	virtual bool tick() = 0;
	void setEntity(Entity entity);
	Entity& getEntity();
protected:
	Entity _entity;
};
