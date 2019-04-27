#pragma once

class Component;

/**
 * Entity is the base class for all game objects in the game world.
 */
class Entity
{
public:
	/** Default constructor. */
	Entity();

	/** Default destructor. */
	virtual ~Entity();

	/** Add a component to this entity. */
	void AddComponent(std::type_index type, Component* comp);

	/** Get a component that is attached to this entity. */
	template<typename T>
	T* GetComponent()
	{
		auto it = m_componentList.find(std::type_index(typeid(T)));
		if (it != m_componentList.end())
		{
			return dynamic_cast<T*>(it->second);
		}

		return nullptr;
	}

	/** Set the entity type. */
	void SetType(const std::string& type);

	/** Get the entity type. */
	inline std::string GetType() const
	{
		return m_type;
	}

private:
	/** The name for this entity. */
	std::string m_type;

	/** Map of components attached to this entity keyed to via their type. */
	std::map<std::type_index, Component*> m_componentList;
};