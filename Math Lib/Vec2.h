#pragma once
#include <cmath>
#include <cassert>
#include <cfloat>

struct Vec2
{
	union
	{
		struct { float x, y; };
		float v[2];
	};

	Vec2() {}
	Vec2(float a_x, float a_y)
		: x(a_x), y(a_y) {}

	float magnitude() const { return sqrtf(x*x + y*y); }

	float &operator[](unsigned idx) { return v[idx]; }
	float  operator[](unsigned idx) const { return v[idx]; }
	
	static Vec2 fromAngle(float a)
	{
		return{ cosf(a), sinf(a) };
	}

	Vec2 normal() const;

	
};


//vec2 by vec2
inline Vec2 operator-(const Vec2  &lhs, const Vec2 &rhs)
{
	return Vec2(lhs.x - rhs.x, lhs.y - rhs.y );
}
inline Vec2 operator+(const Vec2 &lhs, const Vec2 &rhs)
{
	return Vec2(lhs.x + rhs.x, lhs.y + rhs.y);
}
inline Vec2 operator/(const Vec2 &lhs, const Vec2 &rhs)
{
	return Vec2(lhs.x / rhs.x, lhs.y / rhs.y);
}
inline Vec2 operator*(const Vec2 &lhs, const Vec2 &rhs)
{
	return Vec2(lhs.x * rhs.x, lhs.y * rhs.y);
}



//vec2 by float
inline Vec2 operator-(const Vec2  &lhs, float &rhs)
{
	return Vec2(lhs.x - rhs, lhs.y - rhs);
}

inline Vec2 operator+(const Vec2 &lhs, float &rhs)
{
	return Vec2(lhs.x + rhs, lhs.y + rhs);
}

inline Vec2 operator/(const Vec2 &lhs, const float &rhs)
{
	return Vec2(lhs.x / rhs, lhs.y / rhs);
}

inline Vec2 operator*(const Vec2 &lhs, float &rhs)
{
	return Vec2(lhs.x * rhs, lhs.y * rhs);
}

inline Vec2 operator*(float &lhs, const Vec2 &rhs)
{
	return rhs * lhs;
}

//inline Vec2 operator*(const Vec2 &lhs, float &rhs)
//{
//	return Vec2(lhs.x * rhs, lhs.y * rhs);
//}

inline float dot(const Vec2 &lhs, const Vec2 &rhs)
{
	return lhs.x * rhs.x + rhs.y * lhs.y;
}

inline Vec2 Lerp(const Vec2 &a, const Vec2 &b, float t )
{
	return a + t *(a - b);

}

inline bool operator==(const Vec2 &lhs, const Vec2 &rhs)
{
	
	return
		rhs.x - FLT_EPSILON < lhs.x && lhs.x < rhs.x + FLT_EPSILON &&
		rhs.y - FLT_EPSILON < lhs.y && lhs.y < rhs.y + FLT_EPSILON;

}

inline Vec2 perp(const Vec2  &a)
{
	return Vec2(-a.y, a.x);
}

inline Vec2 Vec2::normal() const
{
	return *this / magnitude();

}


//inline Vec2 operator<(float &lhs, const Vec2 &rhs)
//{
//	return float lhs;
//}


// Vector clamp clamps the x's and the y's separately
// min and a max that finds the min of x's and y's separately

inline Vec2 Min(const Vec2 &a, const Vec2 &b)
{
	return Vec2{ fminf(a.x, b.x), fminf(a.y, b.y) };
}


inline Vec2 Max(const Vec2 &a, const Vec2 &b)
{
	return Vec2{ fmaxf(a.x, b.x), fmaxf(a.y, b.y) };
}

inline Vec2 Clamp(const Vec2 &a, const Vec2 &min, const Vec2 &max)
{

	return Max(min, Min(a, max));
	//if (a.x < min) { return min; }
	//if (a.x < max) { return max; }
	//if (a.x > min && a.x < max) { return a; }
}


