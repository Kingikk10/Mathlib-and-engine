//
//#include "mat3.h"
//
//
//Mat3 operator*(const Mat3 &_A, const Mat3 &B)
//{
//
//	Mat3 r, A = _A.transpose();
//
//	r.c[0] = Vec3(dot(A.c[0], B.c[0]), dot(A.c[1], B.c[0]), dot(A.c[2], B.c[0]));
//	r.c[1] = Vec3(dot(A.c[0], B.c[1]), dot(A.c[1], B.c[1]), dot(A.c[2], B.c[1]));
//	r.c[2] = Vec3(dot(A.c[0], B.c[2]), dot(A.c[1], B.c[2]), dot(A.c[2], B.c[2]));
//
//	return r;
//}
//
//Vec3 operator*(const Mat3 &_A, const Vec3 &b)
//{
//	Mat3 A = _A.transpose();
//	Vec3 r;
//
//	r.x = dot(A.c[0], b);
//	r.y = dot(A.c[1], b);
//	r.z = dot(A.c[2], b);
//
//	return r;
//}
