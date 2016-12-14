#pragma once
#include <string>
#include "vec2.h"

namespace bab
{
	class Sprite
	{
		//Name for the sprite
		float Width       = 0;
		float Height      = 0;
		float rotation    = 0;
		unsigned int tint = 0;
		//Sprite scale, starts at a 1:1 scale
		Vec2 scale =    {1,1};
		//Sprite pos
		Vec2 pos   =    {0,0};

		//going with a non centered texture pos

		//the name handle for the sprite in order to fetch info about it from SFW
		//it holds the filepath for the texture
		unsigned handle;
		std::string filePath = {};

	public:
		Sprite();
		Sprite(std::string);
		Sprite(std::string, int, int);

		
		void setSpritePath(std::string);

		unsigned int getWidth();
		void setWidth(float);

		unsigned int getHeight();
		void setHeight(float);
		
		float getRotation();
		void setRotation(float);

		unsigned int getTint();
		void setTint(unsigned int);

		Vec2 getScale();
		void setScale(Vec2);

		Vec2 getPos();
		void setPos(Vec2);

		std::string getFilePath();

		void Update();
			
	};

}