#pragma once

class World;

/**
 * Class for managing audio systems.
 */
class AudioManager
{
public:
	/** Default constructor. */
	AudioManager(World* world);

	/** Default destructor. */
	~AudioManager();

	/** Initializes audio systems. */
	void Initilaize();

	/** Shutdown audio systems. */
	void Shutdown();

	/** Update audio systems, called once per frame. */
	void Update();

private:
	/** Pointer to the world object. */
	World* m_world;

	/** Pointer to the FMOD studio system. */
	FMOD::Studio::System* m_system;

	/** Pointer to the FMOD low level system. */
	FMOD::System* m_baseSystem;
};