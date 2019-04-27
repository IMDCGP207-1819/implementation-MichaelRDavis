#pragma once

class Renderer;

/** Mode the window is currently in */
enum EWindowMode
{
	EFullscreen,
	EWindowed,
};

/**
 * Abstraction layer for a game application.
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

	/** Pointer to the renderer. */
	std::unique_ptr<Renderer> m_pRenderer;

	/** Title of the game window. */
	std::string m_windowTitle;

	/** The windows current mode. */
	EWindowMode m_windowMode;

	/** Width of the window. */
	int32_t m_width;

	/** Height of the window. */
	int32_t m_height;

	/** True if application is currently running. */
	bool m_isRunning;
};