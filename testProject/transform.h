#pragma once
#include "mat3.h"
#include <mat3.cpp>
#include <list>
#include "GCData.h"


class Transform : public GCData<Transform>
{

private:
	Vec2 position, scale;
	float angle;
	Transform *parent;

public:

	Transform();


	Mat3 getGlobalTrans() const;
	
	void setParent(Transform *);
	void setPos(const Vec2 &);
	void setScale(const Vec2 &);
	void setAngle(float);

	Vec2 getPos() const;
	Vec2 getScale() const;
	float getAngle() const;

	Vec2 getRight()     const;
	Vec2 getUp()        const;

};













