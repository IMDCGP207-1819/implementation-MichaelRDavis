#pragma once

/**
 * 
 */
class Gamepad
{
public:
	/**  */
	Gamepad();

	/**  */
	~Gamepad();

	/**  */
	void Initialize();

	/**  */
	void Destroy();

	/**  */
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
	/**  */
	SDL_Joystick* m_gamepad;

	/**  */
	int32_t m_xAxis;

	/**  */
	int32_t m_yAxis;

	/**  */
	static const int32_t m_thumstickDeadZone;
};