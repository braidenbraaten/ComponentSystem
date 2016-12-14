#pragma once
#include "vec2.h"
#include "mat3.h"
#include <list>


namespace bab
{
	class Transform 
	{
	private:
		Transform *Parent;
		std::list<Transform*> Children;
		Vec2 pos, scale;
		mat3 objectPos;
		float angle;
	public:
		Transform();
		Transform(const Vec2&, const Vec2&, float);
		//~Transform();
		//mat3 getGlobalTransform() const;

		void setParent(Transform*);
		void setPos   (const Vec2&);
		void setPos   (float,float);
		void setScale (const Vec2&);
		void setAngle (float      );

		Vec2 getPosition()    const;
		Vec2 getScale   ()    const;
		float getAngle  ()    const;


		void Update();





	};


}