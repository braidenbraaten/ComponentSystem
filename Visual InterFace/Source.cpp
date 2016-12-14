#include "sfwdraw.h"
#include "Circle.h"
#include "vec2.h"
#include "Rectangle.h"
#include "Collision.h"
#include "Ray2D.h"
#include "GameObjects.h"
#include <vector>
#include <cassert>
#include "Sprite.h"
#include <iostream>

bab::Rectangle rectangle;
bab::Collision collision;
void DrawRectangle(const bab::Rectangle& rec)
{
	sfw::drawLine(rec.getMin().x, rec.getMax().y, rec.getMax().x, rec.getMax().y, CYAN);
	sfw::drawLine(rec.getMax().x, rec.getMax().y, rec.getMax().x, rec.getMin().y, CYAN);
	sfw::drawLine(rec.getMax().x, rec.getMin().y, rec.getMin().x, rec.getMin().y, CYAN);
	sfw::drawLine(rec.getMin().x, rec.getMin().y, rec.getMin().x, rec.getMax().y, CYAN);
}



bab::GameObjects Player;




const int Width = 800;
const int Height = 600;

static bool hasHappened = false;
static bool hasHappenedUp = false;
int main()
{

	Player.getCom().getSprite().setSpritePath("./res/cat.jpg");
	Player.getCom().getSprite().setPos(Player.getCom().getTransform().getPosition());

	sfw::initContext();

	std::string bob = "hi";
	bob = Player.getCom().getSprite().getFilePath();
	
	while (sfw::stepContext())
	{
		std::cout << bob << std::endl;

	};

	sfw::termContext();
	
}