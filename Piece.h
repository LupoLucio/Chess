#ifndef PIECE_H
#define PIECE_H

#include "Position.h"
#include <vector>

/*
Classe che definisce il modo generico il pezzo in una scacchiera.
*/

class Piece
{
public:
    enum class Color { White = 0, Black, NColors };

    // costruttore che crea un Piece
    Piece(Color color, bool alive, Position p);

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
    bool isOppositeColor(Piece *piece);

    Position getPosition();

    void setPosition(Position pos);

    inline Color getColor() const { return m_color; }

    static inline Color getOppositColor(Color c)
    {
        //Cast to int to do a NOT and then back to enum
        return Color(!int(c));
    }

public:
    static string getColorName(Color c);

public:
    // oggetto Position p per la posizione nella board
    Position p;
    // bool isAlive per stabilire se è vivo
    bool isAlive, isVirgin = 1, isPinned;
    // array di posizioni controllate nella board
    std::vector<Position> controlledPos;
    // array di posizioni accessibili nella board
    std::vector<Position> accessiblePos;
    // array di posizioni controllate ipotetiche servono per controllare se il pezzo è pinnato
    std::vector<Position> ipoControlledPos;
    // array di posizioni accessibili ipotetiche servono per controllare se il pezzo è pinnato
    std::vector<Position> ipoAccessiblePos;

private:
    Color m_color;
};

#endif
