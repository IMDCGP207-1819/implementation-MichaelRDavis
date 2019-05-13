#include "stdafx.h"
#include "Gamepad.h"

Gamepad::Gamepad()
{
	m_gamepad = nullptr;
	m_isConnected = false;
}

Gamepad::~Gamepad()
{
	Destroy();
	m_gamepad = nullptr;
}

void Gamepad::Initialize()
{
	for (int32_t i = 0; i < SDL_NumJoysticks(); i++)
	{
		if (SDL_IsGameController(i))
		{
			m_gamepad = SDL_GameControllerOpen(i);
			if (m_gamepad != nullptr)
			{
				m_isConnected = true;
			}
		}
	}

	std::memset(m_currentButtons, 0, SDL_CONTROLLER_BUTTON_MAX);
	std::memset(m_previousButtons, 0, SDL_CONTROLLER_BUTTON_MAX);
}

void Gamepad::PreUpdate()
{
	std::memcpy(m_previousButtons, m_currentButtons, SDL_CONTROLLER_BUTTON_MAX);
}

void Gamepad::Update()
{
	for (int32_t i = 0; i < SDL_CONTROLLER_BUTTON_MAX; i++)
	{
		m_currentButtons[i] = SDL_GameControllerGetButton(m_gamepad, SDL_GameControllerButton(i));
	}

	int32_t x = 0;
	int32_t y = 0;

	x = SDL_GameControllerGetAxis(m_gamepad, SDL_CONTROLLER_AXIS_LEFTX);
	y = -SDL_GameControllerGetAxis(m_gamepad, SDL_CONTROLLER_AXIS_LEFTY);
	m_leftThumbstick = Interpolate(x, y);
	x = SDL_GameControllerGetAxis(m_gamepad, SDL_CONTROLLER_AXIS_RIGHTX);
	y = -SDL_GameControllerGetAxis(m_gamepad, SDL_CONTROLLER_AXIS_RIGHTY);
	m_rightThumbstick = Interpolate(x, y);
}

void Gamepad::Destroy()
{
	if (m_gamepad != nullptr)
	{
		SDL_GameControllerClose(m_gamepad);
	}
}

void Gamepad::HandleGamepadEvents(SDL_Event event)
{
	switch (event.type)
	{
	case SDL_CONTROLLERDEVICEADDED:
		std::cout << "Gamepad connected" << std::endl;
		break;

	case SDL_CONTROLLERAXISMOTION:
	{
		SDL_ControllerAxisEvent axisEvent = event.caxis;
	}
	break;

	case SDL_CONTROLLERBUTTONDOWN:
	{
		switch (event.cbutton.button)
		{
		case SDL_CONTROLLER_BUTTON_A:
			std::cout << "Gamepad: A" << std::endl;
			break;
		case SDL_CONTROLLER_BUTTON_B:
			std::cout << "Gamepad: B" << std::endl;
			break;
		}
	}
	break;
	}
}

bool Gamepad::IsButtonPressed(SDL_GameControllerButton button) const
{
	return m_currentButtons[button] == 1;
}

bool Gamepad::IsButtonReleased(SDL_GameControllerButton button) const
{
	return m_currentButtons[button] == 0;
}

Vec2 Gamepad::Interpolate(float inputX, float inputY)
{
	const float deadzone = 8000.0f;
	const float max = 30000.0f;

	Vec2 dir = Vec2::zero;
	dir.x = inputX;
	dir.y = inputY;

	if (dir.Size() < deadzone)
	{
		dir = Vec2::zero;
	}
	else
	{
		float f = (dir.Size() - deadzone) / (max - deadzone);
		f = std::clamp(f, 0.0f, 1.0f);
		dir *= f / dir.Size();
	}

	return dir;
}
