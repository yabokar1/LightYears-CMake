#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Core.h"

namespace ly
{
	class Actor;
	class Application;
	class World
	{
	public:
		World(Application* owningApp);
		
		// Application.cpp uses these public methods 
		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		void Render(sf::RenderWindow& window);

		virtual ~World();

		template<typename ActorType>
		weak<ActorType> SpawnActor();
	private:
		void BeginPlay();
		void Tick(float deltaTime);

		Application* mOwningApp;
		bool mBeganPlay;

		List<shared<Actor>> mActors; // pending actors are staged into this list
		List<shared<Actor>> mPendingActors; // queued into the pending actors list
	};


	template<typename ActorType>
	weak<ActorType> World::SpawnActor()
	{
		shared<ActorType> newActor{ new ActorType{this} };
		mPendingActors.push_back(newActor);
		return newActor;
	}

}