#pragma once

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

private:
	/** Handle to the lua state object. */
	//sol::state m_luaState;
};