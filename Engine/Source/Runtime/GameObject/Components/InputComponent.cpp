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

void InputComponent::InitializeComponent()
{
	Component::InitializeComponent();

	m_gamepad->Initialize();
}

void InputComponent::PreUpdate()
{
	Component::PreUpdate();

	m_gamepad->PreUpdate();
}

void InputComponent::UpdateComponent(float deltaTime)
{
	Component::UpdateComponent(deltaTime);

	m_gamepad->PreUpdate();
	m_gamepad->Update();
}
