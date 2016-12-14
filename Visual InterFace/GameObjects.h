#pragma once
#include "Component.h"
#include <vector>



namespace bab
{
	

	class GameObjects
	{


		//if the components are active within the object, used to save update time / use
		// [0] Transform    [1] Rigidbody   [2] Collider  [3] Sprite  [4] Lifetime
		bool ActiveComponents[5] = {false};
		bool ActiveObject = true;
		
		//creates the components for your game object
		Components objectComponents;


	public:

		//Basically a function that gets the list of gameObjects
		static std::vector<GameObjects *>& getList()
		{
			static std::vector<GameObjects *> ptrs;
			return ptrs;
		}

		// list of ptrs pointing at your gameObjects
		

		GameObjects *thisObject = &*this;
		GameObjects();

		//Gets the Object's Components
		Components getCom();
		
		//Should update all game object's components
		void UpdateObject();
	};

	
	

	 
}

//GameObjects gameObjects.