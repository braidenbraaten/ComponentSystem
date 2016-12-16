#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"

#include "mat4.h"
#include "mat3.h"
#include "vec3.h"
//#include quaternion.h
class GameObject;

class Transform : public Component
{
public:
	GameObject* m_gameObject;
	//quaternion rotation m_varible
	bab::Vec3 m_up;
	bab::Vec3 m_right;
	bab::Vec3 m_direction;
	bab::Vec3 m_position;

	bab::mat3 m_scale;
	bab::mat4 m_localMatrix;
	bab::mat4 m_worldMatrix;

	bab::mat4 m_modelView;
	bab::mat4 m_mvp;


	Transform(void);
	~Transform(void);

	 virtual void Destroy() override;
	 virtual void Awake() override;
	 virtual void Start() override;
	 virtual void FixedUpdate() override;
	 virtual void Update() override;
	 virtual void LateUpdate() override;

	 Transform* setRotation();//should have a quaternion as a parameter
	 //Quaternion getRotation();
	 Transform* rotate(bab::Vec3 l_axis, float l_angle);
	 Transform* rotateAroundX( float l_angle);
	 Transform* rotateAroundY( float l_angle);
	 Transform* rotateAroundZ( float l_angle);

	 bab::Vec3 getRight();
	 bab::Vec3 getUp();
	 bab::Vec3 getDirection();

	 bab::Vec3 getPosition();
	 bab::Vec3 getWorldPosition();

	 Transform* setPosition(bab::Vec3 l_position);
	 Transform* translate(float l_translation);
	 Transform* translate(bab::Vec3 l_translation);
	 Transform* translate(float x, float y, float z);

	 bab::mat3 getScale();
	 float getScaleX();
	 float getScaleY();
	 float getScaleZ();

	 //set a new scale value to instantly change to
	 Transform* setScale(float x, float y, float z);
	 Transform* setScale(float l_scale);
	 Transform* setScale(bab::Vec3 l_scale);

	 //scale over time
	 Transform* scale(float x, float y, float z);
	 Transform* scale            (float l_scale);
	 Transform* scale		 (bab::Vec3 l_scale);
	
	 bab::mat4 getLocalMatrix();
	 bab::mat4 getWorldMatrix();
	 bab::mat4    getMVMatrix();
	 bab::mat4   getMVPMatrix();

};

#endif // !TRANSFORM.H

