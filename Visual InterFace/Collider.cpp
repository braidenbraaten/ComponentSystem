#include "Collider.h"
#include "Rectangle.h"
#include "vec2.h"



/*
	this Collider class is setup with the ability to switch between circle and rectangle colliders
*/

namespace bab
{
	Collider::Collider()
	{
		
	}

	Collider::Collider(char input[9])
	{
		if (input == "circle"    || input == "Circle"    || input == "c" || input == "cir") shape = CIRCLE; 
		if (input == "rectangle" || input == "Rectangle" || input == "r" || input == "rec") shape = RECT;
	}

	Collider::Collider(Vec2 pos, float radius)
	{
		shape = CIRCLE;
		circle.setPos   (pos   );
		circle.setRadius(radius);
	}

	Collider::Collider(Vec2 min, Vec2 max)
	{
		shape = RECT;
		rectangle.setMin(min);
		rectangle.setMax(max);
	}

	Vec2 Collider::getColPos()
	{
		switch (shape)
		{
		case CIRCLE:
			return circle.getPos();
			break;

		case RECT:
			return rectangle.getPos();
			break;
		}
	}

	//decides if the colliders shape will draw to the screen or not
	void Collider::isShapeVisible(bool b) { isVisible = b; }

	//returns the type of collider as a char array
	char Collider::getColType()
	{
		return colType[10];
	}

	//Updates the collider / the collision checks for the game objects
	void Collider::Update()
	{
		//Decides if the collider will be visible to the screen
		if (isVisible == true)
		{
			switch (shape)
			{
			case CIRCLE:
				sfw::drawCircle(circle.getPos().x, circle.getPos().y, circle.getRadius(), 13, CYAN);
				break;

			case RECT:
				sfw::drawLine(rectangle.getMin().x, rectangle.getMax().y, rectangle.getMax().x, rectangle.getMax().y, CYAN);
				sfw::drawLine(rectangle.getMax().x, rectangle.getMax().y, rectangle.getMax().x, rectangle.getMin().y, CYAN);
				sfw::drawLine(rectangle.getMax().x, rectangle.getMin().y, rectangle.getMin().x, rectangle.getMin().y, CYAN);
				sfw::drawLine(rectangle.getMin().x, rectangle.getMin().y, rectangle.getMin().x, rectangle.getMax().y, CYAN);
				break;
			case EMPTY:
				break;
			}
		}
	}


}