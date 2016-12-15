#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <vector>
class GameObject;


class Component
{
	//GameObject m_GameObject;



public:
	std::string m_name;
	bool	    m_isEnabled;

	GameObject* m_gameObject;


	Component(void);
	Component(std::string l_name);
	virtual ~Component(void);

	//Called when the code is generated
	virtual void Awake();

	//called when the script is first run
	virtual void Start();
	//called on this component when removing 
	virtual void Destroy();
	// applies changes through the physics update
	virtual void FixedUpdate();
	// general update loop
	virtual void Update();
	// called if you want to be sure that it will be updated after the normal update loop
	virtual void LateUpdate();



};

struct ComponentComparer
{
	std::string m_name;
	

	ComponentComparer(std::string l_name)
		: m_name(l_name)
	{	
	}

	bool operator()(Component* l_object)
	{
		return (l_object->m_name == m_name ? true : false);
	}

};

#endif

