#include "framework/World.h"
#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{
	World::World(Application* owningApp)
		: mOwningApp{owningApp},
		mBegunPlay{false},
		mActors{},
		mPendingActors{}
	{

	}

	World::~World()
	{

	}

	void World::BeginPlayInternal()
	{
		if (!mBegunPlay)
		{
			mBegunPlay = true;
			BeginPlay();
		}
	}

	void World::TickInternal(float deltaTime)
	{
		for (shared<Actor> actor : mPendingActors)
		{
			mActors.push_back(actor);
			actor->BeginPlayInternal();
		}
		mPendingActors.clear();

		for (auto iter = mActors.begin(); iter != mActors.end();)
		{
			if ((*iter)->IsPendingDestroy())
			{
				iter = mActors.erase(iter);
			}
			else
			{
				(*iter)->TickInternal(deltaTime);
				++iter;
			}
		}

		Tick(deltaTime);
	}

	void World::Render(sf::RenderWindow& window)
	{
		for (auto& actor : mActors)
		{
			actor->Render(window);
		}
	}

	void World::BeginPlay()
	{
		LOG("begin play");
	}

	void World::Tick(float deltaTime)
	{
		LOG("ticking at framerate: %f", 1.f / deltaTime);
	}
}
