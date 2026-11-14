#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace ly
{
	class World;
	class Application
	{
	public:
		Application();
		virtual ~Application() = default;
		void Run();

		template<typename WorldType>
		weak<WorldType> LoadWorld();

	private:
		void TickInternal(float deltaTime);
		void RenderInternal();
		virtual void Tick(float deltaTime);
		virtual void Render();

		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;
		shared<World> mCurrentWorld;
	};

	template<typename WorldType>
	weak<WorldType> Application::LoadWorld()
	{
		shared<WorldType> newWorld{new WorldType{this}};
		mCurrentWorld = newWorld;
		mCurrentWorld->BeginPlayInternal();
		return newWorld;
	}
}
