#pragma once
#include "Collider.h"
#include "Rigidbody.h"
#include "collisions.h"
#include "transform.h"
void drawAABB(const AABB &c, unsigned TINT = 0xffffffff);
void drawCircle(const Circle &c, unsigned TINT = 0xffffffff);
void drawMatrix(const Mat3 &);
void drawVector(const Mat3 &, const Vec2 &, unsigned TINT = 0x00ffffff);
void drawPlane(const Plane   &, unsigned TINT);
void drawRay(const Ray     &, unsigned TINT);


void drawTransform(const Transform &);
void drawRigidbody(const Transform &, const Rigidbody &);
void drawCollider(const Transform &, const Collider  &);