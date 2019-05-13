#pragma once

#include "Math/Vec2.h"

/** Gamepad thumbstick deadzones. */
constexpr int32_t LEFT_THUMBSTICK_DEADZONE{ 7800 };
constexpr int32_t RIGHT_THUMBSTICK_DEAZONE{ 8700 };

/** Gamepad button states. */
enum class EButtonState
{
	ENone,
	EPressed,
	EReleased,
	EHeld
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

	/** Returns true if the gamepad button is pressed. */
	bool IsButtonPressed(SDL_GameControllerButton button) const;

	/** Returns true if the the gamepad button is released. */
	bool IsButtonReleased(SDL_GameControllerButton button) const;

	/** Interpolates thumbstick input. */
	Vec2 Interpolate(float inputX, float inputY);

	/** Returns the left thumbstick axis. */
	inline const Vec2& GetLeftThumbStick() const
	{
		return m_leftThumbstick;
	}

	/** Returns the right thumbstick axis. */
	inline const Vec2& GetRightThumbstick() const
	{
		return m_rightThumbstick;
	}

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