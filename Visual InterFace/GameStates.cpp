#include "GameStates.h"

namespace bab
{
	void GameState::addObject()
	{
		 GameObjects::getList().push_back(new GameObjects);
	}

	void GameState::ClearObjects()
	{
		GameObjects::getList().clear();
	}

	void GameState::Update()
	{
		//if the game exits, then clear all objects held in the vector
		if (gameState == EXIT) GameState::ClearObjects();

		//the main loop for the engine
		while (gameState != EXIT)
		{

			switch (gameState)
			{
			case PAUSE:

				break;
			default:
			case PLAY:
				//Update all of the things here
				for (std::vector<GameObjects*>::iterator it = GameObjects::getList().begin(); it != GameObjects::getList().end(); it++)
				{
					//updates all of the objects in the game
					GameObjects::getList().front()->UpdateObject();
				}
					
				break;


			}
		}
	}


	

}