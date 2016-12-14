#pragma once

namespace bab
{
	//so you can have objects that will only be alive / collide with things within a certain time frame or for a certain amount of time
	class LifeTime
	{

		
		//countdown timer
		float aliveTime           = 0;
		float activeCollisionTime = 0;
		//tells us if the object is dead
		bool isAlive = true;



	public:

		LifeTime();
		LifeTime(float);
		void setCollisionLT(float);



		float getAliveTime(     );
		void  setAliveTime(float);

		bool getIsAlive(    );
		void setIsAlive(bool);

		void Update();

	};

}