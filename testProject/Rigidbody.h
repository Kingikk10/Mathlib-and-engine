#pragma once

#include "Vec2.h"
#include "GCData.h"
#include "transform.h"


class Rigidbody : public GCData<Rigidbody>
{

public:
	Vec2 vel, acc, force, jerk;
	float mass, drag;

	float angVel, angAcc, tq;
	float andDrag;

	Rigidbody();
	void addForce(const Vec2 &);
	void addTq(float a);
	void integrate(Transform *, float dt);
	

};


