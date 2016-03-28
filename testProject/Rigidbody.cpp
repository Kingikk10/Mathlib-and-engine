#include "Rigidbody.h"









Rigidbody::Rigidbody()
	:acc({ 0,0 }), vel({ 0,0 }), mass(1), force({ 0,0 }), drag(0)
{
}

void Rigidbody::addForce(const Vec2 &a)
{
	force = force + a;
}

void Rigidbody::addTq(float a)
{
	tq = tq + a;
}

void Rigidbody::integrate(Transform *t, float dt)
{
	//jerk = force / mass - acc;
	acc = force / mass; 
	vel = vel + acc * dt;
	t->setPos(t->getPos() + vel * dt);

	vel = vel - vel * drag * dt;

	force = { 0, 0 };
}
