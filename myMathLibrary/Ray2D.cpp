#include "Ray2D.h"


namespace bab
{

	
	Vec2 Ray2D::getPos() { return Pos; }
	void Ray2D::setPos(const Vec2& v) { Pos = v; }

	Ray2D::Ray2D(const Vec2& p, const Vec2& d, float f) 
	{
		Pos = p; Direction = d; Length = f;
	}

	Vec2 Ray2D::getDirection() { return Direction; }
	void Ray2D::setDirection(const Vec2& v) { Direction = v; }

	float Ray2D::getLength() { return Length; }
	void Ray2D::setLength(float f) { Length = f; }

}