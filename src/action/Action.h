#pragma once

#include <memory>

struct GameObject;

struct Action
{
	Action(std::weak_ptr<GameObject> gameObject);
	virtual bool execute() = 0;
protected:
	std::weak_ptr<GameObject> _gameObject;
};