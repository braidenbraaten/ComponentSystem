#include "Transform.h"
#include "GameObject.h"


Transform::Transform(void)
{
}


Transform::~Transform(void)
{
}

void Transform::Destroy()
{
}

void Transform::Awake()
{
	bab::mat3 l_mat;
	this->m_up = bab::Vec3(1, 0, 0);
	this->m_right = bab::Vec3(0, 1, 0);
	this->m_direction = bab::Vec3(0, 0, 1); //Forward Direction

	//row major for matricies 
	//this->m_rotation = Quaternion(1,0,0,0)
	this->m_position = bab::Vec3(0, 0, 0);

	this->m_scale = l_mat.Identity();
}

void Transform::Start()
{
	//->m_localMatrix = mat4::toMatrix(Quaternion q, vec3 pos, mat3 scale);  rotation, position, scale
	//this->m_right = vec3()
	//up
	//direction

	this->m_worldMatrix = this->m_localMatrix;

	if (this->m_gameObject->m_parent != nullptr)
	{
		this->m_worldMatrix = this->m_gameObject->m_parent->m_transform->m_worldMatrix * this->m_worldMatrix;
	}
}

void Transform::FixedUpdate()
{
	//->m_localMatrix = mat4::toMatrix(Quaternion q, vec3 pos, mat3 scale);  rotation, position, scale
	//this->m_right = vec3()
	//up
	//direction

	this->m_worldMatrix = this->m_localMatrix;

	if (this->m_gameObject->m_parent != nullptr)
	{
		this->m_worldMatrix = this->m_gameObject->m_parent->m_transform->m_worldMatrix * this->m_worldMatrix;
	}

	bab::mat4 test;
	test.test();
}

void Transform::Update()
{
	//->m_localMatrix = mat4::toMatrix(Quaternion q, vec3 pos, mat3 scale);  rotation, position, scale
	//this->m_right = vec3()
	//up
	//direction

	this->m_worldMatrix = this->m_localMatrix;

	if (this->m_gameObject->m_parent != nullptr)
	{
		this->m_worldMatrix = this->m_gameObject->m_parent->m_transform->m_worldMatrix * this->m_worldMatrix;
	}
}

void Transform::LateUpdate()
{
	//->m_localMatrix = mat4::toMatrix(Quaternion q, vec3 pos, mat3 scale);  rotation, position, scale
	//this->m_right = vec3()
	//up
	//direction

	this->m_worldMatrix = this->m_localMatrix;

	if (this->m_gameObject->m_parent != nullptr)
	{
		this->m_worldMatrix = this->m_gameObject->m_parent->m_transform->m_worldMatrix * this->m_worldMatrix;
	}
}

//Transform* Transform::getRotation();

Transform * Transform::setRotation()
{
	return nullptr;
}

Transform * Transform::rotate(bab::Vec3 l_axis, float l_angle)
{
	return nullptr;
}

Transform * Transform::rotateAroundX(float l_angle)
{
	return nullptr;
}

Transform * Transform::rotateAroundY(float l_angle)
{
	return nullptr;
}

Transform * Transform::rotateAroundZ(float l_angle)
{
	return nullptr;
}

bab::Vec3 Transform::getRight()
{
	return bab::Vec3();
}

bab::Vec3 Transform::getUp()
{
	return bab::Vec3();
}

bab::Vec3 Transform::getDirection()
{
	return bab::Vec3();
}

bab::Vec3 Transform::getPosition()
{
	return bab::Vec3();
}

bab::Vec3 Transform::getWorldPosition()
{
	return bab::Vec3();
}

Transform * Transform::setPosition(bab::Vec3 l_position)
{
	return nullptr;
}

Transform * Transform::translate(float l_translation)
{
	return nullptr;
}

Transform * Transform::translate(bab::Vec3 l_translation)
{
	return nullptr;
}

Transform * Transform::translate(float x, float y, float z)
{
	return nullptr;
}

bab::mat3 Transform::getScale()
{
	return bab::mat3();
}

float Transform::getScaleX()
{
	return 0.0f;
}

float Transform::getScaleY()
{
	return 0.0f;
}

float Transform::getScaleZ()
{
	return 0.0f;
}

Transform * Transform::setScale(float x, float y, float z)
{
	return nullptr;
}

Transform * Transform::setScale(float l_scale)
{
	return nullptr;
}

Transform * Transform::setScale(bab::Vec3 l_scale)
{
	return nullptr;
}

Transform * Transform::scale(float x, float y, float z)
{
	return nullptr;
}

Transform * Transform::scale(float l_scale)
{
	return nullptr;
}

Transform * Transform::scale(bab::Vec3 l_scale)
{
	return nullptr;
}

bab::mat4 Transform::getLocalMatrix()
{
	return bab::mat4();
}

bab::mat4 Transform::getWorldMatrix()
{
	return bab::mat4();
}

bab::mat4 Transform::getMVMatrix()
{
	return bab::mat4();
}

bab::mat4 Transform::getMVPMatrix()
{
	return bab::mat4();
}
