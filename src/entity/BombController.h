#pragma once

#include "Controller.h"

struct BombController : Controller
{
	bool tick() override;
};
