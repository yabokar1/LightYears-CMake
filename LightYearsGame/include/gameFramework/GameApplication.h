#pragma once
#include <framework/Application.h>

namespace ly
{
	class Actor;
	class GameApplication : public Application
	{
	public:
		GameApplication();
	private:
		virtual void Tick(float deltaTime) override;
		float mCounter;
		weak<Actor> mActorToDestroy;
	};
}
