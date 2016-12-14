#pragma once
#include "GameObjects.h"


namespace bab
{
	

	class GameState
	{

	private:
		enum GAME_STATE       {PLAY, EXIT, PAUSE};
		GAME_STATE gameState = PLAY;

	public:
		//instantiates a new gameobject in the game 
		void addObject();

		//updates the game (is the update function that encompasses all of the other updates,
		//except for the sfw calls)
		void Update();

		//deletes all of the objects in the game
		void ClearObjects();
		

	};

}