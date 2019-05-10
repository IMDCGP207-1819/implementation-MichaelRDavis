#include "stdafx.h"
#include "LuaManager.h"

LuaManager::LuaManager()
{

}

LuaManager::~LuaManager()
{

}

void LuaManager::Init()
{
	//m_luaState.open_libraries();
}

void LuaManager::ExceuteString(const std::string& str)
{
	//m_luaState.script(str);
}

void LuaManager::ExecuteFile(const std::string& filePath)
{
	//m_luaState.script_file(filePath);
}
