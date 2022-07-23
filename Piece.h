#ifndef PIECE_H
#define PIECE_H

#include "Position.h"
#include <vector>


/*
Classe che definisce il modo generico il pezzo in una scacchiera.
*/

class Piece{

    public:
    // oggetto Position p per la posizione nella board
    Position p;
    // bool isWhite per il colore e isLive per stabilire se è vivo
    bool isWhite,isLive,isVirgin = 1;
    // array di posizioni controllate nella board
    std::vector<Position> controlledPos;
    // array di posizioni accessibili nella board
    std::vector<Position> accessiblePos;

    // costruttore di default
    Piece()=default;
    // costruttore che crea un Piece
    Piece(bool color,bool live,Position p);

    // funzione move che cambia l'oggetto p di Piece a newP spostando il pezzo
    void move(Position newP);
    // altre che muovere in newP deve anche eliminare il mangiato
    void eat(Position newP);

    // stampa posizioni controllate
    void printControlledPos();
    // stampa posizioni accessibili
    void printAccessiblePos();
    // stampa posizioni controllate e accessibili
    void printAllPos();
    // funzione virtual implemntata nelle singole sottoclassi
    virtual void printPiece();

    // operatore ugualianza fra un Piece e un puntatore a Piece
    bool operator==(Piece *piece);
    // ritorna se il piece puntato è di colore opposto al colore dell'invocante
    bool isOpposite(Piece *piece);

    Position getPosition();



    // booleani sul tipo di pezzo
    /*bool isKing();
    bool isQueen();
    bool isRook();
    bool isBishop();
    bool isKnight();
    bool isPawn();
    */

};


#endif