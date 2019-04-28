#pragma once

/**
 * 
 */
class String
{
public:
	/**  */
	static std::string Normalize(std::string& str)
	{
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		return str;
	}
};