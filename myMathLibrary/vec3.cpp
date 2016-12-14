#include "vec3.h"


 namespace bab 
 {
	 float Vec3::Magnitude()
	 {
		 return sqrtf((x * x) + (y * y) + (z * z));
	 }


	 Vec3 Vec3::normal()
	 {
		 Vec3 norm;
		 norm.x = x / Magnitude();
		 norm.y = y / Magnitude();
		 norm.z = z / Magnitude();

		 return norm;
	 }

	 void Vec3::Normalize()
	 {
		 x = x / Magnitude();
		 y = y / Magnitude();
		 z = z / Magnitude();
	 }

	 float dot(const Vec3 &lhs, const Vec3 &rhs)
	 {
		 return ((lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z));
	 }

	 Vec3 operator+(const Vec3 &lhs, const Vec3 &rhs)
	 {
		 Vec3 sum;

		 sum.x = lhs.x + rhs.x;
		 sum.y = lhs.y + rhs.y;
		 sum.z = lhs.z + rhs.z;
		 return sum;
	 }

	 Vec3& operator+=(Vec3 &lhs, const Vec3 &rhs)
	 {

		 lhs.x += rhs.x;
		 lhs.y += rhs.y;
		 lhs.z += rhs.z;

		 return lhs;
	 }

	 Vec3 operator-(const Vec3 &lhs, const Vec3 &rhs)
	 {
		 Vec3 sum;
		 sum.x = lhs.x - rhs.x;
		 sum.y = lhs.y - rhs.y;
		 sum.y = lhs.z - rhs.z;
		 return sum;
	 }

	 Vec3 operator-(Vec3 vec)
	 {
		 vec.x = -(vec.x);
		 vec.y = -(vec.y);
		 vec.z = -(vec.z);

		 return  vec;
	 }

	 Vec3& operator-=(Vec3 &lhs, const Vec3 &rhs)
	 {
		 lhs.x -= rhs.x;
		 lhs.y -= rhs.y;
		 lhs.z -= rhs.z;
		 return lhs;
	 }

	 Vec3 operator*(const Vec3 &lhs, const Vec3 &rhs)
	 {
		 Vec3 sum;
		 sum.x = lhs.x * rhs.x;
		 sum.y = lhs.y * rhs.y;
		 sum.z = lhs.z * rhs.z;
		 return sum;
	 }

	 Vec3 operator*(const mat3 &m, const Vec3 &vec)
	 {
		 Vec3 result;
			
		 result.x = (m.Matrix[0][0] * vec.x) + (m.Matrix[0][1] * vec.y) + (m.Matrix[0][2] * vec.z);
		 result.y = (m.Matrix[1][0] * vec.x) + (m.Matrix[1][1] * vec.y) + (m.Matrix[1][2] * vec.z);
		 result.z = (m.Matrix[2][0] * vec.x) + (m.Matrix[2][1] * vec.y) + (m.Matrix[2][2] * vec.z);

		 return result;
	 }

	 Vec3 operator/(const Vec3 &lhs, const Vec3 &rhs)
	 {
		 Vec3 sum;
		 sum.x = lhs.x / rhs.x;
		 sum.y = lhs.y / rhs.y;
		 sum.z = lhs.z / rhs.z;
		 return sum;
	 }

	 bool operator==(const Vec3 &lhs, const Vec3 &rhs)
	 {
		 if (lhs.x == rhs.x)
		 {
			 if (lhs.y == rhs.y)
			 {
				 if (lhs.z == rhs.z)
				 {
					 return true;
				 }
			 }
		 }

		 return false;
	 }

	 bool operator!=(const Vec3 &lhs, const Vec3 &rhs)
	 {
		 if (lhs.x == rhs.x)
		 {
			 if (lhs.y == rhs.y)
			 {
				 if (lhs.z == rhs.z)
				 {
					 return false;
				 }
			 }
		 }

		 return true;
	 }

	 bool operator<(const Vec3 &lhs, const Vec3 &rhs)
	 {
		 if (lhs.x < rhs.x)
		 {
			 if (lhs.y < rhs.x)
			 {
				 if (lhs.z < rhs.z)
				 {
					 return true;
				 }
			 }
		 }
		 return false;
	 }

	 bool operator<=(const Vec3 &lhs, const Vec3 &rhs)
	 {
		 if (lhs.x <= rhs.x)
		 {
			 if (lhs.y <= rhs.x)
			 {
				 if (lhs.z <= rhs.z)
				 {
					 return true;
				 }
			 }
		 }
		 return false;
	 }

	 bool operator>(const Vec3 &lhs, const Vec3 &rhs)
	 {
		 if (lhs.x > rhs.x)
		 {
			 if (lhs.y > rhs.x)
			 {
				 if (lhs.z > rhs.z)
				 {
					 return true;
				 }
			 }
		 }
		 return false;
	 }

	 bool operator>=(const Vec3 &lhs, const Vec3 &rhs)
	 {
		 if (lhs.x >= rhs.x)
		 {
			 if (lhs.y >= rhs.x)
			 {
				 if (lhs.z >= rhs.z)
				 {
					 return true;
				 }
			 }
		 }
		 return false;
	 }








}