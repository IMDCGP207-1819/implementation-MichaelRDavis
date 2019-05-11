#pragma once

#include "Math/Vec2.h"

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

	/** Initialize the entity. */
	virtual void Initialize(SDL_Renderer* renderer);

	/** Update this entity, called once per frame. */
	virtual void Update(float deltaTime);

	/** Draw this entity. */
	virtual void Draw(SDL_Renderer* renderer);

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

	/** Set a new position for the entity. */
	void SetPosition(Vec2 newPosition);

	/** Set a new velocity for the entity. */
	void SetVelcity(Vec2 newVelocity);

	/** Returns the position of the entity. */
	inline Vec2 GetPosition() const
	{
		return m_position;
	}

	/** Returns the velocity of the entity. */
	inline Vec2 GetVelocity() const
	{
		return m_velocity;
	}

	/** Set the entity type. */
	void SetType(const std::string& type);

	/** Get the entity type. */
	inline std::string GetType() const
	{
		return m_type;
	}

	/** Activate this entity. */
	void Enable();

	/** Disable this entity. */
	void Disable();

	/** Returns the active state of this entity. */
	inline bool GetIsActive() const
	{
		return m_isActive;
	}

#ifdef _DEBUG
	/** Log components to the console. */
	void LogComponents()
	{
		for (auto it : m_componentList)
		{
			const std::type_info& entity = typeid(it.second);
			printf("%s", entity.name());
		}
	}
#endif

protected:
	/** Cached renderer pointer. */
	SDL_Renderer* m_renderer;

	/** The position of the entity in 2D space. */
	Vec2 m_position;

	/** The movement velocity of the entity in 2D space. */
	Vec2 m_velocity;

	/** The name for this entity. */
	std::string m_type;

	/** Map of components attached to this entity keyed to via their type. */
	std::map<std::type_index, Component*> m_componentList;

	/** Flag to activate this entity. */
	bool m_isActive;
};