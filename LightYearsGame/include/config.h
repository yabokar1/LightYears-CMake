#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG //release build
	return "assets/";
#else
	return "C:/Users/yabok/source/repos/LightYears/LightYearsGame/assets/";
#endif
}
