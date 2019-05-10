#include "stdafx.h"
#include "Gamepad.h"

Gamepad::Gamepad()
{
	m_gamepad = nullptr;
}

Gamepad::~Gamepad()
{
	m_gamepad = nullptr;
}

void Gamepad::Initialize()
{
	for (int32_t i = 0; i < SDL_NumJoysticks(); i++)
	{
		if (SDL_IsGameController(i))
		{
			m_gamepad = SDL_GameControllerOpen(i);
		}
	}
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
