#pragma once
#include "vec2.h"
namespace bab
{
	class Ray2D
	{
	public:
		Vec2  Pos;
		Vec2  Direction;
		float Length;
		Vec2 getPos();
		void setPos(const Vec2&);
		Ray2D(const Vec2&, const Vec2&, float);
		Vec2 getDirection();
		void setDirection(const Vec2&);

		float getLength();
		void  setLength(float);

	};

}