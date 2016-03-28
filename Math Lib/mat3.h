#pragma once
#include "vec3.h"
#include "Vec2.h"

struct Mat3
{
	Mat3() {}
	union
	{
		float v[9];
		float m[3][3];
		Vec3 c[3];
	};
	Vec3  operator[](unsigned idx) const { return c[idx]; }
	Vec3 &operator[](unsigned idx) { return c[idx]; }


	Mat3 transpose() const
	{
		Mat3 r;
		r.c[0] = Vec3(m[0][0], m[1][0], m[2][0]);
		r.c[1] = Vec3(m[0][1], m[1][1], m[2][1]);
		r.c[2] = Vec3(m[0][2], m[1][2], m[2][2]);
		return r;
	}

	static Mat3 identity()
	{
		Mat3 r;
		r.c[0] = Vec3(1, 0, 0);
		r.c[1] = Vec3(0, 1, 0);
		r.c[2] = Vec3(0, 0, 1);
		return r;
	}

	static Mat3 rotate(float angle)
	{
		Mat3 r = identity();
		r.c[0] = Vec3(cosf(angle), sinf(angle), 0);
		r.c[1] = Vec3(-sinf(angle), cosf(angle), 0);
		return r;
	}

	static Mat3 scale(float scale)
	{
		Mat3 r = identity();
		r.m[0][0] = scale;
		r.m[1][1] = scale;
		return r;
	}

	static Mat3 scale(const Vec2 &xy)
	{
		Mat3 r = identity();
		r.m[0][0] = xy.x;
		r.m[1][1] = xy.y;
		return r;
	}

	static Mat3 translation(const Vec2 &xy)
	{
		Mat3 r = identity();
		r.m[2][0] = xy.x;
		r.m[2][1] = xy.y;
		return r;
	}
};



inline Mat3 operator*(const Mat3 &_A, const Mat3 &B)
{

	Mat3 r, A = _A.transpose();

	r.c[0] = Vec3(dot(A.c[0], B.c[0]), dot(A.c[1], B.c[0]), dot(A.c[2], B.c[0]));
	r.c[1] = Vec3(dot(A.c[0], B.c[1]), dot(A.c[1], B.c[1]), dot(A.c[2], B.c[1]));
	r.c[2] = Vec3(dot(A.c[0], B.c[2]), dot(A.c[1], B.c[2]), dot(A.c[2], B.c[2]));

	return r;
}

inline Vec3 operator*(const Mat3 &_A, const Vec3 &b)
{
	Mat3 A = _A.transpose();
	Vec3 r;

	r.x = dot(A.c[0], b);
	r.y = dot(A.c[1], b);
	r.z = dot(A.c[2], b);

	return r;
}
