#pragma once

/** Gamepad thumbstick deadzones. */
constexpr int32_t LEFT_THUMBSTICK_DEADZONE{ 7800 };
constexpr int32_t RIGHT_THUMBSTICK_DEAZONE{ 8700 };

/**
 * 
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

	/** Destroy gamepad device. */
	void Destroy();

	/** Process gamepad events. */
	void HandleGamepadEvents(SDL_Event event);

	/**  */
	inline int32_t GetXAxis() const
	{
		return m_xAxis;
	}

	/**  */
	inline int32_t GetYAxis() const
	{
		return m_yAxis;
	}

private:
	/** Pointer to the gamepad device. */
	SDL_GameController* m_gamepad;

	/**  */
	int32_t m_xAxis;

	/**  */
	int32_t m_yAxis;
};