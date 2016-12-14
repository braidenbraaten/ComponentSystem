#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"

class Transform : public Component
{
public:
	GameObject* m_gameObject;

	Transform();
	~Transform();
};

#endif // !TRANSFORM.H

