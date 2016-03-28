#pragma once
#include "GCData.h"


class LifeCycle : public GCData<LifeCycle>
{
public:
	float lifetime;
	float lifespan;

	LifeCycle() : lifetime(0), lifespan(5) {}
};


