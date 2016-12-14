#include "Transform.h"
namespace bab
{
	Transform::Transform()
	{
		pos = {0,0};
		scale = {1,1};
		angle = 0;
	}
	Transform::Transform(const Vec2& p, const Vec2& s, float a)
	{
		pos = p;
		scale = s;
		angle = a;
		
	}



	void Transform::setParent(Transform* newParent)
	{
		this->Parent = newParent;
	}

	void Transform::setPos(const Vec2& newPos)
	{
		this->pos = newPos;
	}

	void Transform::setPos(float x, float y) { this->pos.x = x; this->pos.y = y; }

	void Transform::setScale(const Vec2& newScale)
	{
		this->scale = newScale;
	}

	void Transform::setAngle(float newAngle)
	{
		this->angle = newAngle;
	}

	Vec2 Transform::getPosition() const
	{
		return this->pos;
	}

	Vec2 Transform::getScale() const
	{
		return this->scale;
	}

	float Transform::getAngle() const
	{
		return this->angle;
	}

	void Transform::Update()
	{
		
	}

	
}