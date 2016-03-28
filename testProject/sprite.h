#pragma once
#include "GCData.h"
#include "Vec2.h"
#include <string>

class Sprite : public GCData<Sprite>
{
public:
	Vec2 offset;
	Vec2 dimension;
	float   angle;

	std::string assetName;

	Sprite() : offset({ 0,0 }),
		dimension({ 1,1 }),
		angle(0) { }
};