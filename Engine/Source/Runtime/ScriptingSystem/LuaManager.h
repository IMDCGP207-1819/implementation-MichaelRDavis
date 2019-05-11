#pragma once

class Entity;

/** Helper function for creating components from lua scripts. */
template<typename T>
void AddComponent(std::shared_ptr<Entity> entity)
{
	entity->AddComponent(typeid(T), new T());
}

/**
 * High-level manager for managing lua script objects.
 */
class LuaManager
{
public:
	/** Default constructor. */
	LuaManager();

	/** Default destructor. */
	~LuaManager();

	/** Initializes the lua state manager object. */
	void Init();

	/** Load and execute a lua script from a string */
	void ExceuteString(const std::string& str);

	/** Load and execute a lua script from a file. */
	void ExecuteFile(const std::string& filePath);

	/** Retrieves table keys from a lua script. */
	sol::table GetTableKeys(const std::string& name);

	/** Load an entity from a lua script file. */
	std::shared_ptr<Entity> LoadEntity(const std::string& type);

private:
	/** Handle to the lua state object. */
	sol::state m_luaState;
};