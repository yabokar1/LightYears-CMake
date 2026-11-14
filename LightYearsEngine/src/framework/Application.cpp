#include "framework/Application.h"
#include "framework/AssetManager.h"
#include "framework/World.h"

namespace ly
{
	Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& windowTitle, sf::Uint32 windowStyle)
		: mWindow{sf::VideoMode(windowWidth, windowHeight), windowTitle, windowStyle},
		mTargetFrameRate{60.f},
		mTickClock{},
		mCleanCycleClock{},
		mCleanCycleInterval{2.f},
		mCurrentWorld{nullptr}
	{

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

			accumulatedTime += mTickClock.restart().asSeconds();
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
		}
	}
	void Application::Tick(float deltaTime)
	{
	}

	void Application::RenderInternal()
	{
		mWindow.clear();
		Render();
		mWindow.display();

	}

	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);

		if (mCurrentWorld)
		{
			mCurrentWorld->TickInternal(deltaTime);
		}

		if (mCleanCycleClock.getElapsedTime().asSeconds() >= mCleanCycleInterval)
		{
			mCleanCycleClock.restart();
			AssetManager::Get().CleanCycle();
		}
	}

	void Application::Render()
	{
		if (mCurrentWorld)
		{
			mCurrentWorld->Render(mWindow);
		}
	}
}
