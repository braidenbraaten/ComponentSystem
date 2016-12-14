#include "Circle.h"


namespace bab
{
	Circle::Circle(Vec2 v, float r)
	{
		P.x = v.x;
		P.y = v.y;
		radius = r;
	}

	Circle::Circle()
	{
		P.Normalize();
		radius = 1;
	}

	Vec2 Circle::getPos() {return P;}

	void Circle::setPos(float x, float y)
	{
		P.x = x;
		P.y = y;
	}
	void Circle::setPos(const Vec2 &vec) {P = vec;}

	float Circle::getRadius() {return radius;}

	void Circle::setRadius(float r) { radius = r; }

}
