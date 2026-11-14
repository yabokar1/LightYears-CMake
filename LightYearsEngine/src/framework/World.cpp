#include "framework/World.h"
#include "framework/Core.h"

namespace ly
{
	World::World(Application* owningApp)
		: mOwningApp{owningApp},
		mBegunPlay{false}
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
		Tick(deltaTime);
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
