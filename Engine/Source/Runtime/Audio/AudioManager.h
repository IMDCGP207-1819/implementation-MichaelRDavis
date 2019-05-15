#pragma once

class World;

/**
 * 
 */
class AudioManager
{
public:
	/** Default constructor. */
	AudioManager();

	/** Default destructor. */
	~AudioManager();

	/**  */
	void Initilaize();

	/**  */
	void Shutdown();

	/**  */
	void Update();

private:
	/**  */
	World* m_world;

	/**  */
	FMOD::System* m_system;
};