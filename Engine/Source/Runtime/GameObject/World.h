#pragma once

class Player;
class EntityManager;

/**
 * 
 */
class World
{
public:
	/**  */
	World();

	/**  */
	~World();

	/**  */
	void Initialize();

	/**  */
	void Update(float deltaTime);

	/**  */
	void Draw(SDL_Renderer* renderer);

private:
	/**  */
	std::unique_ptr<Player> m_player;

	/**  */
	std::unique_ptr<EntityManager> m_entityManager;
};