#include "sfwdraw.h"
#include "crenderutils.h"


void drawAABB(const AABB &t, unsigned TINT)
{
	sfw::drawLine(t.min().x, t.min().y, t.max().x, t.min().y, TINT);
	sfw::drawLine(t.min().x, t.max().y, t.max().x, t.max().y, TINT);
	sfw::drawLine(t.max().x, t.min().y, t.max().x, t.max().y, TINT);
	sfw::drawLine(t.min().x, t.min().y, t.min().x, t.max().y, TINT);
}
//void drawLine(float x1, float y1, float x2, float y2, unsigned tint = 0xffffffff, const float transform[16] = identity);

void drawCircle(const Circle &c, unsigned TINT)
{
	sfw::drawCircle(c.position.x, c.position.y, c.r,12, TINT);
}

void drawCollider(const Transform &t, const Collider  &c)
{
	switch (c.shape)
	{
	case Collider::e_AABB:
		drawAABB(t.getGlobalTrans() * c.aabb, BLUE);
		break;
	case Collider::e_CIRCLE:
		drawCircle(t.getGlobalTrans() * c.circle, BLUE);
		break;
	}
}

void drawMatrix(const Mat3 &a)
{
	Vec2 &pos = a[2].xy;
	Vec2 up = pos + a[1].xy;
	Vec2 right = pos + a[0].xy;

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);
}

void drawTransform(const Transform &t) { drawMatrix(t.getGlobalTrans() * Mat3::scale({ 30,30 })); }

void drawRigidbody(const Transform &t, const Rigidbody &rb)
{

	Vec2 pos = t.getPos();
	Vec2 acc = pos + rb.acc;
	Vec2 vel = pos + rb.vel;

	sfw::drawLine(pos.x, pos.y, acc.x, acc.y, CYAN);
	sfw::drawLine(pos.x, pos.y, vel.x, vel.y, YELLOW);
}