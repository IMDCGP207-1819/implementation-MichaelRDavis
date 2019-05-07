#pragma once

class Entity;

/**
 * 
 */
class EntityManager
{
public:
	/**  */
	EntityManager();

	/**  */
	~EntityManager();

	/**  */
	void AddEntity(Entity* entity);

	/**  */
	void Initialize(SDL_Renderer* renderer);

	/**  */
	void Update(float deltaTime);

	/**  */
	void Draw(SDL_Renderer* renderer);

#ifdef _DEBUG
	/**  */
	void LogEntity()
	{
		for (auto it : m_entityList)
		{
			const std::type_info& entity = typeid(it);
			printf("%s", entity.name());
		}
	}
#endif // _DEBUG

	/**  */
	inline uint64_t GetEntityCount() const
	{
		return m_entityList.size();
	}

private:
	/**  */
	std::list<Entity*> m_entityList;
};