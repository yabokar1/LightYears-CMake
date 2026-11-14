#pragma once
#include "framework/Core.h"

namespace ly
{
	class Actor;
	class Application;
	class World
	{
	public:
		World(Application* owningApp);
		virtual ~World();

		void BeginPlayInternal();
		void TickInternal(float deltaTime);

		template<typename ActorType>
		weak<ActorType> SpawnActor();

	private:
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);

		Application* mOwningApp;
		bool mBegunPlay;

		list<shared<Actor>> mActors;
		list<shared<Actor>> mPendingActors;
	};

	template<typename ActorType>
	weak<ActorType> World::SpawnActor()
	{
		shared<ActorType> newActor{new ActorType{this}};
		mPendingActors.push_back(newActor);
		return newActor;
	}
}
