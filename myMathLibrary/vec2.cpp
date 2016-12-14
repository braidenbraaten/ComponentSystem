#include "vec2.h"

namespace bab
{

	//uses pythags to give the length of the vector 
	float Vec2::Magnitude()
	{
		
		return sqrtf((x * x) + (y * y));
	}


	Vec2 Vec2::normal()
	{
		Vec2 norm;
		norm.x = x / Magnitude();
		norm.y = y / Magnitude();
		return norm;
	}

	void Vec2::Normalize()
	{
	    this->x = x / Magnitude();
		this->y = y / Magnitude();
	}


	//gives the perp vector from the vector given
	Vec2 Vec2::perp()
	{
		Vec2 newVec;
		newVec.x = -(y);
		newVec.y = x;
		return newVec;
	}


	//if the value is positive than both vecs are Vec2ing in the same direction ,  value = 0 if perp, value = negative if opposite
	float dot(const Vec2 &lhs, const Vec2 &rhs)
	{
		float product = (lhs.x * rhs.x) + (lhs.y * rhs.y);
		return product;
	}



	Vec2 operator+(const Vec2 &lhs, const Vec2 &rhs)
	{
		Vec2 sum;

		sum.x = lhs.x + rhs.x;
		sum.y = lhs.y + rhs.y;
		return sum;
	}

	Vec2 operator+=(Vec2 &lhs, const Vec2 &rhs)
	{
		
		lhs.x += rhs.x;
		lhs.y += rhs.y;

		return lhs;
	}

	Vec2 operator-(const Vec2 &lhs, const Vec2 &rhs)
	{
		Vec2 sum;
		sum.x = lhs.x - rhs.x;
		sum.y = lhs.y - rhs.y;
		return sum;
	}

	Vec2 operator-(Vec2 vec)
	{
		vec.x = -(vec.x);
		vec.y = -(vec.y);
		
		return  vec;
	}

	Vec2 operator-=(Vec2 &lhs, const Vec2 &rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		return lhs;
	}

	Vec2 operator*(const Vec2 &lhs, const Vec2 &rhs)
	{
		Vec2 sum;
		sum.x = lhs.x * rhs.x;
		sum.y = lhs.y * rhs.y;
		return sum;
	}

	Vec2 operator/(const Vec2 &lhs, const Vec2 &rhs)
	{
		Vec2 sum;
		sum.x = lhs.x / rhs.x;
		sum.y = lhs.y / rhs.y;
		return sum;
	}

	bool operator==(const Vec2 &lhs, const Vec2 &rhs)
	{
		if (lhs.x == rhs.x)
		{
			if (lhs.y == rhs.y)
			{
				return true;
			}
		}

		return false;
	}


	bool operator!=(const Vec2 &lhs, const Vec2 &rhs)
	{
		if (lhs.x == rhs.x)
		{
			if (lhs.y == rhs.y)
			{
				return false;
			}
		}

		return true;
	}

	bool operator<(const Vec2 &lhs, const Vec2 &rhs)
	{
		if (lhs.x < rhs.x)
		{
			if (lhs.y < rhs.x)
			{
				return true;
			}
		}
		return false;
	}

	bool operator<=(const Vec2 &lhs, const Vec2 &rhs)
	{
		if (lhs.x <= rhs.x)
		{
			if (lhs.y <= rhs.x)
			{
				return true;
			}
		}
		return false;
	}

	bool operator>(const Vec2 &lhs, const Vec2 &rhs)
	{
		if (lhs.x > rhs.x)
		{
			if (lhs.y > rhs.x)
			{
				return true;
			}
		}
		return false;
	}

	bool operator>=(const Vec2 &lhs, const Vec2 &rhs)
	{
		if (lhs.x >= rhs.x)
		{
			if (lhs.y >= rhs.x)
			{
				return true;
			}
		}
		return false;
	}







}





