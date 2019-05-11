#pragma once

class Entity;

/**
 * High level class for managing game entities.
 */
class EntityManager
{
public:
	/** Default constructor. */
	EntityManager();

	/** Default destructor. */
	~EntityManager();

	/** Add an entity to the manager. */
	void AddEntity(Entity* entity);

	/** Initialize any managed entities. */
	void Initialize(SDL_Renderer* renderer);

	/** Update any managed entities, called once per frame. */
	void Update(float deltaTime);

	/** Draw any managed entities. */
	void Draw(SDL_Renderer* renderer);

#ifdef _DEBUG
	/** Log entities to the console. DEBUG only. */
	void LogEntity()
	{
		for (auto it : m_entityList)
		{
			const std::type_info& entity = typeid(it);
			printf("%s", entity.name());
		}
	}
#endif

	/** Returns the number of manged entities. */
	inline uint64_t GetEntityCount() const
	{
		return m_entityList.size();
	}

private:
	/** List of entities. */
	std::list<Entity*> m_entityList;
};