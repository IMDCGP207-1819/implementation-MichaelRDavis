#pragma once

/**
 * Interface for an asset object.
 */
class Asset
{
public:
	/** Constructor. */
	Asset(const std::string& assetName);

	/** Default destructor. */
	virtual ~Asset();

	/** Retunrs the name of the asset. */
	inline std::string GetAssetName() const
	{
		return m_assetName;
	}

protected:
	/** The name of the asset. */
	std::string m_assetName;
};