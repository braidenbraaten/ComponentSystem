#include "mat3.h"
#include "vec3.h"
#include <ctime>

namespace bab
{
	void mat3::Identity()
	{
		//Diagonal values set to 1
		this->Matrix[0][0] = 1;
		this->Matrix[1][1] = 1;
		this->Matrix[2][2] = 1;
		//rest of the matrix values set to 0
		this->Matrix[0][1] = 0;
		this->Matrix[0][2] = 0;
		this->Matrix[1][0] = 0;
		this->Matrix[1][2] = 0;
		this->Matrix[2][0] = 0;
		this->Matrix[2][1] = 0;

	}

	float mat3::Determinant()
	{
		float D = this->Matrix[0][0] * (this->Matrix[1][1] * this->Matrix[2][2] - this->Matrix[1][2] * this->Matrix[2][1]) - this->Matrix[0][1] * (this->Matrix[1][0] *  this->Matrix[2][2] - this->Matrix[1][2] * this->Matrix[2][0]) + this->Matrix[0][2] * (this->Matrix[1][0] * this->Matrix[2][1] - this->Matrix[1][1] * this->Matrix[2][0]);
		return D;
	}

	mat3 mat3::coFactors()
	{
		mat3 result;
		//Row 1
		result.Matrix[0][0] = +(this->Matrix[1][1] * this->Matrix[2][2] - this->Matrix[1][2] * this->Matrix[2][1]);
		result.Matrix[0][1] = -(this->Matrix[1][0] * this->Matrix[2][2] - this->Matrix[1][2] * this->Matrix[0][2]);
		result.Matrix[0][2] = +(this->Matrix[1][0] * this->Matrix[2][1] - this->Matrix[1][1] * this->Matrix[2][0]);
		//Row 2
		result.Matrix[1][0] = -(this->Matrix[0][1] * this->Matrix[2][2] - this->Matrix[0][2] * this->Matrix[2][1]);
		result.Matrix[1][1] = +(this->Matrix[0][0] * this->Matrix[2][2] - this->Matrix[0][2] * this->Matrix[2][0]);
		result.Matrix[1][2] = -(this->Matrix[0][0] * this->Matrix[2][1] - this->Matrix[0][1] * this->Matrix[2][0]);
		//Row 3
		result.Matrix[2][0] = +(this->Matrix[0][1] * this->Matrix[1][2] - this->Matrix[0][2] * this->Matrix[1][1]);
		result.Matrix[2][1] = -(this->Matrix[0][0] * this->Matrix[1][2] - this->Matrix[0][2] * this->Matrix[1][0]);
		result.Matrix[2][2] = +(this->Matrix[0][0] * this->Matrix[1][1] - this->Matrix[0][1] * this->Matrix[1][0]);
		return result;
	}


