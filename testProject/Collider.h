#pragma once
#include "collisions.h"
#include "transform.h"
#include "GCData.h"





class Collider : public GCData<Collider>
{
public:
	enum SHAPE { e_CIRCLE = 1, e_AABB = 2, e_RAY = 4, e_PLANE = 8 } shape;
	union
	{
		Circle circle;
		AABB aabb;
		Ray ray;
		Plane plane;

	};

	Collider();
	
};

class Transform;

CollisionData EvaluateCollision(const Transform &at, const Collider &ac, const Transform &bt, const Collider &bc);



