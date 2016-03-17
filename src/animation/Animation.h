#pragma once

struct Animation
{
	virtual ~Animation() = default;
	virtual bool run() = 0;
	virtual void finalize() = 0;
};
