#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace ly
{
	class AssetManager
	{
	public:
		static AssetManager& Get();
		shared<sf::Texture> LoadTexture(const std::string& texturePath);
		void CleanCycle();

	protected:
		AssetManager();

	private:
		static unique<AssetManager> assetManager;
		dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
	};
}
