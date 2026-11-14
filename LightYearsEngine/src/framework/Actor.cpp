#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{
	Actor::Actor(World* owningWorld)
		: mOwningWorld{owningWorld},
		mHasBegunPlay{false}
	{

	}

	Actor::~Actor()
	{
		LOG("actor destroyed");
	}

	void Actor::BeginPlayInternal()
	{
		if (!mHasBegunPlay)
		{
			mHasBegunPlay = true;
			BeginPlay();
		}
	}

	void Actor::BeginPlay()
	{
		LOG("actor begin play");
	}

	void Actor::Tick(float deltaTime)
	{
		LOG("actor ticking");
	}
}
