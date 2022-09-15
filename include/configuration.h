#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "chessBoard.h"
#include "configurationItem.h"

#include <iostream>
#include <fstream>
#include <string>

/*
Classe che definisce l'oggetto configurazione che rappresenta
con un vector di struct ConfigurationItem la configurazione
della scacchiera in un dato istante.
Deve poter essere in grado di acquisire da file una configurazione
passata sotto formato di testo (sequenze di tipo,posizione) e memorizzarli
nei ConfigurationItem del itemsVector creando cosi' la configurazione
*/

class Configuration
{

public:
    // Represents a configuration
    std::vector<ConfigurationItem> itemsVector;

    Configuration();
    ~Configuration();

    void printConfiguration();

};


#endif