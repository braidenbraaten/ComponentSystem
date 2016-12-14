#include "Plane2D.h"
namespace bab 
{

	Plane2D::Plane2D(const Vec2& p)
	{
		Pos = p;
	}

	Vec2 Plane2D::getPlaneNormal() { return PlaneNormal; }
	void Plane2D::setPlaneNormal(const Vec2& v) { PlaneNormal = v; }

}