#pragma once
#include <cmath>
namespace bab
{
	struct Vec2 {float x, y;
	
	Vec2 normal(); // gives what the norm would be
	float Magnitude();
	Vec2 perp(); // <-y, x>
	void Normalize();//changes the x and y to 1

	};



	float dot(const Vec2 &lhs, const  Vec2 &rhs);


	Vec2 operator-(Vec2 vec); //<-x, -y>

	

	Vec2 operator+ (const Vec2 &lhs, const Vec2 &rhs);
	Vec2 operator+=(Vec2 &lhs, const Vec2 &rhs);

	Vec2 operator- (const Vec2 &lhs, const Vec2 &rhs);
	Vec2 operator-=(Vec2 &lhs, const Vec2 &rhs);

	Vec2 operator* (const Vec2 &lhs, const Vec2 &rhs);
	Vec2 operator/ (const Vec2 &lhs, const Vec2 &rhs);

	bool operator==(const Vec2 &lhs, const Vec2 &rhs);
	bool operator!=(const Vec2 &lhs, const Vec2 &rhs);

	bool operator< (const Vec2 &lhs, const Vec2 &rhs);
	bool operator<=(const Vec2 &lhs, const Vec2 &rhs);


	bool operator> (const Vec2 &lhs, const Vec2 &rhs);
	bool operator>=(const Vec2 &lhs, const Vec2 &rhs);


}


