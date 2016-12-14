#pragma once
namespace bab
{
	struct mat4
	{
		const static int rows = 4;
		const static int columns = 4;
		float Matrix[rows][columns] =
		{
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		float* ptr = &Matrix[0][0];
		void Identity();
		mat4 operator=(const mat4&);
		float Determinant();
		mat4 coFactors();
		mat4 Inverse();
		mat4 Transpose();
		mat4 diagonalFlip();
		void Randomize();

		void Scale(float, float, float);
		void Rotate(char, float);

		//The Difference between the two is that translate will move x,y, and z away from the Vec2 it is currently at
		//While MoveTo will move the matrix to the exact location specified no matter where it is currently
		void Translate(float, float,float);
		void MoveTo(float, float, float);
	};

	mat4   operator+(const mat4&, const mat4&);
	mat4   operator+=(mat4&, const mat4&);
	mat4   operator-(const mat4&, const mat4&);
	mat4   operator-=(mat4&, const mat4&);
	mat4   operator*(const mat4&, const mat4&);

	mat4   operator*=(mat4&, const mat4&);

}