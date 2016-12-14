#include "Collision.h"

namespace bab
{
	float  Collision::dist(const Vec2& a, const Vec2& b)
	{
		float distance;
		distance = sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
		return distance;
	}


	//Even though it is using a template, this clamp function is optomized for 2D vectors
	template <typename T>
	T Collision::clamp(T value, T min,T max)
	{
			if (value.x < min.x) value.x = min.x;
			if (value.x > max.x) value.x = max.x;
			if (value.y < min.y) value.y = min.y;
			if (value.y > max.y) value.y = max.y;
		
		return value;
	}

	bool Collision::CheckCC(const Vec2& p1, float r1, const Vec2& p2, float r2) {return (dist(p1, p2) <= r1 + r2);}

	bool Collision::CheckCC(Circle& a, Circle& b) { return (dist(a.getPos(),b.getPos()) <= a.getRadius() + b.getRadius()); }


	bool Collision::CheckCR(const Vec2& p1, float r1, Vec2 min, Vec2 max)
	{
		Vec2 pc = clamp<Vec2>(p1, min, max);

		return (dist(p1, pc) <= r1);
		 //return (dot(p1, pc) <= (r1 * r1));
	}

	bool Collision::CheckCR(Circle& c, Rectangle& r) 
	{
		return CheckCR(c.getPos(), c.getRadius(), Vec2{ r.getMin().x, r.getMin().y }, Vec2{ r.getMax().x, r.getMax().y });
	}

	bool Collision::AABB(const Vec2& aMin, const Vec2& aMax, const Vec2& bMin, const Vec2& bMax) {return (aMax > bMin && bMin > aMin || bMax > aMin && bMin < aMin);}
	
	bool Collision::AABB(const Rectangle& a, const  Rectangle& b) {return (a.getMax() > b.getMin() && b.getMin() > a.getMin() || b.getMax() > a.getMin() && b.getMin() < a.getMin());}

											//the Collision Check for Circle vs Plane may be wrong, Can't tell if it is a multiplication or dot product

	bool Collision::CheckCP(const Vec2& cPos, float cRadius, const Vec2& pPos, const Vec2& pNorm) { return ( dot(cPos, pPos) <= cRadius); }
}