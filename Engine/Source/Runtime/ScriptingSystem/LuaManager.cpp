#include "stdafx.h"
#include "LuaManager.h"
#include "GameObject/Entity.h"

LuaManager::LuaManager()
{

}

LuaManager::~LuaManager()
{

}

void LuaManager::Init()
{
	m_luaState.open_libraries();
}

void LuaManager::ExceuteString(const std::string& str)
{
	m_luaState.script(str);
}

void LuaManager::ExecuteFile(const std::string& filePath)
{
	m_luaState.script_file(filePath);
}

sol::table LuaManager::GetTableKeys(const std::string& name)
{
	return m_luaState.get<sol::table>(name);
}

std::shared_ptr<Entity> LuaManager::LoadEntity(const std::string& type)
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entity->SetType(type);
	auto table = GetTableKeys(type);
	for (auto& compName : table)
	{

	}

	return entity;
}
