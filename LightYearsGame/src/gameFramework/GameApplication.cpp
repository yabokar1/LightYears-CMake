#include "gameFramework/GameApplication.h"
#include "framework/Actor.h"
#include "framework/World.h"

namespace ly
{
	GameApplication::GameApplication()
		: mCounter{0.f}
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		mActorToDestroy = newWorld.lock()->SpawnActor<Actor>();
	}

	void GameApplication::Tick(float deltaTime)
	{
		mCounter += deltaTime;
		if (mCounter > 2.f && !mActorToDestroy.expired())
		{
			mActorToDestroy.lock()->Destroy();
		}
	}
}

ly::Application* GetApplication()
{
	return new ly::GameApplication();
}
