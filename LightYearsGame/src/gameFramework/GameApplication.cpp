#include "gameFramework/GameApplication.h"
#include "framework/World.h"

namespace ly
{
	GameApplication::GameApplication()
	{
		LoadWorld<World>();
	}
}

ly::Application* GetApplication()
{
	return new ly::GameApplication();
}
