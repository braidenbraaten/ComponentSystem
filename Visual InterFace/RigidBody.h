#pragma once
#include "vec2.h"
#include "sfwdraw.h"
namespace bab
{
	class RigidBody
	{
		//Linear distance
		float Distance;
		float Time = sfw::getTime() - sfw::getDeltaTime();
		float Vel = Distance / Time;
		Vec2 Force;
		Vec2 Torque;
		Vec2 Acceleration;
		Vec2 Velocity = { Vel, Vel };

	public:
		RigidBody();


	};


}