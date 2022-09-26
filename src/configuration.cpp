#include "configuration.h"

#include <iostream>
#include <fstream>

bool parseItem(ConfigurationItem& item,string& line)
{
	enum LineColumn{ Color = 0, Type, Life, X_Pos, Y_Pos, NColumns};
	
	if(line.size() != NColumns)
	{
		return false;
	}

	char colorName = line[Color];
	switch(colorName)
	{
		case 'w':
		{
			item.color = Piece::Color::White;
			break;
		}
		case 'b':
		{
			item.color = Piece::Color::Black;
			break;
		}
		default:
		{
			return false;
		}
	}

	char typeName = line[Type];
	item.type = Piece::parseTypeShortName(typeName);
	if(item.type == Piece::Type::NTypes)
		return false;

	char lifeName = line[Life];
	switch(lifeName)
	{
		case 'l':
		{
			item.live = true;
			break;
		}
		case 'd':
		{
			item.live = false;
			break;
		}
		default:
		{
			return false;
		}
	}

	int x = (int)line[3] - '0';
	int y = (int)line[4] - '0';
	item.pos = Position(x, y);

	return true;
}

Configuration::Configuration(string fileName)
{
	fstream myFile;
	myFile.open(fileName, ios::in);
	if (!myFile) {
		cout << "No such file";
		return;
	}

	std::string line;
	int row = 0;
    while(std::getline(myFile, line))
    {
        std::cout << line << std::endl;

		ConfigurationItem item;
		if(!parseItem(item, line))
		{
			cout << "Errore nel file alla riga " << row << std::endl;
		}
		itemsVector.push_back(item);

		row++;
    }

	myFile.close();
}

Configuration::~Configuration()
{
    
}

void Configuration::printConfiguration()
{
	cout << "Configuration is : " << endl;
	for(auto item : itemsVector){
		item.print();
	}
	cout << "End configuration" << endl;
}