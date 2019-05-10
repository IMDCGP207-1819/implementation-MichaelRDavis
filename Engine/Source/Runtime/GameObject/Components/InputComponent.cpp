#include "stdafx.h"
#include "InputComponent.h"
#include "Input/Gamepad.h"

InputComponent::InputComponent()
{
	m_gamepad = std::make_unique<Gamepad>();
}

InputComponent::~InputComponent()
{

}
