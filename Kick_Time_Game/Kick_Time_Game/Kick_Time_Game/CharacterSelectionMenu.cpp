#include "CharacterSelectionMenu.h"
#include "CharacterSelectionMenu_Defines.h"
#include "CharacterData.h"
#include "GameManager.h"
#include "MainMenu.h"
#include "LevelSelectionMenu.h"

#include <stdio.h>

using namespace std;

CharacterSelectionMenu::CharacterSelectionMenu() : Menu()
{
    this->listAvatars = new vector<sf::Sprite*>();
    this->numberPlayerValidate = 0;

    Button * button;
    int indexLine = 0, indexColumn = 0;
    vector<bool> * active = new vector<bool>(NUMBER_FIGHTERS, true);
    sf::Sprite * sprite;
    TextureManager * textureManager = GameManager::getInstance()->getTextureManager();
    CharacterManager * characterManager = GameManager::getInstance()->getCharacterManager();
    Position * position;
	for (int i = 0; i < NUMBER_CHARACTERDATA; ++i)
    {
        indexColumn = i % NUMBER_CHARACTER_BY_LINE;
        indexLine = (int)(i / NUMBER_CHARACTER_BY_LINE);
        position = new Position(POSITION_FIRST_CHARACTER_X + indexColumn * OFFSET_CHARACTER_X, POSITION_FIRST_CHARACTER_Y + indexLine * OFFSET_CHARACTER_Y);
        for (int j = 0; j < NUMBER_FIGHTERS; ++j)
        {
            if (characterManager->getCharactersDataIndex()->size() > j)
            {
                if (characterManager->getCharactersDataIndex()->at(j) == i)
                    this->listButtons->push_back(new Button("", position, true, true, false, j));
                else
                    this->listButtons->push_back(new Button("", position, true, false, false, j));
                active->at(j) = false;
            }
            else
            {
                this->listButtons->push_back(new Button("", position, true, active->at(j), false, j));
                active->at(j) = false;
            }
            button = this->listButtons->at(this->listButtons->size() - 1);
            button->setAction(&Menu::actionValidateCharacter);
            button->setActionMove(&Menu::listMove);
        }

        this->listAvatars->push_back(new sf::Sprite());
        sprite = this->listAvatars->at(this->listAvatars->size() - 1);
        sprite->setTexture(*textureManager->getTexture(characterDataArray[i].getPathAvatar()));
        sprite->setPosition((float)(position->getX() - sprite->getTextureRect().width / 2), (float)(position->getY() - sprite->getTextureRect().height / 2));
    }
    characterManager->getCharactersDataIndex()->clear();

    // Button back
	this->listButtons->push_back(new Button("Back", new Position(POSITION_BACK_X, POSITION_BACK_Y), true, false, true, 0));
	button = this->listButtons->at(this->listButtons->size() - 1);
	button->setAction(&Menu::actionBack);
	button->setActionMove(&Menu::classicMove);

	this->spriteMenu->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(FILE_MENU_SELECTION));
}

CharacterSelectionMenu::~CharacterSelectionMenu()
{
	delete this->spriteMenu;
	delete this->listButtons;
    delete this->listAvatars;
}

void CharacterSelectionMenu::renderMenu()
{
	Menu::renderMenu();

    // Render avatar
    for (unsigned int i = 0; i < this->listAvatars->size(); ++i)
    {
		GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->listAvatars->at(i));
    }

    // Render selection
    Button * button;
    sf::RectangleShape * rectangle;
    sf::Text * text;
	char buffer[3];
    int indexLine = 0, indexColumn = 0;
	int max = (int)this->listButtons->size();
    for (int i = 0; i < max - 1; ++i)
    {
        button = this->listButtons->at(i);
        if (button->getIsActive())
        {
            // Rectangle of selection
            rectangle = new sf::RectangleShape();
            rectangle->setFillColor(sf::Color::Transparent);
            rectangle->setOutlineColor(sf::Color::Green);
            rectangle->setOutlineThickness(2);
            rectangle->setSize(sf::Vector2f((float)(this->listAvatars->at(i / NUMBER_FIGHTERS)->getTextureRect().width), (float)(this->listAvatars->at(i / NUMBER_FIGHTERS)->getTextureRect().height)));
            rectangle->setPosition((float)button->getCenter()->getX() - rectangle->getSize().x / 2, (float)button->getCenter()->getY() - rectangle->getSize().y / 2);
            GameManager::getInstance()->getRenderManager()->getWindow()->draw(*rectangle);

            // Number of player
            snprintf(buffer, 3, "%d", button->getIndexPlayer() + 1);
            indexColumn = button->getIndexPlayer() % NUMBER_INDEX_PLAYER_BY_LINE;
            indexLine = (int)(button->getIndexPlayer() / NUMBER_INDEX_PLAYER_BY_LINE);
            text = new sf::Text(buffer, *(GameManager::getInstance()->getFontManager()->getFont(INDEX_PLAYER_FONT)));
            text->setColor(sf::Color(INDEX_PLAYER_COLOR_RED, INDEX_PLAYER_COLOR_GREEN, INDEX_PLAYER_COLOR_BLUE));
            text->setScale((float)INDEX_PLAYER_SCALE_X, (float)INDEX_PLAYER_SCALE_Y);
            text->setPosition((float)button->getCenter()->getX() - rectangle->getSize().x / 2 + POSITION_FIRST_INDEX_PLAYER_X + indexColumn * OFFSET_INDEX_PLAYER_X, (float)button->getCenter()->getY() - rectangle->getSize().y / 2 + POSITION_FIRST_INDEX_PLAYER_Y + indexLine * POSITION_FIRST_INDEX_PLAYER_Y);
            GameManager::getInstance()->getRenderManager()->getWindow()->draw(*text);
        }
    }
}

void CharacterSelectionMenu::actionBack(Button * button)
{
	GameManager::getInstance()->getMenuManager()->setActiveMenu(new MainMenu());
    GameManager::getInstance()->getCharacterManager()->getCharactersDataIndex()->clear();
}

void CharacterSelectionMenu::actionValidateCharacter(Button * button)
{
    //Inactive all the buttons of this player
	Button * buttonTemp;
	int indexButton = 0;
    for (unsigned int i = 0; i < this->listButtons->size(); ++i)
    {
        buttonTemp = this->listButtons->at(i);
        if (buttonTemp->getIndexPlayer() == button->getIndexPlayer())
        {
            buttonTemp->setCanBeActive(false);
            if (buttonTemp == button)
                indexButton = i;
        }
    }
    GameManager::getInstance()->getCharacterManager()->addCharacterDataIndexAt(button->getIndexPlayer(), (int)(indexButton / NUMBER_FIGHTERS));

    ++this->numberPlayerValidate;
    if (this->numberPlayerValidate == NUMBER_FIGHTERS)
        GameManager::getInstance()->getMenuManager()->setActiveMenu(new LevelSelectionMenu());
}