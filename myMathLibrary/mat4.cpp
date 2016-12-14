#include "mat4.h"
#include "mat3.h"
#include "vec4.h"
#include <stdlib.h>
#include <ctime>

namespace bab
{
	void mat4::Identity()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				this->Matrix[i][j] = 0;
			}
		}

		this->Matrix[0][0] = 1;
		this->Matrix[1][1] = 1;
		this->Matrix[2][2] = 1;
		this->Matrix[3][3] = 1;
	}

	mat4 mat4::operator=(const mat4 &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				this->Matrix[i][j] = rhs.Matrix[i][j];
			}
		}

		return *this;
	}

	float mat4::Determinant()
	{
		float D = 0;
		mat3 m3[4] = {};
		m3[0].Matrix[0][0] = this->Matrix[1][1]; m3[0].Matrix[0][1] = this->Matrix[1][2]; m3[0].Matrix[0][2] = this->Matrix[1][3];
		m3[0].Matrix[1][0] = this->Matrix[2][1]; m3[0].Matrix[1][1] = this->Matrix[2][2]; m3[0].Matrix[1][2] = this->Matrix[2][3];
		m3[0].Matrix[2][0] = this->Matrix[3][1]; m3[0].Matrix[2][1] = this->Matrix[3][2]; m3[0].Matrix[2][2] = this->Matrix[3][3];

		m3[1].Matrix[0][0] = this->Matrix[1][0]; m3[1].Matrix[0][1] = this->Matrix[1][2]; m3[1].Matrix[0][2] = this->Matrix[1][3];
		m3[1].Matrix[1][0] = this->Matrix[2][0]; m3[1].Matrix[1][1] = this->Matrix[2][2]; m3[1].Matrix[1][2] = this->Matrix[2][3];
		m3[1].Matrix[2][0] = this->Matrix[3][0]; m3[1].Matrix[2][1] = this->Matrix[3][2]; m3[1].Matrix[2][2] = this->Matrix[3][3];

		m3[2].Matrix[0][0] = this->Matrix[1][0]; m3[2].Matrix[0][1] = this->Matrix[1][1]; m3[2].Matrix[0][2] = this->Matrix[1][3];
		m3[2].Matrix[1][0] = this->Matrix[2][0]; m3[2].Matrix[1][1] = this->Matrix[2][1]; m3[2].Matrix[1][2] = this->Matrix[2][3];
		m3[2].Matrix[2][0] = this->Matrix[3][0]; m3[2].Matrix[2][1] = this->Matrix[3][1]; m3[2].Matrix[2][2] = this->Matrix[3][3];

		m3[3].Matrix[0][0] = this->Matrix[1][0]; m3[3].Matrix[0][1] = this->Matrix[1][1]; m3[3].Matrix[0][2] = this->Matrix[1][2];
		m3[3].Matrix[1][0] = this->Matrix[2][0]; m3[3].Matrix[1][1] = this->Matrix[2][1]; m3[3].Matrix[1][2] = this->Matrix[2][2];
		m3[3].Matrix[2][0] = this->Matrix[3][0]; m3[3].Matrix[2][1] = this->Matrix[3][1]; m3[3].Matrix[2][2] = this->Matrix[3][2];

		D = m3[0].Determinant() + -m3[1].Determinant() + m3[2].Determinant() + -m3[3].Determinant();
		return D;
	
	}


	mat4 mat4::Transpose()
	{
		mat4 result = *this;
		Vec4 row[4] = {};


		
		for (int j = 0; j < 4; j++)
		{
			row[j].x = result.Matrix[j][0];
			row[j].y = result.Matrix[j][1];
			row[j].z = result.Matrix[j][2];
			row[j].w = result.Matrix[j][3];
		}

		for (int j = 0; j < 4; j++)
		{
			result.Matrix[0][j] = row[j].x;
			result.Matrix[1][j] = row[j].y;
			result.Matrix[2][j] = row[j].z;
			result.Matrix[3][j] = row[j].w;
		}

		
		

		return result;
	}



	mat4 mat4::diagonalFlip()
	{
		mat4 result = *this;
		result.Matrix[0][1] = this->Matrix[1][0];
		result.Matrix[0][2] = this->Matrix[2][0];
		result.Matrix[0][3] = this->Matrix[3][0];

		result.Matrix[1][0] = this->Matrix[0][1];
		result.Matrix[1][2] = this->Matrix[2][1];
		result.Matrix[1][3] = this->Matrix[3][1];

		result.Matrix[2][0] = this->Matrix[0][2];
		result.Matrix[2][1] = this->Matrix[1][2];
		result.Matrix[2][3] = this->Matrix[3][2];

		result.Matrix[3][0] = this->Matrix[0][3];
		result.Matrix[3][1] = this->Matrix[1][3];
		result.Matrix[3][2] = this->Matrix[2][3];



		return result;
	}

	void mat4::Randomize()
	{
		srand(time(NULL));
		

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int RNG = rand() % 25 + 1;
				this->Matrix[i][j] = RNG;
			}
		}

	}

	void mat4::Scale(float x, float y, float z)
	{
		this->Matrix[0][0] = this->Matrix[0][0] * x;
		this->Matrix[1][1] = this->Matrix[1][1] * y;
		this->Matrix[2][2] = this->Matrix[2][2] * z;

	}



	void mat4::Rotate(char axis,float degrees)
	{
		if (axis == 'x' || axis == 'X')
		{
			this->Matrix[1][1] = cosf(degrees);
			this->Matrix[1][2] = -sinf(degrees);
			this->Matrix[2][1] = sinf(degrees);
			this->Matrix[2][2] = cosf(degrees);
		}

		if (axis == 'y' || axis == 'y')
		{
			this->Matrix[0][0] = cosf(degrees);
			this->Matrix[0][2] = sinf(degrees);
			this->Matrix[2][0] = -sinf(degrees);
			this->Matrix[2][2] = cosf(degrees);
		}

		if (axis == 'z' || axis == 'z')
		{
			this->Matrix[0][0] = cosf(degrees);
			this->Matrix[0][1] = -sinf(degrees);
			this->Matrix[1][0] = sinf(degrees);
			this->Matrix[1][1] = cosf(degrees);
		}

		
	}

	void mat4::Translate(float x, float y, float z)
	{
		this->Matrix[0][3] += x;
		this->Matrix[1][3] += y;
		this->Matrix[2][3] += z;
	}

	void mat4::MoveTo(float x, float y, float z)
	{
		this->Matrix[0][3] = x;
		this->Matrix[1][3] = y;
		this->Matrix[2][3] = z;
	}



	/* //////////////////////////////////////Out of the Struct Functions\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */

	mat4 operator+(const mat4 &lhs, const mat4 &rhs) { mat4 sum; for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++) { sum.Matrix[i][j] = lhs.Matrix[i][j] + rhs.Matrix[i][j]; } }return sum; }

	mat4 operator+=(mat4& lhs, const mat4& rhs) { for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++) { lhs.Matrix[i][j] += rhs.Matrix[i][j]; } }return lhs; }

	mat4 operator-(const mat4 &lhs, const mat4 &rhs) { mat4 total; for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++) { total.Matrix[i][j] = lhs.Matrix[i][j] - rhs.Matrix[i][j]; } } return total; }

	mat4 operator-=(mat4 &lhs, const mat4 &rhs) { for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++) { lhs.Matrix[i][j] -= rhs.Matrix[i][j]; } } return lhs; }

	mat4 operator*(const mat4&a, const mat4&b)
	{
		mat4 Result;
		Result.Matrix[0][0] = ((a.Matrix[0][0] * b.Matrix[0][0]) + (a.Matrix[0][1] * b.Matrix[1][0]) + (a.Matrix[0][2] * b.Matrix[2][0]) + (a.Matrix[0][3] * b.Matrix[3][0]));
		Result.Matrix[0][1] = ((a.Matrix[0][0] * b.Matrix[0][1]) + (a.Matrix[0][1] * b.Matrix[1][1]) + (a.Matrix[0][2] * b.Matrix[2][1]) + (a.Matrix[0][3] * b.Matrix[3][1]));
		Result.Matrix[0][2] = ((a.Matrix[0][0] * b.Matrix[0][2]) + (a.Matrix[0][1] * b.Matrix[1][2]) + (a.Matrix[0][2] * b.Matrix[2][2]) + (a.Matrix[0][3] * b.Matrix[3][2]));
		Result.Matrix[0][3] = ((a.Matrix[0][0] * b.Matrix[0][3]) + (a.Matrix[0][1] * b.Matrix[1][3]) + (a.Matrix[0][2] * b.Matrix[2][3]) + (a.Matrix[0][3] * b.Matrix[3][3]));
		//Row 2
		Result.Matrix[1][0] = ((a.Matrix[1][0] * b.Matrix[0][0]) + (a.Matrix[1][1] * b.Matrix[1][0]) + (a.Matrix[1][2] * b.Matrix[2][0]) + (a.Matrix[1][3] * b.Matrix[3][0]));
		Result.Matrix[1][1] = ((a.Matrix[1][0] * b.Matrix[0][1]) + (a.Matrix[1][1] * b.Matrix[1][1]) + (a.Matrix[1][2] * b.Matrix[2][1]) + (a.Matrix[1][3] * b.Matrix[3][1]));
		Result.Matrix[1][2] = ((a.Matrix[1][0] * b.Matrix[0][2]) + (a.Matrix[1][1] * b.Matrix[1][2]) + (a.Matrix[1][2] * b.Matrix[2][2]) + (a.Matrix[1][3] * b.Matrix[3][2]));
		Result.Matrix[1][3] = ((a.Matrix[1][0] * b.Matrix[0][3]) + (a.Matrix[1][1] * b.Matrix[1][3]) + (a.Matrix[1][2] * b.Matrix[2][3]) + (a.Matrix[1][3] * b.Matrix[3][3]));
		//Row 3
		Result.Matrix[2][0] = ((a.Matrix[2][0] * b.Matrix[0][0]) + (a.Matrix[2][1] * b.Matrix[1][0]) + (a.Matrix[2][2] * b.Matrix[2][0]) + (a.Matrix[2][3] * b.Matrix[3][0]));
		Result.Matrix[2][1] = ((a.Matrix[2][0] * b.Matrix[0][1]) + (a.Matrix[2][1] * b.Matrix[1][1]) + (a.Matrix[2][2] * b.Matrix[2][1]) + (a.Matrix[2][3] * b.Matrix[3][1]));
		Result.Matrix[2][2] = ((a.Matrix[2][0] * b.Matrix[0][2]) + (a.Matrix[2][1] * b.Matrix[1][2]) + (a.Matrix[2][2] * b.Matrix[2][2]) + (a.Matrix[2][3] * b.Matrix[3][2]));
		Result.Matrix[2][3] = ((a.Matrix[2][0] * b.Matrix[0][3]) + (a.Matrix[2][1] * b.Matrix[1][3]) + (a.Matrix[2][2] * b.Matrix[2][3]) + (a.Matrix[2][3] * b.Matrix[3][3]));
		//Row 4
		Result.Matrix[3][0] = ((a.Matrix[3][0] * b.Matrix[0][0]) + (a.Matrix[3][1] * b.Matrix[1][0]) + (a.Matrix[3][2] * b.Matrix[2][0]) + (a.Matrix[3][3] * b.Matrix[3][0]));
		Result.Matrix[3][1] = ((a.Matrix[3][0] * b.Matrix[0][1]) + (a.Matrix[3][1] * b.Matrix[1][1]) + (a.Matrix[3][2] * b.Matrix[2][1]) + (a.Matrix[3][3] * b.Matrix[3][1]));
		Result.Matrix[3][2] = ((a.Matrix[3][0] * b.Matrix[0][2]) + (a.Matrix[3][1] * b.Matrix[1][2]) + (a.Matrix[3][2] * b.Matrix[2][2]) + (a.Matrix[3][3] * b.Matrix[3][2]));
		Result.Matrix[3][3] = ((a.Matrix[3][0] * b.Matrix[0][3]) + (a.Matrix[3][1] * b.Matrix[1][3]) + (a.Matrix[3][2] * b.Matrix[2][3]) + (a.Matrix[3][3] * b.Matrix[3][3]));


		return Result;
	}

	mat4 operator*=(mat4&lhs, const mat4&rhs) { for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++) { lhs.Matrix[i][j] *= rhs.Matrix[i][j]; } } return lhs; }

}
