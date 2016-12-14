#pragma once

#include "Transform.h  "
#include "RigidBody.h  "
#include "Collider.h   "
#include "Sprite.h     "
#include "LifeTime.h   "
namespace bab
{
	 //Think of it as Components are derived from this game object
	class Components 
	{
		 
		Transform transform;
		RigidBody rigidBody;
		Collider  collider;
		Sprite    sprite;
		LifeTime  lifeTime;
	public:
		Components();

		void      setParentTransform( Transform&);
		Transform getTransform();

		void      setRigidBody( RigidBody&);
		RigidBody getRigidBody();

		void      setCollider ( Collider&);
		Collider  getCollider ();

		void      setSprite   ( Sprite&);
		void	  setSprite   (std::string path, Vec2 pos, Vec2 scale, float rotation);
		Sprite    getSprite   ();

		void      setLifeTime ( LifeTime&);
		LifeTime  getLifeTime ();

		void Update();
	
	};









}