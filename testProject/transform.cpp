#include "transform.h"

Transform::Transform()
	:parent(nullptr), scale({ 1,1 }), position({ 0,0 }), angle(0){}


Mat3 Transform::getGlobalTrans() const
{	
		if (parent == nullptr)
		{
			return Mat3::translation(position) * Mat3::scale(scale) * Mat3::rotate(angle);
		}
		else
		{
			return parent->getGlobalTrans() * Mat3::translation(position) * Mat3::scale(scale) * Mat3::rotate(angle);
		}
}

void Transform::setParent(Transform *a_parent)
{
	parent = a_parent;
}

void Transform::setPos(const Vec2 &a_position)
{
	position = a_position;
}

void Transform::setScale(const Vec2 &a_scale)
{
	scale = a_scale;
}

void Transform::setAngle(float a_angle)
{
	angle = a_angle;
}

Vec2 Transform::getPos() const
{
	return position;
}

Vec2 Transform::getScale() const
{
	return scale;
}

float Transform::getAngle() const
{
	return angle;
}
Vec2 Transform::getRight() const
{
	return Vec2::fromAngle(angle);
}

Vec2 Transform::getUp() const
{
	return perp(Vec2::fromAngle(angle));
}