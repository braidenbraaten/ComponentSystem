#include "Rectangle.h"

namespace bab
{

	Rectangle::Rectangle()
	{
		Pos.Normalize();
		length = 1;
		width = 1;
	}

	Rectangle::Rectangle(float x, float y, float l, float w)
	{
		Pos.x = x;
		Pos.y = y;
		length = l;
		width = w;

	}

	Rectangle::Rectangle(const Vec2 &p, float l, float w)
	{
		Pos.x = p.x;
		Pos.y = p.y;
		length = l;
		width = w;
	}

	Rectangle::Rectangle(Vec2 min, Vec2 max)
	{
		Pos.x = max.x / 2;
		Pos.y = max.y / 2;
		length = max.x - min.x;
		width = max.y - min.y;
		Min = min;
		Max = max;
	}

	Vec2 Rectangle::getPos() { return Pos; }
	void Rectangle::setPos(float x, float y) { Pos.x = x; Pos.y = y; }
	void Rectangle::setPos(Vec2 vec) { Pos = vec; }
	void Rectangle::setMin(float x, float y) { Min.x = x; Min.y = y; }
	void Rectangle::setMin(Vec2 v) { Min.x = v.x; Min.y = v.y; }
	void Rectangle::setMax(float x, float y) { Max.x = x; Max.y = y; }
	void Rectangle::setMax(Vec2 v) { Max.x = v.x; Max.y = v.y; }
	Vec2 Rectangle::getMin() const { return Min; }
	Vec2 Rectangle::getMax() const { return Max; }


}