#pragma once

/**
 * String utility class.
 */
class String
{
public:
	/** Normalize a given string. */
	static std::string Normalize(std::string& str)
	{
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		return str;
	}
};