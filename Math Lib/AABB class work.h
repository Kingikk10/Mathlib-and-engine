#pragma once






struct vec2 { float x, y; };

struct AABB { vec2 pos; vec2 dim;};

vec2 min(vec2 *v, size_t n);
vec2 max(vec2 *v, size_t n);

AABB genAABB(vec2 *pts, size_t n);


AABB rotate(const AABB &aabb, float a);

