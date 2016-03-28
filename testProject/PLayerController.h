#pragma once
#include "GCData.h"

class PlayerController : public GCData<PlayerController>
{
public:
	char Left, Right, Forward;

	float speed, turnspeed;

	PlayerController() : Forward('W'),  Left('A'), Right('D'),
	speed(100), turnspeed(10) {}


};