#include "stdafx.h"
#include "Asset.h"

Asset::Asset(const std::string& assetName)
{
	if (assetName.empty())
	{
		printf("Empty asset name is not allowed");
	}

	m_assetName = assetName;
}

Asset::~Asset()
{

}
