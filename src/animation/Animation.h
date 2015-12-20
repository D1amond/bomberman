#pragma once

struct Animation
{
	virtual bool run() = 0;
	virtual void finalize() = 0;
};
