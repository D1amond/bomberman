#include "Controller.h"

Entity& Controller::getEntity()
{
	return _entity;
}

void Controller::setEntity(Entity entity)
{
	_entity = entity;
}
