#pragma once
#include "vec2.h"
namespace bab
{
	

	class Circle
	{
		Vec2 P;
		float radius;
	public:
		Circle(Vec2,float);
		Circle();

		Vec2 getPos();
		void setPos(float x, float y);
		void setPos(const Vec2&);

		float getRadius();
		void setRadius(float);

		
	};

}