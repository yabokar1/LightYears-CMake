#include "framework/Application.h"
#include <iostream>

namespace ly
{
	Application::Application()
		: mWindow{sf::VideoMode(1024, 1440), "Light Years"},
		mTargetFrameRate{60.f},
		mTickClock{}
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
		std::cout << "ticking at framerate: " << 1.f / deltaTime << std::endl;
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
	}

	void Application::Render()
	{
		sf::CircleShape circle{ 50.f };
		circle.setFillColor(sf::Color::Green);
		circle.setOrigin(50.f, 50.f);
		circle.setPosition(mWindow.getSize().x / 2.f, mWindow.getSize().y / 2.f);
		mWindow.draw(circle);
	}
}