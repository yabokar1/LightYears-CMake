#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{
	Actor::Actor(World* owningWorld, const std::string& texturePath)
		: mOwningWorld{owningWorld},
		mHasBegunPlay{false},
		mSprite{},
		mTexture{}
	{
		SetTexture(texturePath);
	}

	Actor::~Actor()
	{
		LOG("actor destroyed");
	}

	void Actor::BeginPlayInternal()
	{
		if (!mHasBegunPlay)
		{
			mHasBegunPlay = true;
			BeginPlay();
		}
	}

	void Actor::TickInternal(float deltaTime)
	{
		if (!IsPendingDestroy())
		{
			Tick(deltaTime);
		}
	}

	void Actor::SetTexture(const std::string& texturePath)
	{
		mTexture.loadFromFile(texturePath);
		mSprite.setTexture(mTexture);

		int textureWidth = mTexture.getSize().x;
		int textureHeight = mTexture.getSize().y;
		mSprite.setTextureRect(sf::IntRect{0, 0, textureWidth, textureHeight});
	}

	void Actor::Render(sf::RenderWindow& window)
	{
		if (IsPendingDestroy())
		{
			return;
		}

		window.draw(mSprite);
	}

	void Actor::BeginPlay()
	{
		LOG("actor begin play");
	}

	void Actor::Tick(float deltaTime)
	{
		LOG("actor ticking");
	}
}
