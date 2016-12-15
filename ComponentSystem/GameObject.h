#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include <string>
#include <algorithm>
#include <typeinfo>
#include <vector>

#include "Component.h"
#include "Transform.h"
#include "ComponentManager.h"

class GameObject
{
public:
	std::string m_name;
	std::string m_tag;

	GameObject* m_parent;
	Transform* m_transform;

	typedef std::vector<Component*>			   component_vector;
	typedef component_vector::iterator         component_vector_itr;
	typedef component_vector::const_iterator   component_vector_const_itr;

	typedef std::vector<GameObject*>		   game_Object_vector;
	typedef game_Object_vector::iterator       game_Object_vector_itr;
	typedef game_Object_vector::const_iterator game_Object_vector_const_itr;
	component_vector   m_components;
	game_Object_vector m_children;

	GameObject(void);
	GameObject(std::string l_name);
	~GameObject(void);

	void Create();
	void Destroy();

	void AddComponent(Component* l_component);
	Component* FindComponentByName(std::string l_name);

	template <typename T>
	T* FindComponentByType()
	{
		for (component_vector_itr itr = m_components.begin(), itr != m_components.end(), ++itr)
		{
			if (T* l_type = dynamic_cast<T*>(*itr))
			{
				return l_type;
			}
		}
		return nullptr;
	}

	void AddChild(GameObject* l_gameObject);
	
	GameObject* FindChildByName(std::string l_name);
	std::vector<GameObject*> FindAllChildrenByName(std::string l_name);

};

struct GameObjectComparer
{
	std::string m_name;


	GameObjectComparer(std::string l_name)
		: m_name(l_name)
	{
	}

	bool operator()(GameObject* l_object)
	{
		return (l_object->m_name == m_name ? true : false);
	}

};

#endif // !GAMEOBJECT_H

