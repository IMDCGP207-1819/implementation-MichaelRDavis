#pragma once

#include "GameObject/Component.h"

class Gamepad;

/**
 * 
 */
class InputComponent : public Component
{
public:
	/** Default constructor. */
	InputComponent();

	/** Default destructor. */
	~InputComponent();

	// Component interface.
	void InitializeComponent();
	void PreUpdate();
	void UpdateComponent(float deltaTime);

	/** Gamepad object */
	std::unique_ptr<Gamepad> m_gamepad;
};