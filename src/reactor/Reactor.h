#pragma once

struct Reactor
{
	~Reactor();
	virtual bool tick() = 0;
	virtual void finalize() = 0;
};
