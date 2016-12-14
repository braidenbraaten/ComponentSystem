#pragma once
#include <cmath>
#include "mat4.h"
//namespace for my own math library 
namespace bab
{
	struct Vec4
	{
		float x, y, z, w;
		Vec4 normal();
		float Magnitude();
		void Normalize();

	};

	float dot(const Vec4 &lhs, const Vec4 &rhs);

	Vec4 operator-(Vec4 vec); //<-x, -y>



	Vec4 operator+ (const Vec4 &lhs, const Vec4 &rhs);
	Vec4& operator+=(Vec4 &lhs, const Vec4 &rhs);

	Vec4 operator- (const Vec4 &lhs, const Vec4 &rhs);
	Vec4& operator-=(Vec4 &lhs, const Vec4 &rhs);

	Vec4 operator* (const Vec4 &lhs, const Vec4 &rhs);
	Vec4 operator* (const mat4 &m, const Vec4 &vec);

	Vec4 operator/ (const Vec4 &lhs, const Vec4 &rhs);

	bool operator==(const Vec4 &lhs, const Vec4 &rhs);
	bool operator!=(const Vec4 &lhs, const Vec4 &rhs);

	bool operator< (const Vec4 &lhs, const Vec4 &rhs);
	bool operator<=(const Vec4 &lhs, const Vec4 &rhs);

	bool operator> (const Vec4 &lhs, const Vec4 &rhs);
	bool operator>=(const Vec4 &lhs, const Vec4 &rhs);



}