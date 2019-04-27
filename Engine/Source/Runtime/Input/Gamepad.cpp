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
	if (SDL_NumJoysticks() < 1)
	{
		printf("No gamepad connected");
	}

	m_gamepad = SDL_JoystickOpen(0);
	if (m_gamepad == nullptr)
	{
		printf("Unable to open gamepad %s", SDL_GetError());
	}
}

void Gamepad::Destroy()
{
	SDL_JoystickClose(m_gamepad);
}

void Gamepad::HandleGamepadEvents(SDL_Event event)
{

}

const int32_t Gamepad::m_thumstickDeadZone = 8000;
