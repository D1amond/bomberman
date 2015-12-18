#pragma once

struct Reactor
{
	virtual ~Reactor() = default;
	virtual bool tick() = 0;
	virtual void finalize() = 0;
};
