#pragma once

#include "GameObject/SingletonObject.h"

/**
 * 
 */
template<class T>
class AssetManager : public SingletonObject<AssetManager<T>>
{
public:
	/** Default constructor. */
	AssetManager()
	{

	}

	/** Default destructor. */
	~AssetManager()
	{
		Release();
	}

	/** Initialize the asset manager. */
	void Initialize(const std::string name)
	{
		if (name.empty())
		{
			printf("Name of asset manager cannot be empty");
		}

		m_assetManagerName = name;
	}

	/** Load an asset into the asset manager. */
	std::shared_ptr<T> Load(const std::string& filePath)
	{
		if (filePath.empty())
		{
			printf("FilePath cannot be empty");
		}

		auto it = m_assetMap.find(filePath);
		if (it != m_assetMap.end())
		{
			return (*it).second;
		}

		std::shared_ptr<T> asset = std::make_shared<T>(filePath);
		m_assetMap.insert(std::pair<std::string, std::shared_ptr<T>>(filePath, asset));
		return asset;
	}

	/** Removes an asset from the asset manager. */
	bool UnLoad(const std::string& filePath)
	{
		return false;
	}

	/** Returns the name of the asset manager. */
	const std::string& GetAssetManagerName() const
	{
		return m_assetManagerName;
	}

	/** Returns the size of the asset manager. */
	const int32_t GetSize() const
	{
		return m_assetMap.size();
	}

private:
	/** Release all assets held by the asset manager. */
	void Release()
	{
		auto it = m_assetMap.begin();
		while (it != m_assetMap.end())
		{
			(*it).second.reset();
			it = m_assetMap.erase(it);
		}
	}

private:
	/** Map of resources. */
	std::unordered_map<std::string, std::shared_ptr<T>> m_assetMap;

	/** Name of this asset manager. */
	std::string m_assetManagerName;
};