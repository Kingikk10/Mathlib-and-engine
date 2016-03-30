#pragma once
#include "Vec2.h"
#include "mat3.h"


struct CollisionData // Wrapper for Minimum Translation Vector
{
	bool     isOverlap;         // Did we collide?
	float    PenetrationDepth;
	Vec2  CollisionNormal;   // CollisionNormal * PenetrationDepth = Minimum Translation Vector, also called the impulse vector, very important! 
	Vec2  PointOfContact;    // optional.
	Vec2 normal;
	Vec2 depth;
};




struct Ray { Vec2 position, direction; float length; };
struct Plane { Vec2 position, normal; };
struct Circle { Vec2 position; float r; };
struct AABB {
	Vec2 position;
	Vec2 halfextents;
	float depth;
	Vec2 min() const, max() const;
};


CollisionData iTest_circleVSaabb(const Circle &a, const AABB &b);

CollisionData iTest_circle(const Circle &a, const Circle	&b);

CollisionData iTest_aabb(const AABB   &a, const AABB	&b);


AABB   operator*(const Mat3 &m, const AABB   &a);

Circle operator*(const Mat3 &m, const Circle &a);
//Ray    operator*(const Mat3 &m, const Ray    &a);
//Plane  operator*(const Mat3 &m, const Plane  &a);
//
//
//float point_plane_dist(const Vec2 &a, const plane &b);
//float ray_plane_dist(const ray  &a, const plane &b);
//
//// determine whether or not the shapes are overlapping... fast!
//bool iTest_aabb(const AABB   &a, const AABB	&b)
//{
//	if (a.max < b.min || b.max < a.max)
//		return false;
//
//}
//bool iTest_aabb_circle(const AABB   &a, const Circle	&b)
//{
//	assert(false && "This needs to be implemented!");
//
//	return false;
//}
//bool iTest_aabb_plane(const aabb   &a, const plane	&b);
//bool iTest_aabb_ray(const aabb   &a, const ray		&b);
//bool iTest_circle(const circle &a, const circle	&b)
//{
//	assert(false && "This needs to be implemented!"); 
//
//	return false;
//}
//bool iTest_circle_plane(const circle &a, const plane	&b);
//bool iTest_circle_ray(const circle &a, const ray		&b);
//bool iTest_ray_plane(const ray    &a, const plane	&b);
//
//// Calculate the Minimum Translation Vector
//Vec2 mtv_aabb(const aabb   &a, const aabb	&b);
//Vec2 mtv_aabb_circle(const aabb   &a, const circle	&b);
//Vec2 mtv_aabb_plane(const aabb   &a, const plane	&b);
//Vec2 mtv_aabb_ray(const aabb   &a, const ray		&b);
//Vec2 mtv_circle(const circle &a, const circle	&b);
//Vec2 mtv_circle_plane(const circle &a, const plane	&b);
//Vec2 mtv_circle_ray(const circle &a, const ray		&b);
//Vec2 mtv_ray_plane(const ray    &a, const plane	&b);
//
//struct Vec2 { float x, y; };
//
//struct ray
//{
//	Vec2  p, // Position
//		d; // Direction
//	float l; // length (possibly infinite?) Just use a big value...
//};
//struct plane
//{
//	Vec2 p, // Position
//		n; // Normal
//};
//
//struct circle
//{
//	Vec2 p;  // position
//	float r; // radius
//};
//struct aabb
//{
//	Vec2 p, e; // position and half-extents
//	Vec2 min() const; // p - e
//	Vec2 max() const; // p + e
//};