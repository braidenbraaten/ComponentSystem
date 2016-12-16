#pragma once
#include <cmath>
#include "mat3.h"
//namespace for my own math library 
namespace bab
{
	
	struct Vec3
	{
		float x, y, z;
		Vec3 normal();
		float Magnitude();
		void Normalize();
		float sum = x + y + z;
		Vec3(): x(0.0f),y(0.0f),z(0.0f) {}
		Vec3(float l_x, float l_y, float l_z) : x(l_x), y(l_y), z(l_z) {}
		Vec3(int l_x, int l_y, int l_z) : x(l_x), y(l_y), z(l_z) {}
	};

	float dot(const Vec3 &lhs, const Vec3 &rhs);

	Vec3 operator-(Vec3 vec); //<-x, -y>



	Vec3 operator+ (const Vec3 &lhs, const Vec3 &rhs);
	Vec3& operator+=(Vec3 &lhs, const Vec3 &rhs);

	Vec3 operator- (const Vec3 &lhs, const Vec3 &rhs);
	Vec3& operator-=(Vec3 &lhs, const Vec3 &rhs);

	Vec3 operator*(const Vec3 &lhs, const Vec3 &rhs);

	Vec3 operator*(const  mat3 &m   , const Vec3 &vec);
	Vec3 operator/ (const Vec3 &lhs, const Vec3 &rhs);

	bool operator==(const Vec3 &lhs, const Vec3 &rhs);
	bool operator!=(const Vec3 &lhs, const Vec3 &rhs);

	bool operator< (const Vec3 &lhs, const Vec3 &rhs);
	bool operator<=(const Vec3 &lhs, const Vec3 &rhs);

	bool operator> (const Vec3 &lhs, const Vec3 &rhs);
	bool operator>=(const Vec3 &lhs, const Vec3 &rhs);



}

