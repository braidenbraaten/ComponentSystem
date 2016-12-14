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

	Vec4 operator* (const mat4 &m, const Vec4 &vec)
	{
		Vec4 result;
		result.x = (m.Matrix[0][0] * vec.x) + (m.Matrix[0][1] * vec.y) + (m.Matrix[0][2] * vec.z) + (m.Matrix[0][3] * vec.w);
		result.y = (m.Matrix[1][0] * vec.x) + (m.Matrix[1][1] * vec.y) + (m.Matrix[1][2] * vec.z) + (m.Matrix[1][3] * vec.w);
		result.z = (m.Matrix[2][0] * vec.x) + (m.Matrix[2][1] * vec.y) + (m.Matrix[2][2] * vec.z) + (m.Matrix[2][3] * vec.w);
		result.w = (m.Matrix[3][0] * vec.x) + (m.Matrix[3][1] * vec.y) + (m.Matrix[3][2] * vec.z) + (m.Matrix[3][3] * vec.w);
		


		return result;
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