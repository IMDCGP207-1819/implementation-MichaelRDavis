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

private:
	/** Gamepad object */
	std::unique_ptr<Gamepad> m_gamepad;
};