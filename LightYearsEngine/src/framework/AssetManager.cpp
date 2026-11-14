#include "framework/AssetManager.h"
#include <utility>

namespace ly
{
	unique<AssetManager> AssetManager::assetManager{nullptr};

	AssetManager::AssetManager()
		: mLoadedTextureMap{}
	{

	}

	AssetManager& AssetManager::Get()
	{
		if (!assetManager)
		{
			assetManager = std::move(unique<AssetManager>{new AssetManager{}});
		}

		return *assetManager;
	}

	shared<sf::Texture> AssetManager::LoadTexture(const std::string& texturePath)
	{
		auto found = mLoadedTextureMap.find(texturePath);
		if (found != mLoadedTextureMap.end())
		{
			return found->second;
		}

		shared<sf::Texture> newTexture{new sf::Texture{}};
		if (newTexture->loadFromFile(texturePath))
		{
			mLoadedTextureMap.insert({texturePath, newTexture});
			return newTexture;
		}

		return shared<sf::Texture>{nullptr};
	}

	void AssetManager::CleanCycle()
	{
		for (auto iter = mLoadedTextureMap.begin(); iter != mLoadedTextureMap.end();)
		{
			if (iter->second.unique())
			{
				LOG("cleaning texture: %s", iter->first.c_str());
				iter = mLoadedTextureMap.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
}
