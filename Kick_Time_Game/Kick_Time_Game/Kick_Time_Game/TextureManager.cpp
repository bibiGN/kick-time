#include "TextureManager.h"
#include "AnimationData.h"
#include "LevelData.h"
#include "HudManager_Defines.h"

#include <iostream>

TextureManager::TextureManager(void)
{
	this->textureList = new map<string, sf::Texture>();
}


TextureManager::~TextureManager(void)
{
	delete textureList;
}

void TextureManager::initializeTextureManager()
{
	int i;
	string currentFile = "";
	sf::Texture currentTexture;
	
	// Textures Animations
	for(i = 0; i < NUMBER_ANIMATIONDATA; ++i)
	{
		if(strcmp(currentFile.c_str(),animationDataArray[i].getFileName().c_str()) != 0)
		{
			currentFile = animationDataArray[i].getFileName();
			if (!currentTexture.loadFromFile(currentFile))
			{
				cout << "Sprite didn't find!" << endl << currentFile << endl;
			}
			else
			{
				this->textureList->insert(pair<string, sf::Texture>(currentFile, currentTexture));
			}
		}
	}

	// Textures Levels
	currentFile = "";
	for(i = 0; i < NUMBER_LEVELDATA; ++i)
	{
		if(strcmp(currentFile.c_str(),levelDataArray[i].getFileName().c_str()) != 0)
		{
			currentFile = levelDataArray[i].getFileName();
			if (!currentTexture.loadFromFile(currentFile))
			{
				cout << "Sprite didn't find!" << endl << currentFile << endl;
			}
			else
			{
				this->textureList->insert(pair<string, sf::Texture>(currentFile, currentTexture));
			}
		}
	}

	// Texture HUD
	if (!currentTexture.loadFromFile(FILE_HUD))
	{
		cout << "Sprite didn't find!" << endl << FILE_HUD << endl;
	}
	else
	{
		this->textureList->insert(pair<string, sf::Texture>(FILE_HUD, currentTexture));
	}
}

void TextureManager::updateTextureManager()
{

}

sf::Texture* TextureManager::getTexture(string textureName)
{
	return &textureList->at(textureName);
}
