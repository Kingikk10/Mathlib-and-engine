#include "collisions.h"
#include <vector>
CollisionData DSAT(float amin, float amax, float bmin, float bmax, Vec2 axis)
{
	float pDr = amax - bmin;
	float pDl = bmax - amin;

	float pD = std::fminf(pDr, pDl);
	float H = std::copysignf(1, pDr - pDl);
	return{ pD > 0, pD, axis*H };
}

CollisionData iTest_circle(const Circle &a, const Circle	&b)
{
	CollisionData cd;
	cd.PenetrationDepth = a.r + b.r - (a.position - b.position).magnitude();
	cd.CollisionNormal  = (a.position - b.position).normal();
	cd.isOverlap = cd.PenetrationDepth >= 0;
	return cd;
}

CollisionData iTest_aabb(const AABB &a, const AABB &b)
{
	// DSAT calculates the Separating Axis Theorem in 1-D
	// We can calculate the results along the x and y axis separately,
	// and just pick the shortest one
	auto cdx = DSAT(a.min().x, a.max().x, b.min().x, b.max().x, { 1, 0 });
	auto cdy = DSAT(a.min().y, a.max().y, b.min().y, b.max().y, { 0, 1 });

	return cdx.PenetrationDepth < cdy.PenetrationDepth ? cdx : cdy;
}

Vec2 AABB::min() const
{
    return position - halfextents;
}
Vec2 AABB::max() const
{
	return position + halfextents;
}

AABB operator*(const Mat3 &m, const AABB &a)
{
	Vec2 omin = a.min();
	Vec2 omax = a.max();

	Vec2 rmin = m[2].xy;
	Vec2 rmax = m[2].xy;

	float p, q;

	for (unsigned j = 0; j < 2; ++j)
		for (unsigned i = 0; i < 2; ++i)
		{
			p = omin[i] * m[i][j];
			q = omax[i] * m[i][j];

			if (p < q) std::swap(p, q);
			rmin[j] += p;
			rmax[j] += q;
		}
	return{ (rmin + rmax) / 2, (rmin - rmax) / 2 };
}
//AABB   operator*(const Mat3 &m, const AABB   &a)
//{
//	AABB r;
//	Vec3 np = (m * Vec3{ a.position.x, a.position.y, 1 });
//
//	r.position.x = np.x;
//	r.position.y = np.y;
//
//	
//	return r;
//}

Circle operator*(const Mat3 &m, const Circle &a)
{
	Circle r;
	Vec3 np = (m * Vec3{ a.position.x, a.position.y, 1 });

	r.position.x = np.x;
	r.position.y = np.y;



	Vec3 tp = (m * Vec3{ a.r, 0, 0 });
	Vec3 dp = (m * Vec3{ 0, a.r, 0 });

	

	r.position.x = np.x;
	r.position.y = np.y;
	r.r = std::fmaxf(tp.magnitude(), dp.magnitude());

	return r;
}


