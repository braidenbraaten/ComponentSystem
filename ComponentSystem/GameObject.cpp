#include "GameObject.h"

GameObject::GameObject(void)
{
	this->m_name = "GameObject";
	this->m_tag = "";
	this->m_transform = nullptr;
	this->m_parent = nullptr;
	HRESULT l_result = CoCreateGuid(&m_guid);
}

GameObject::GameObject(std::string l_name)
{
	this->m_name = l_name;
	this->m_tag = "";
	this->m_transform = nullptr;
	this->m_parent = nullptr;
	HRESULT l_result = CoCreateGuid(&m_guid);
}

GameObject::~GameObject(void)
{
}

void GameObject::Create()
{
	Transform* l_transform = new Transform();
	l_transform->m_gameObject = this;
	this->m_transform = (Transform*)ComponentManager::getInstance()->AddComponent(l_transform);
	this->AddComponent(this->m_transform);
}

void GameObject::Destroy()
{
	ComponentManager::getInstance()->RemoveComponentWithGameObject(this);

	for (game_Object_vector_itr itr = m_children.begin(); itr != m_children.end(); ++itr)
	{
		(*itr)->Destroy();
		delete *itr;
	}

	for (component_vector_itr itr = m_components.begin(); itr != m_components.end(); ++itr)
	{
		delete *itr;
	}

	//Clears the vectors
	m_children.clear();
	m_components.clear();

}

void GameObject::AddComponent(Component * l_component)
{
	l_component->m_gameObject = this;
	m_components.push_back(l_component);
	l_component->Start();
}



void GameObject::AddChild(GameObject * l_gameObject)
{

	l_gameObject->m_parent = this;
	l_gameObject->Create();
	this->m_children.push_back(l_gameObject);
}

GameObject * GameObject::FindChildByName(std::string l_name)
{
	game_Object_vector_itr itr = std::find_if(m_children.begin(), m_children.end(), GameObjectComparer(l_name));

	if (itr != m_children.end())
	{
		return *itr;
	}
	else
	{
		return NULL;
	}
}

std::vector<GameObject*> GameObject::FindAllChildrenByName(std::string l_name)
{
	return std::vector<GameObject*>();
}
