#include "Collider.h"
#include "transform.h"
#include "collisions.h"



	Collider::Collider() : shape(Collider::e_CIRCLE), circle({ { 0,0 },1 })
	{ }



	CollisionData EvaluateCollision(const Transform &at, const Collider &ac, const Transform &bt, const Collider &bc)
	{
		
		return iTest_circle(at.getGlobalTrans() * ac.circle, bt.getGlobalTrans() * bc.circle);
	}

	//CollisionData EvaluateCollision(const Transform &at, const Collider &ac,
	//	const Transform &bt, const Collider &bc)
	//{
	//	Transform t_lhs = at;
	//	Transform t_rhs = bt;
	//	Collider lhs = ac;
	//	Collider rhs = bc;
	//	if (lhs.shape > rhs.shape)
	//	{
	//		std::swap(lhs, rhs);
	//		std::swap(t_lhs, t_rhs);
	//	}

	//	switch (lhs.shape | rhs.shape)
	//	{
	//	case Collider::e_CIRCLE:
	//		return iTest(t_lhs.getGlobalTrans() * lhs.circle,
	//			t_rhs.getGlobalTrans() * rhs.circle);

	//	case Collider::e_CIRCLE | Collider::e_AABB:
	//		return iTest(t_lhs.getGlobalTrans() * lhs.circle,
	//			t_rhs.getGlobalTrans() * rhs.aabb);

	//	case Collider::e_CIRCLE | Collider::e_RAY:
	//		return iTest(t_lhs.getGlobalTrans() * lhs.circle,
	//			t_rhs.getGlobalTrans() * rhs.ray);

	//	case Collider::e_CIRCLE | Collider::e_PLANE:
	//		return iTest(t_lhs.getGlobalTrans() * lhs.circle,
	//			t_rhs.getGlobalTrans() * rhs.plane);

	//	case Collider::e_AABB:
	//		return iTest(t_lhs.getGlobalTrans() * lhs.aabb,
	//			t_rhs.getGlobalTrans() * rhs.aabb);

	//	case Collider::e_AABB | Collider::e_RAY:
	//		return iTest(t_lhs.getGlobalTrans() * lhs.aabb,
	//			t_rhs.getGlobalTrans() * rhs.ray);

	//	case Collider::e_AABB | Collider::e_PLANE:
	//		return iTest(t_lhs.getGlobalTrans() * lhs.aabb,
	//			t_rhs.getGlobalTrans() * rhs.plane);

	//	case Collider::e_RAY | Collider::e_PLANE:
	//		return iTest(t_lhs.getGlobalTrans() * lhs.ray,
	//			t_rhs.getGlobalTrans() * rhs.plane);
	//	}
	//}

