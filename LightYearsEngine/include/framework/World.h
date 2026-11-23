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
		sf::Vector2u GetWindowSize() const;

		virtual ~World();

		template<typename ActorType, typename... Args>
		weak<ActorType> SpawnActor(Args... args);
	private:
		void BeginPlay();
		void Tick(float deltaTime);

		Application* mOwningApp;
		bool mBeganPlay;

		List<shared<Actor>> mActors; // pending actors are staged into this list
		List<shared<Actor>> mPendingActors; // queued into the pending actors list
	};


	template<typename ActorType, typename... Args>
	weak<ActorType> World::SpawnActor(Args... args)
	{
		shared<ActorType> newActor{ new ActorType{this, args...} };
		mPendingActors.push_back(newActor);
		return newActor;
	}

}