#pragma once
#include "vec2.h"
namespace bab
{
	class Plane2D
	{
	public:
		Vec2 Pos;
		Vec2 PlaneNormal = Pos.normal();

		Plane2D(const Vec2&);

		Vec2 getPlaneNormal();
		void setPlaneNormal(const Vec2&);

	};




}