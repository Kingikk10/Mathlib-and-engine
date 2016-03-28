#pragma once
#include <cmath>
#include <cassert>
#include <cfloat>
#include "Vec2.h"

struct Vec3
{
	union
	{
		float v[3];
		struct { float x, y, z; };
		Vec2 xy;
	};

	Vec3() {}
	Vec3(float a_x, float a_y, float a_z)
		: x(a_x), y(a_y), z(a_z) {}

	float magnitude() const { return sqrtf(x*x + y*y + z*z); }

	float &operator[](unsigned idx) { return v[idx]; }
	float  operator[](unsigned idx) const { return v[idx]; }

	Vec3 normal() const;
};
//vec3 by vec3
inline Vec3 operator-(const Vec3  &lhs, const Vec3 &rhs)
{
	return Vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}
inline Vec3 operator+(const Vec3 &lhs, const Vec3 &rhs)
{
	return Vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}
inline Vec3 operator/(const Vec3 &lhs, const Vec3 &rhs)
{
	return Vec3(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
}
inline Vec3 operator*(const Vec3 &lhs, const Vec3 &rhs)
{
	return Vec3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}



//vec3 by float
inline Vec3 operator-(const Vec3  &lhs, float &rhs)
{
	return Vec3(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs);
}

inline Vec3 operator+(const Vec3 &lhs, float &rhs)
{
	return Vec3(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);
}

inline Vec3 operator/(const Vec3 &lhs, const float &rhs)
{
	return Vec3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

inline Vec3 operator*(const Vec3 &lhs, float &rhs)
{
	return Vec3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}




inline float dot(const Vec3 &lhs, const Vec3 &rhs)
{
	return lhs.x * rhs.x + rhs.y * lhs.y + rhs.z*lhs.z;
}


inline bool operator==(const Vec3 &lhs, const Vec3 &rhs)
{
	
	return
		rhs.x - FLT_EPSILON < lhs.x && lhs.x < rhs.x + FLT_EPSILON &&
		rhs.y - FLT_EPSILON < lhs.y && lhs.y < rhs.y + FLT_EPSILON &&
		rhs.z - FLT_EPSILON < lhs.z && lhs.z < rhs.z + FLT_EPSILON;

	
}

inline Vec3 Vec3::normal() const
{
	return *this / magnitude();
}