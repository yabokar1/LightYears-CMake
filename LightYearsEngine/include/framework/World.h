#pragma once

namespace ly
{
	class Application;
	class World
	{
	public:
		World(Application* owningApp);
		virtual ~World();

		void BeginPlayInternal();
		void TickInternal(float deltaTime);

	private:
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);

		Application* mOwningApp;
		bool mBegunPlay;
	};
}
