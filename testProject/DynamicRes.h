#pragma once
#include "CollisionDetection.h"
#include "Vec2.h"

class DynamicResolution : public CollisionSystem
{
	bool condition(Collision c)
	{
		return c.first->rigidbody > -1 && c.second->rigidbody > -1;
	}

	void update(Collision c)
	{
		Vec2 MTV = c.collision.normal * c.collision.depth;

		Vec2 p1 = c.first->transform->getPos() - MTV / 2;
		Vec2 p2 = c.second->transform->getPos() + MTV / 2;

		c.first->transform->setPos(p1);
		c.second->transform->setPos(p2);

		std::swap(c.first->rigidbody->vel, c.second->rigidbody->vel);
	}
};
