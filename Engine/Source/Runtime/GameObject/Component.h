#pragma once

class Entity;

/**
 * Component is a base class for all components that can be attached to entities.
 */
class Component
{
public:
	/** Default constructor. */
	Component();

	/** Default destructor. */
	virtual ~Component();

	/** Initialize this component. */
	virtual void InitializeComponent();

	/** Update this component called, called once per frame. */
	virtual void UpdateComponent(float deltaTime);

	/** Enable this component. */
	void EnableComponent();

	/** Disable this component. */
	void DisableComponent();

	/** Set the owner for this component. */
	void SetOwner(Entity* newOwner);

	/** Returns true if this component is active. */
	inline bool GetIsActive() const
	{
		return true;
	}

	/** Returns the entity that owns this component. */
	inline Entity* GetEntityOwner() const
	{
		return m_entityOwner;
	}

protected:
	/** Entity that owns this component */
	Entity* m_entityOwner;

	/** Is this component active */
	bool m_isActive;
};