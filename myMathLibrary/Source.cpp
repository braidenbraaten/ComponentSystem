#include <iostream>
#include "mat3.h"
#include "mat4.h"
#include "Collision.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace std;
using namespace bab;

int main()
{
	Collision collision;
	Rectangle rec;
	Circle c;
	rec.setMin(1,1);
	rec.setMax(2, 2);
	c.setPos(1, 1);
	c.setRadius(1);

	if (collision.CheckCR(c,rec))
	{
		cout << "there is collision" << endl;
	}
	else
	{
		cout << "there is no collision" << endl;
	}

	system("pause");
}
