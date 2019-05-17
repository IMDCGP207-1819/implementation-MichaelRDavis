#pragma once

#include "GameObject/Component.h"

class Gamepad;

/**
 * Input component.
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

	// TODO: Add a map of input binding's here.
	// TODO: Add input binding function.
	// TODO: Remove input binding function.

	/** Gamepad object */
	std::unique_ptr<Gamepad> m_gamepad;
};