#include "gameFramework/GameApplication.h"
#include "config.h"
#include "framework/Actor.h"
#include "framework/World.h"

namespace ly
{
	GameApplication::GameApplication()
		: Application{600, 980, "Light Years", sf::Style::Titlebar | sf::Style::Close},
		mCounter{0.f}
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		mActorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		mActorToDestroy.lock()->SetTexture(GetResourceDir() + "SpaceShooterRedux/PNG/playerShip1_blue.png");
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
