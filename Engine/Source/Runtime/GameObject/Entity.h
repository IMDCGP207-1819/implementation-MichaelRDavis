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

	/**  */
	virtual void Initialize();

	/**  */
	virtual void Update(float deltaTime);

	/**  */
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

	void SetPosition(Vec2 newPosition);
	void SetVelcity(Vec2 newVelocity);

	inline Vec2 GetPosition() const
	{
		return m_position;
	}

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

	/** Retunrs the active state of this entity. */
	inline bool GetIsActive() const
	{
		return m_isActive;
	}

protected:
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