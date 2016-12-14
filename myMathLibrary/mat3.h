#pragma once
#include <cmath>

namespace bab
{
	struct mat3
	{
		const static int rows = 3;
		const static int columns = 3;
		float Matrix[3][3] =
		{
			1, 0, 0,
			0, 1, 0,
			0, 0, 1
		};

		float* ptr = &Matrix[0][0];
		void Identity();
		mat3 operator=(const mat3&);
		float Determinant();
		mat3 coFactors();
		mat3 Inverse();
		mat3 Transpose();
		mat3 diagonalFlip();
		void Randomize();

		mat3 Scale(float, float);
		mat3 Rotate(float);
		mat3 Translate(float, float);
	};


	mat3   operator+(const mat3&, const mat3&);
	mat3   operator+=(mat3&, const mat3&);
	mat3   operator-(const mat3&, const mat3&);
	mat3   operator-=(mat3&, const mat3&);
	mat3   operator*(const mat3&, const mat3&);

	mat3   operator*=(mat3&, const mat3&);

}