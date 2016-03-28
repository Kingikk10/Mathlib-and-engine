#pragma once
#include "Systems.h"
#include "Input.h"
#include "Time.h"
#include "Factory.h"
#include "PLayerController.h"

class PlayerFlightSystem : public System
{
	bool condition(Handle<Entity> i)
	{
		return i->rigidbody  > -1 &&
			i->transform  > -1 &&
			i->controller > -1;
	}

	void update(Handle<Entity> i)
	{
		auto  &input = Input::instance();
		auto  &c = *i->controller;
		auto  &r = *i->rigidbody;
		float dt = Time::instance().getDeltaTime();

		if (input.getKey(c.Left))
			i->rigidbody->addTq(c.turnspeed);

		if (input.getKey(c.Right))
			r.addTq(-c.turnspeed);

		if (input.getKey(c.Forward))
			r.addForce(i->transform->getUp() * c.speed);
	
		/*if (input.getKey(c.Back))
			r.addForce(i->transform->getUp() * c.speed);*/

		if (input.getKey(' '))
		{
			Factory::makeBullet(i->transform->getPos(), i->transform->getUp());
		}
	}

};