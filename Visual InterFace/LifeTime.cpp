#include "LifeTime.h"

namespace bab
{
	//Constructors

	LifeTime::LifeTime()
	{
		//Setting the default timer to 10 seconds
		aliveTime = 10;
		isAlive = true;
	}

	LifeTime::LifeTime(float setTimer)
	{
		aliveTime = setTimer;
	}


	// Member Functions

	void LifeTime::setCollisionLT(float coll_timer)
	{
		activeCollisionTime = coll_timer;
	}

	float LifeTime::getAliveTime()
	{
		return aliveTime;
	}

	void LifeTime::setAliveTime(float alive_time)
	{
		aliveTime = alive_time;
	}

	bool LifeTime::getIsAlive()
	{
		return isAlive;
	}

	void LifeTime::setIsAlive(bool is_alive)
	{
		isAlive = is_alive;
	}

	void LifeTime::Update()
	{
		if (isAlive == true)
		{
			
		}
	}

}