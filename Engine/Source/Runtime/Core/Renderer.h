#pragma once

/**
 * Abstraction layer for the SDL renderer.
 */
class Renderer
{
public:
	/** Default constructor. */
	Renderer();

	/** Default destructor. */
	~Renderer();

	/** Initialize the renderer object. */
	void Initialize(SDL_Window* window);

	/** Clear buffer. */
	void Clear();

	/** Swap buffer */
	void SwapBuffers();

	/** Retunrs a pointer to the SDL renderer. */
	inline SDL_Renderer* GetSDLRenderer() const
	{
		return m_pRenderer;
	}

private:
	/** Pointer to the SDL_Renderer. */
	SDL_Renderer* m_pRenderer;
};