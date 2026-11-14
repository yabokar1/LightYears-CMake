#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
	class Application
	{
	public:
		Application();
		virtual ~Application() = default;
		void Run();
	private:
		void TickInternal(float deltaTime);
		void RenderInternal();
		virtual void Tick(float deltaTime);
		virtual void Render();

		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;
	};
}
