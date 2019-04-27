#pragma once

/**
 * Abstraction for a game application.
 */
class GameApp
{
public:
	/** Default GameApp constructor. */
	GameApp();

	/** Default GameApp destructor. */
	~GameApp();

	/** Initialize the application state. */
	virtual void Startup();

	/** Destroys the application. */
	virtual void Shutdown();

	/** Updates the application, called once per frame. */
	virtual void Update(float deltaTime);

	/** Handles application messages. */
	void ProcessEvents();

	/** Returns true if the application is currently running. */
	inline bool GetIsRunning() const
	{
		return m_isRunning;
	}

	/** Returns a pointer to the native window. */
	inline SDL_Window* GetWindow() const
	{
		return m_pWindow;
	}

private:
	/** Pointer to the native window. */
	SDL_Window* m_pWindow;

	/** Width of the window. */
	int32_t m_width;

	/** Height of the window. */
	int32_t m_height;

	/** True if application is currently running. */
	bool m_isRunning;

	/** Sets the application window to fullscreen mode. */
	bool m_fullscreen;

	/** Sets the application window to windowed mode. */
	bool m_windowed;
};