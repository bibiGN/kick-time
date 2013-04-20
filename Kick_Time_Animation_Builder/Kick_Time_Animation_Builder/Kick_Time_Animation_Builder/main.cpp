#include <iostream>
#include "functions.h"
#include <fstream>
#include <list>
#include "AnimationLine.h"
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc,const char * argv[])
{
	// Variables to get/set data for locations
	char* animLocation = new char[1024];
	char* outputLocation = new char[1024];
	char confirm = 'n';
	bool resetData = false;

	// Variables for files' creation
	char* headerOutputLocation = new char[];
	char* cppOutputLocation = new char[];

	// Variable to open/read/create/write files
	// Animation file
	list <AnimationLine> animArray;
	ifstream animFile;
	string currentLine;
	int posDelimStart = -1;
	int posDelimEnd = 0;
	char* fileName = new char[];
	char* animationName = new char[];
	int posX;
	int posY;
	int spriteWidth;
	int spriteHeight;
	int framerate;
	int spriteNb;
	//char* animationLoop = new char[];
	char* animationLoopStr = new char[];
	// Header file
	ofstream headerFile;
	ostringstream animationData;
	string headerContent;
	int position;
	// CPP file
	ofstream cppFile;
	string cppContent;

	/*****************************/
	/* Get and set the locations */
	/*****************************/

	// Get the info from the arguments if there is any set
	if(argc > 1)
	{
		if(argc == 3)
		{
			// Put the arguments into the variables
			strcpy_s(animLocation,strlen(argv[1])+1,argv[1]);
			strcpy_s(outputLocation,strlen(argv[2])+1,argv[2]);
		}
		else
		{
			// Error message - Not enough argument
			cout << "Not enough argument provided!\nPlease check your settings." << endl;
			system("Pause");
			return 1;
		}

		// We ask the user if the data are ok
		while(confirm != 'y')
		{
			// If the user pressed 'n', then he can reset the data as he wishes
			if(resetData)
			{
				cout << "Set \"animation file's location\" : ";
				cin >> animLocation;
				cout << "Set \"Output class location\" : ";
				cin >> outputLocation;
				cout << endl << endl << endl;
			}
			cout << "Confirm : " << endl;
			cout << "Animation file's location : " << animLocation << endl << endl;
			cout << "Output class location : " << outputLocation << endl << endl;

			cout << "Confirm (y/n) : ";
			cin >> confirm;
			resetData = true;
		}

	}
	// No argument set, so the user has to define them
	else
	{
		while(confirm != 'y')
		{
			cout << "Set \"animation file's location\" : ";
			cin >> animLocation;
			cout << "Set \"Output class location\" : ";
			cin >> outputLocation;
			cout << endl << endl << endl;

			cout << "Confirm : " << endl;
			cout << "Animation file's location : " << animLocation << endl << endl;
			cout << "Output class location : " << outputLocation << endl << endl;

			cout << "Confirm (y/n) : ";
			cin >> confirm;
			resetData = true;
		}
	}

	// Check the animation file
	// Check if it's a text file
	if(strcmp(subChar(animLocation,findChar(animLocation,'.',LAST),4),".txt") != 0)
	{
		cout << "Please select an animation file as a '.txt' file" << endl;
		system("Pause");
		return 1;
	}

	/***************************/
	/* Read the animation file */
	/***************************/

	// Open the animation file
	animFile.open(animLocation,ios::in);

	if(animFile)
	{
		while(!animFile.eof())
		{
			// Get the full current line
			getline(animFile,currentLine);

			if(!currentLine.empty())
			{
				posDelimStart = -1;

				/****************************/
				/* Get the different values */
				/****************************/

				// Get fileName
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1)
				{
					cout << "ERROR GD001 - A problem occured while getting the file's name in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				fileName = mySubStringToChar(currentLine,posDelimStart,posDelimEnd-1);
				if(fileName == "")
				{
					cout << "ERROR GD002 - A problem occured while getting the file's name in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get animationName
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1)
				{
					cout << "ERROR GD003 - A problem occured while getting the animation's name in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				animationName = mySubStringToChar(currentLine,posDelimStart,posDelimEnd-1);
				if(animationName == "")
				{
					cout << "ERROR GD004 - A problem occured while getting the animation's name in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get posX
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1)
				{
					cout << "ERROR GD005 - A problem occured while getting the X position in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				posX = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(posX == -1)
				{
					cout << "ERROR GD006 - A problem occured while getting the X position in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get posY
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1)
				{
					cout << "ERROR GD007 - A problem occured while getting the Y position in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				posY = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(posY == -1)
				{
					cout << "ERROR GD008 - A problem occured while getting the Y position in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get spriteWidth
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1)
				{
					cout << "ERROR GD009 - A problem occured while getting the sprite's width in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				spriteWidth = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(spriteWidth == -1)
				{
					cout << "ERROR GD010 - A problem occured while getting the sprite's width in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get spriteHeight
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1)
				{
					cout << "ERROR GD011 - A problem occured while getting the sprite's height in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				spriteHeight = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(spriteHeight == -1)
				{
					cout << "ERROR GD012 - A problem occured while getting the sprite's height in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get framerate
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1)
				{
					cout << "ERROR GD013 - A problem occured while getting the framerate in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				framerate = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(framerate == -1)
				{
					cout << "ERROR GD014 - A problem occured while getting the framerate in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get spriteNb
				posDelimStart = posDelimEnd;
				posDelimEnd = findFrom(currentLine,posDelimStart+1,' ');
				if(posDelimEnd == -1)
				{
					cout << "ERROR GD015 - A problem occured while getting the number of sprites in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				posDelimStart++;

				spriteNb = myAtoi(mySubStringToChar(currentLine,posDelimStart,posDelimEnd));
				if(spriteNb == -1)
				{
					cout << "ERROR GD016 - A problem occured while getting the number of sprites in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				// Get animationLoop
				posDelimStart = posDelimEnd;

				posDelimStart++;

				transform(currentLine.begin(),currentLine.end(),currentLine.begin(),::tolower);
				animationLoopStr = mySubStringToChar(currentLine,posDelimStart,currentLine.at(currentLine.length()-1));			
				if((strcmp(animationLoopStr,"true") != 0) && (strcmp(animationLoopStr,"false") != 0))
				{
					cout << "ERROR GD017 - A problem occured while getting the loop animation value in this line:\n	" << currentLine << endl;
					system("Pause");
					return 1;
				}

				animArray.push_back(*new AnimationLine(fileName,animationName,posX,posY,spriteWidth,spriteHeight,framerate,spriteNb,animationLoopStr));
			}
		}
	}
	else
	{
		cout << "ERROR OP001 - Can't open the animation file." << endl;
	}

	animFile.close();

	/*********************/
	/* Set the '.h' file */
	/*********************/

	// Set the location of the file
	headerOutputLocation = new char[strlen(outputLocation) + strlen("\\AnimationData.h") + 1];
	strcpy_s(headerOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(headerOutputLocation,strlen(headerOutputLocation)+strlen("\\AnimationData.h")+1,"\\AnimationData.h");
	
	// Create and open the file
	headerFile.open(headerOutputLocation, ios::out|ios::trunc);
	animationData << animArray.size();

	if(headerFile)
	{
		headerContent = "#ifndef __ANIMATIONDATA__\n";
		headerContent = headerContent + "#define __ANIMATIONDATA__\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "class AnimationData\n";
		headerContent = headerContent + "{\n";
		headerContent = headerContent + "private:\n";
		headerContent = headerContent + "	char* fileName;\n";
		headerContent = headerContent + "	char* animationName;\n";
		headerContent = headerContent + "	int posX;\n";
		headerContent = headerContent + "	int posY;\n";
		headerContent = headerContent + "	int spriteWidth;\n";
		headerContent = headerContent + "	int spriteHeight;\n";
		headerContent = headerContent + "	int framerate;\n";
		headerContent = headerContent + "	int spriteNb;\n";
		headerContent = headerContent + "	bool animationLoop;\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "public:\n";
		headerContent = headerContent + "	AnimationData();\n";
		headerContent = headerContent + "	AnimationData(char* fileName, char* animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop);\n";
		headerContent = headerContent + "	char* getFileName();\n";
		headerContent = headerContent + "	char* getAnimationName();\n";
		headerContent = headerContent + "	int getPosX();\n";
		headerContent = headerContent + "	int getPosY();\n";
		headerContent = headerContent + "	int getSpriteWidth();\n";
		headerContent = headerContent + "	int getSpriteHeight();\n";
		headerContent = headerContent + "	int getFramerate();\n";
		headerContent = headerContent + "	int getSpriteNb();\n";
		headerContent = headerContent + "	bool getAnimationLoop();\n";
		headerContent = headerContent + "	~AnimationData(void);\n";
		headerContent = headerContent + "};\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "#define NUMBER_ANIMATIONDATA " + animationData.str() + "\n";
		headerContent = headerContent + "\n";
		headerContent = headerContent + "extend const AnimationData animationDataArray[NUMBER_ANIMATIONDATA];\n";
		headerContent = headerContent + "\n";
		

		// Go to the beginning of the list
		std::list<AnimationLine>::iterator it = animArray.begin();

		// Define the animations' name
		for(position = 0; position < animArray.size(); position++)
		{
			std::advance(it, position);
			animationData.str("");
			animationData << it->getAnimationName();
			headerContent = headerContent + "#define " + animationData.str() + " ";
			animationData.str("");
			animationData << position;
			headerContent = headerContent + animationData.str() + "\n";
		}

		headerContent = headerContent + "\n";
		headerContent = headerContent + "#endif __ANIMATIONDATA__\n";

		headerFile << headerContent;
	}
	else
	{
		cout << "ERROR OP002 - Can't create the header file." << endl;
	}

	headerFile.close();

	/***********************/
	/* Set the '.cpp' file */
	/***********************/

	// Set the location of the file
	cppOutputLocation = new char[strlen(outputLocation) + strlen("\\AnimationData.cpp") + 1];
	strcpy_s(cppOutputLocation,strlen(outputLocation)+1,outputLocation);
	strcat_s(cppOutputLocation,strlen(cppOutputLocation)+strlen("\\AnimationData.cpp")+1,"\\AnimationData.cpp");
	
	// Create and open the file
	cppFile.open(cppOutputLocation, ios::out|ios::trunc);

	if(cppFile)
	{
		animationData.str("");
		animationData << "AnimationData";

		cppContent = "#include \"" + animationData.str() + ".h\"\n";
		cppContent = cppContent + "\n";

		animationData.str("");
		animationData << animArray.size();
		cppContent = cppContent + "const AnimationData animationDataArray[NUMBER_ANIMATIONDATA] =\n";
		cppContent = cppContent + "{\n";

		// Go to the beginning of the list
		std::list<AnimationLine>::iterator it = animArray.begin();

		// Put all the data into the animationArray in the cpp file
		for(position = 0; position < animArray.size(); position++)
		{
			std::advance(it, position);

			cppContent = cppContent + "	{\n";
			
			// Put : fileName
			animationData.str("");
			animationData << it->getFileName();
			cppContent = cppContent + "		\"" + animationData.str() + "\",\n";

			// Put : animatioName
			animationData.str("");
			animationData << it->getAnimationName();
			cppContent = cppContent + "		" + animationData.str() + ",\n";

			// Put : posX
			animationData.str("");
			animationData << it->getPosX();
			cppContent = cppContent + "		" + animationData.str() + ",\n";

			// Put : posY
			animationData.str("");
			animationData << it->getPosY();
			cppContent = cppContent + "		" + animationData.str() + ",\n";
			
			// Put : spriteWidth
			animationData.str("");
			animationData << it->getSpriteWidth();
			cppContent = cppContent + "		" + animationData.str() + ",\n";
			
			// Put : spriteHeight
			animationData.str("");
			animationData << it->getSpriteHeight();
			cppContent = cppContent + "		" + animationData.str() + ",\n";

			// Put : framerate
			animationData.str("");
			animationData << it->getFramerate();
			cppContent = cppContent + "		" + animationData.str() + ",\n";

			// Put : spriteNb
			animationData.str("");
			animationData << it->getSpriteNb();
			cppContent = cppContent + "		" + animationData.str() + ",\n";

			// Put : animationLoop
			animationData.str("");
			animationData << it->getAnimationLoop();
			cppContent = cppContent + "		" + animationData.str() + "\n";

			cppContent = cppContent + "	}";

			if(animArray.size() > 1)
			{
				if(position != animArray.size()-1)
					cppContent = cppContent + ",";
			}

			cppContent = cppContent + "\n";
		}
		
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "AnimationData::AnimationData()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->fileName = \"\";\n";
		cppContent = cppContent + "\tthis->animationName = \"\";\n";
		cppContent = cppContent + "\tthis->posX = 0;\n";
		cppContent = cppContent + "\tthis->posY = 0;\n";
		cppContent = cppContent + "\tthis->spriteWidth = 0;\n";
		cppContent = cppContent + "\tthis->spriteHeight = 0;\n";
		cppContent = cppContent + "\tthis->framerate = 0;\n";
		cppContent = cppContent + "\tthis->spriteNb = 0;\n";
		cppContent = cppContent + "\tthis->animationLoop = false;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "AnimationData::AnimationData(char* fileName, char* animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tthis->fileName = new char[strlen(fileName)+1];\n";
		cppContent = cppContent + "\tstrcpy_s(this->fileName,strlen(fileName)+1, fileName);\n\n";
		cppContent = cppContent + "\tthis->animationName = new char[strlen(animationName)+1];\n";
		cppContent = cppContent + "\tstrcpy_s(this->animationName,strlen(animationName)+1, animationName);\n";
		cppContent = cppContent + "\tthis->posX = posX;\n";
		cppContent = cppContent + "\tthis->posY = posY;\n";
		cppContent = cppContent + "\tthis->spriteWidth = spriteWidth;\n";
		cppContent = cppContent + "\tthis->spriteHeight = spriteHeight;\n";
		cppContent = cppContent + "\tthis->framerate = framerate;\n";
		cppContent = cppContent + "\tthis->spriteNb = spriteNb;\n\n";
		cppContent = cppContent + "\tthis->animationLoop = animationLoop;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "char* AnimationData::getFileName()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->fileName;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "char* AnimationData::getAnimationName()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->animationName;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int AnimationData::getPosX()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->posX;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int AnimationData::getPosY()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->posY;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int AnimationData::getSpriteWidth()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->spriteWidth;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int AnimationData::getSpriteHeight()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->spriteHeight;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int AnimationData::getFramerate()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->framerate;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "int AnimationData::getSpriteNb()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->spriteNb;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "\n";
		cppContent = cppContent + "bool AnimationData::getAnimationLoop()\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\treturn this->animationLoop;\n";
		cppContent = cppContent + "}\n";
		cppContent = cppContent + "AnimationData::~AnimationData(void)\n";
		cppContent = cppContent + "{\n";
		cppContent = cppContent + "\tdelete[] this->fileName;\n";
		cppContent = cppContent + "\tdelete[] this->animationName;\n";
		cppContent = cppContent + "}\n";
		
		cppFile << cppContent;
	}
	else
	{
		cout << "ERROR OP003 - Can't create the .cpp file." << endl;
	}

	cppFile.close();

	/*****************/
	/* Final message */
	/*****************/

	cout << endl << endl << "The following 2 files have been successfully generated :" << endl;
	cout << "	- AnimationData.h" << endl;
	cout << "	- AnimationData.cpp" << endl;
	cout << "into the folder :" << endl;
	cout << "	- " << outputLocation << endl << endl;

	system("Pause");
	return 0;
}