	//Answer is in Approximate form
	mat3 mat3::Inverse()
	{
		mat3 result = this->coFactors();
		result.diagonalFlip();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.Matrix[i][j] *= (1 / this->Determinant());
			}
		}
		return result;
	}

	//flips the rows and columns, and in this case will not change the actual value of this-> matrix
	mat3 mat3::Transpose()
	{
		mat3 result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.Matrix[i][j] = this->Matrix[j][i];
			}
		}
		return result;

	}

	mat3 mat3::diagonalFlip()
	{
		mat3 result = *this;
		result.Matrix[0][1] = this->Matrix[1][0];
		result.Matrix[0][2] = this->Matrix[2][0];
		result.Matrix[1][0] = this->Matrix[0][1];

		result.Matrix[1][2] = this->Matrix[2][1];
		result.Matrix[2][0] = this->Matrix[0][2];
		result.Matrix[2][1] = this->Matrix[1][2];

		return result;
	}


	//Fills the matrix with numbers 1-25 instead of the identity mat
	void mat3::Randomize()
	{
		srand(time(NULL));
		int RNG = rand() % 25 + 1;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				RNG = rand() % 25 + 1;
				this->Matrix[i][j] = RNG;
			}
		}
	}


	mat3 mat3::Scale(float x, float y)
	{
		mat3 result;

		if (x == 0) { x = 1; }
		if (y == 0) { y = 1; }
		//sets the values to the Identity matrix
		result.Matrix[0][0] = x;
		result.Matrix[1][1] = y;


		return *this * result;




	}

	mat3 mat3::Rotate(float r)
	{
		mat3 result;
		result.Matrix[0][0] = cosf(r);
		result.Matrix[0][1] = -sinf(r);
		result.Matrix[1][0] = sinf(r);
		result.Matrix[1][1] = cosf(r);

		return *this * result;
	}

	mat3 mat3::Translate(float x, float y)
	{
		mat3 result;
		result.Matrix[0][2] = x;
		result.Matrix[1][2] = y;

		return *this * result;
	}

	// ////////////////////Outside of the Struct Functions\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/


	mat3 mat3::operator=(const mat3 &rhs)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				this->Matrix[i][j] = rhs.Matrix[i][j];
			}
		}
		return *this;
	}




	mat3 operator+(const mat3 &a, const mat3 &b)
	{
		mat3 sum;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				sum.Matrix[i][j] = (a.Matrix[i][j] + b.Matrix[i][j]);
			}
		}
		return sum;
	}

	mat3 operator+=(mat3 &lhs, const mat3 &rhs) { lhs = lhs + rhs; return lhs; }

	mat3 operator-(const mat3 &a, const mat3 &b)
	{
		mat3 sum;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				sum.Matrix[i][j] = (a.Matrix[i][j] - b.Matrix[i][j]);
			}
		}
		return sum;
	}

	mat3 operator-=(mat3 &lhs, const mat3 &rhs) { lhs = lhs - rhs; return lhs; }

	mat3 operator*(const mat3 &a, const mat3 &b)
	{
		mat3 Result;
		//Row 1
		Result.Matrix[0][0] = ((a.Matrix[0][0] * b.Matrix[0][0]) + (a.Matrix[0][1] * b.Matrix[1][0]) + (a.Matrix[0][2] * b.Matrix[2][0]));
		Result.Matrix[0][1] = ((a.Matrix[0][0] * b.Matrix[0][1]) + (a.Matrix[0][1] * b.Matrix[1][1]) + (a.Matrix[0][2] * b.Matrix[2][1]));
		Result.Matrix[0][2] = ((a.Matrix[0][0] * b.Matrix[0][2]) + (a.Matrix[0][1] * b.Matrix[1][2]) + (a.Matrix[0][2] * b.Matrix[2][2]));
		//Row 2
		Result.Matrix[1][0] = ((a.Matrix[1][0] * b.Matrix[0][0]) + (a.Matrix[1][1] * b.Matrix[1][0]) + (a.Matrix[1][2] * b.Matrix[2][0]));
		Result.Matrix[1][1] = ((a.Matrix[1][0] * b.Matrix[0][1]) + (a.Matrix[1][1] * b.Matrix[1][1]) + (a.Matrix[1][2] * b.Matrix[2][1]));
		Result.Matrix[1][2] = ((a.Matrix[1][0] * b.Matrix[0][2]) + (a.Matrix[1][1] * b.Matrix[1][2]) + (a.Matrix[1][2] * b.Matrix[2][2]));
		//Row 3
		Result.Matrix[2][0] = ((a.Matrix[2][0] * b.Matrix[0][0]) + (a.Matrix[2][1] * b.Matrix[1][0]) + (a.Matrix[2][2] * b.Matrix[2][0]));
		Result.Matrix[2][1] = ((a.Matrix[2][0] * b.Matrix[0][1]) + (a.Matrix[2][1] * b.Matrix[1][1]) + (a.Matrix[2][2] * b.Matrix[2][1]));
		Result.Matrix[2][2] = ((a.Matrix[2][0] * b.Matrix[0][2]) + (a.Matrix[2][1] * b.Matrix[1][2]) + (a.Matrix[2][2] * b.Matrix[2][2]));

		return Result;
	}



	mat3 operator*=(mat3& lhs, const mat3& rhs) { lhs = lhs * rhs; return lhs; }



}





