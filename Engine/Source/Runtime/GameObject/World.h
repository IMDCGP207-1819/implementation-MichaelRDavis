#pragma once

class Player;
class EntityManager;
class ComponentManager;

/**
 * A world is a high level game object that represents a game level.
 */
class World
{
public:
	/** Default constructor. */
	World();

	/** Default destructor. */
	~World();

	/** Initialize the game world object. */
	void Initialize(SDL_Renderer* renderer);

	/** Update all game objects in the game world, called once per frame. */
	void Update(float deltaTime);

	/** Draw all game objects in the game world. */
	void Draw(SDL_Renderer* renderer);

private:
	/** Pointer to the player object. */
	std::unique_ptr<Player> m_player;

	/** Pointer to the entity manager container. */
	std::unique_ptr<EntityManager> m_entityManager;

	/** Pointer to the component manager container. */
	std::unique_ptr<ComponentManager> m_componentManager;
};