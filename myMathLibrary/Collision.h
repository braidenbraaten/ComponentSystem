#pragma once
#include "Circle.h"
#include "Rectangle.h"
#include "vec2.h"
#include "Ray2D.h"
#include "Plane2D.h"

namespace bab
{
	//This is a commit test
	class Collision
	{
	public:

		float dist(const Vec2&, const Vec2&);
		//   allows you to clamp values 
		template <typename T>
		T clamp(T value,T min,T max);
		
		//   Check Circle Circle Collision
		bool CheckCC(const Vec2&, float, const Vec2&, float);
		bool CheckCC( Circle&,  Circle&);
		
		//   Check Circle Rectangle Collision
		bool CheckCR(const Vec2&, float, Vec2, Vec2);
		bool CheckCR( Circle&,  Rectangle&);
		
		//   Check Rectangle Rectangle Collision
		bool AABB(const Vec2&, const Vec2&, const Vec2&, const Vec2&);
		bool AABB(const Rectangle&, const Rectangle&);

		//Circle vs Plane Collision
		bool CheckCP(const Vec2&, float, const Vec2&, const Vec2&);
	};
}