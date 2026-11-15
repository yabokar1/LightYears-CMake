#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"
namespace ly
{
	class World;
	class Application
	{
	public:
		Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style);
		void Run();

		template<typename WorldType>
		weak<WorldType> LoadWorld();

	private:
		void TickInternal(float deltaTime);
		void RenderInternal();

		virtual void Render();
		virtual void Tick(float deltaTime);

		sf::RenderWindow mWindow; // This is the application render window
		float mTargetFrameRate; // set the frame rate e.g 60 and so it becomes 1 / 60
		sf::Clock mTickClock;
	
		shared<World> currentWorld;
		sf::Clock mCleanCycleClock;
		float mCleanCycleInterval;
	};

	template<typename WorldType>
	weak<WorldType> Application::LoadWorld()  // return type::className::function (same as .cpp file format)
	{
		shared<WorldType> newWorld{ new WorldType{this} };
		currentWorld = newWorld;
		currentWorld->BeginPlayInternal();
		return newWorld;
	}
}