#include "vec4.h"


namespace bab
{
	float Vec4::Magnitude()
	{
		return sqrtf((x * x) + (y * y) + (z * z) + (w * w));
	}

	Vec4 Vec4::normal()
	{
		Vec4 norm;
		norm.x = x / Magnitude();
		norm.y = y / Magnitude();
		norm.z = z / Magnitude();
		norm.w = w / Magnitude();
		return norm;
	}

	void Vec4::Normalize()
	{
		x = x / Magnitude();
		y = y / Magnitude();
		z = z / Magnitude();
		w = w / Magnitude();
	}

	float dot(const Vec4 &lhs, const Vec4 &rhs)
	{
		return ((lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w));
	}

	Vec4 operator+ (const Vec4 &lhs, const Vec4 &rhs)
	{
		Vec4 sum;
		sum.x = lhs.x + rhs.x;
		sum.y = lhs.y + rhs.y;
		sum.z = lhs.z + rhs.z;
		sum.w = lhs.w + rhs.w;
		return sum;
	}
	Vec4& operator+=(Vec4 &lhs, const Vec4 &rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;
		lhs.w += rhs.w;
		return lhs;
	}

	Vec4 operator-(Vec4 vec)
	{
		return{ -vec.x, -vec.y, -vec.z, -vec.w };
	}

	Vec4 operator- (const Vec4 &lhs, const Vec4 &rhs)
	{
		Vec4 sum;
		sum.x = lhs.x - rhs.x;
		sum.y = lhs.y - rhs.y;
		sum.z = lhs.z - rhs.z;
		sum.w = lhs.w - rhs.w;
		return sum;
	}
	Vec4& operator-=(Vec4 &lhs, const Vec4 &rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;
		lhs.w -= rhs.w;
		return lhs;
	}

	Vec4 operator* (const Vec4 &lhs, const Vec4 &rhs)
	{
		Vec4 sum;
		sum.x = lhs.x * rhs.x;
		sum.y = lhs.y * rhs.y;
		sum.z = lhs.z * rhs.z;
		sum.w = lhs.w * rhs.w;
		return sum;
	}



	Vec4 operator/ (const Vec4 &lhs, const Vec4 &rhs) 
	{
		Vec4 sum; 
		sum.x = lhs.x / rhs.x;
		sum.y = lhs.y / rhs.y;
		sum.z = lhs.z / rhs.z;
		sum.w = lhs.w / rhs.w;
		return sum;
	}

	bool operator==(const Vec4 &lhs, const Vec4 &rhs) { return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w) ? true : false; }

	bool operator!=(const Vec4 &lhs, const Vec4 &rhs) { return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w) ? false : true; }

	bool operator<(const Vec4 &lhs, const Vec4 &rhs) { return (lhs.x < rhs.x && lhs.y < rhs.y && lhs.z < rhs.z && lhs.w < rhs.w) ? true : false; }

	bool operator<=(const Vec4 &lhs, const Vec4 &rhs) { return (lhs.x <= rhs.x && lhs.y <= rhs.y && lhs.z <= rhs.z && lhs.w <= rhs.w) ? true : false; }

	bool operator>(const Vec4 &lhs, const Vec4 &rhs) {return (lhs.x > rhs.x && lhs.y > rhs.y && lhs.z > rhs.z && lhs.w > rhs.w) ? true : false;}
		
	bool operator>=(const Vec4 &lhs, const Vec4 &rhs) { return (lhs.x >= rhs.x && lhs.y >= rhs.y && lhs.z >= rhs.z && lhs.w >= rhs.w) ? true : false; }



}