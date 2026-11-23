#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "framework/AssetManager.h"

namespace ly
{

	Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style)
		: mWindow{ sf::VideoMode(windowWidth, windowHeight),  title, style},
		mTargetFrameRate{ 60.f },
		mTickClock{},
		currentWorld{ nullptr },
		mCleanCycleClock{},
		mCleanCycleInterval{2.f}
	{

	}

	sf::Vector2u Application::GetWindowSize() const
	{
		return mWindow.getSize();
	}

	void Application::Run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / mTargetFrameRate;
		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					mWindow.close();
				}
			}
			float frameDeltaTime = mTickClock.restart().asSeconds();
			accumulatedTime += frameDeltaTime;
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
		}
	}
	void Application::TickInternal(float deltaTime) // Internal design pattern 
	{
		Tick(deltaTime);
	
		if (currentWorld)
		{
			currentWorld->TickInternal(deltaTime);
		}

		if (mCleanCycleClock.getElapsedTime().asSeconds() >= mCleanCycleInterval) // After 2 seconds clean any unused textures
		{
			mCleanCycleClock.restart();
			AssetManager::Get().CleanCycle(); // Singleton pattern static method AssetManager::Get()
		}
	}

	void Application::RenderInternal() // Internal design pattern 
	{
		mWindow.clear();

		Render();

		mWindow.display();
	}

	void Application::Render()
	{
		if (currentWorld)
		{
			currentWorld->Render(mWindow);
		}
	}

	void Application::Tick(float deltaTime)
	{
		
	}
}