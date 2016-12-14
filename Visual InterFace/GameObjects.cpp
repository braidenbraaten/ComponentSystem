#include "GameObjects.h"

namespace bab
{
	GameObjects::GameObjects()
	{
		//Adds this object to the object list
		getList().push_back(thisObject);

		
		
	}
	//update the object's components here
	
	Components GameObjects::getCom()
	{
		return objectComponents;
	}


	void GameObjects::UpdateObject()
	{
		//trying to iterate through the vector until it finds this object and only updates this object
		for (std::vector<GameObjects*>::iterator it = GameObjects::getList().begin(); *it != this->thisObject; it++)
		{
			if (*it == this->thisObject)
			{   //finished
				if(this->ActiveComponents[0] == true) GameObjects::getList().front()->objectComponents.getTransform().Update();
				if(this->ActiveComponents[2] == true) GameObjects::getList().front()->objectComponents.getCollider().Update();
				if(this->ActiveComponents[3] == true) GameObjects::getList().front()->objectComponents.getSprite().Update();
				if(this->ActiveComponents[4] == true) GameObjects::getList().front()->objectComponents.getLifeTime().Update();
				//unfinished
				if(this->ActiveComponents[1] == true) GameObjects::getList().front()->objectComponents.getRigidBody();
			}
		}
	}





}