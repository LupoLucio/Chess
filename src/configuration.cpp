#include "configuration.h"

#include <iostream>
#include <fstream>

bool parseItem(ConfigurationItem& item,string& line)
{
	if(line.size() != 4)
	{
		return false;
	}

	int n0 = (int)line[0]-48;
	int n1 = (int)line[1]-48;
	int n2 = (int)line[2]-48;
	int n3 = (int)line[3]-48;

	Piece::Color colore;
	Piece::Type tipo;
	Position posizione;

	switch(n0){
		case 0:
			colore = Piece::Color::White;
			break;
		case 1:
			colore = Piece::Color::Black;
			break;
		default:
			return false;
			break;
	}

	switch(n1){
    case 0:
        tipo = Piece::Type::Bishop;
        break;
    case 1:
		tipo = Piece::Type::King;
        break;
	case 2:
		tipo = Piece::Type::Knight;
		break;
	case 3:
		tipo = Piece::Type::Pawn;
		break;
	case 4:
		tipo = Piece::Type::Queen;
		break;
	case 5:
		tipo = Piece::Type::Rook;
		break;
    default:
		return false;
		break;
	}

	posizione = Position(n2,n3);


	item.color = colore;
	item.type = tipo;
	item.pos = posizione;

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
		item.print();
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