#pragma once

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

	/**  */
	virtual void InitializeComponent();

	/**  */
	virtual void UpdateComponent(float deltaTime);

	/** Enable this component. */
	void EnableComponent();

	/** Disable this component. */
	void DisableComponent();

	/** Returns true if this component is active. */
	inline bool GetIsActive() const
	{
		return true;
	}

protected:
	/**  */

	/** Is this component active */
	bool m_isActive;
};