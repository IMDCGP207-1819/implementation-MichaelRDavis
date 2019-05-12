#pragma once

#include "Math/Vec2.h"

/** Gamepad thumbstick deadzones. */
constexpr int32_t LEFT_THUMBSTICK_DEADZONE{ 7800 };
constexpr int32_t RIGHT_THUMBSTICK_DEAZONE{ 8700 };

/** Gamepad button states. */
enum class EButtonState
{
	EPressed,
	EReleased
};

/**
 * Input device wrapper class for a gamepad device. 
 */
class Gamepad
{
public:
	/** Default constructor. */
	Gamepad();

	/** Default destructor. */
	~Gamepad();

	/** Initializes the gamepad device. */
	void Initialize();

	/** Called before the main update function. */
	void PreUpdate();

	/** Poll gamepad input device, called once per frame. */
	void Update();

	/** Destroy gamepad device. */
	void Destroy();

	/** Process gamepad events. */
	// TODO: Implement an event management system for gamepad input.
	void HandleGamepadEvents(SDL_Event event);

private:
	/** Pointer to the gamepad device. */
	SDL_GameController* m_gamepad;

	/** Current gamepad button states. */
	uint8_t m_currentButtons[SDL_CONTROLLER_BUTTON_MAX];

	/** Previous gamepad button states. */
	uint8_t m_previousButtons[SDL_CONTROLLER_BUTTON_MAX];

	/** Left thumbstick axis. */
	Vec2 m_leftThumbstick;

	/** Right thumbstick axis. */
	Vec2 m_rightThumbstick;

	/** True if a gamepad is currently connected. */
	bool m_isConnected;
};