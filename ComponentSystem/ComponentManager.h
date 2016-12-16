#ifndef _COMPONENTMANAGER_H
#define _COMPONENTMANAGER_H

#include "Component.h"
#include "GameObject.h"
#include "RenderingManager.h"

class ComponentManager 
{
public:
	typedef std::vector<Component*> component_vector;
	typedef component_vector::iterator component_vector_itr;
	typedef component_vector::const_iterator component_vector_const_itr;

	typedef std::vector<RenderingManager*> rendManager_vector;
	typedef rendManager_vector::iterator rendManager_vector_itr;
	typedef rendManager_vector::const_iterator rendManager_vector_const_itr;
	component_vector m_components;
	rendManager_vector m_renderComponents;

	int m_componentSize;
	int m_currentComponentSize;
	int m_currentComponentCount; //current number of components in the system

	ComponentManager(void);
	~ComponentManager(void);
	void Clear();
	void Create();
	void Destroy();
	Component* AddComponent(Component* l_component);
	bool RemoveComponent(component_vector_const_itr l_component);
	void RemoveComponentWithGameObject(GameObject* l_objects);

	void FixedUpdate();
	void Update();
	void LateUpdate();

	void Render();

	void ResizeComponents();

	//Singleton Implimentation
	static ComponentManager* s_instance;

	static inline ComponentManager* getInstance(void)
	{


		if (s_instance == NULL)
		{
			s_instance = new ComponentManager();
		}

		return s_instance;
	}

	static inline bool exists(void)
	{
		return s_instance != 0;
	}

};


#endif // !_COMPONENTMANAGER_H
