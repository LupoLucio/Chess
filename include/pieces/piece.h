#ifndef PIECE_H
#define PIECE_H

#include "position.h"
#include <vector>
#include <string>

/*
Classe che definisce il modo generico il pezzo in una scacchiera.
*/

class Piece
{
public:
    enum class Color { White = 0, Black, NColors };

    enum class Type { Bishop = 0, King, Knight, Pawn, Queen, Rook, NTypes };

    static constexpr int INVALID_NUMBER = -1;

    // costruttore che crea un Piece
    Piece(Type type, Color color, bool alive, Position p);

    // funzione move che cambia l'oggetto m_pos di Piece a newP spostando il pezzo
    void move(const Position &newPos);
    // stampa posizioni controllate
    void printControlledPos();
    // stampa posizioni accessibili
    void printAccessiblePos();
    // stampa posizioni controllate e accessibili
    void printAllPos();
    // funzione virtual implemntata nelle singole sottoclassi
    virtual void printPiece();

    // operatore ugualianza fra un Piece e un puntatore a Piece
    bool operator==(const Piece &other) const;
    // ritorna se il piece puntato è di colore opposto al colore dell'invocante
    bool isOppositeColor(Piece *piece);

    Position getPosition();

    void setPosition(Position pos);

    inline Color getColor() const { return m_color; }

    static inline Color getOppositColor(Color c)
    {
        // Cast to int to do a NOT and then back to enum
        return Color(!int(c));
    }

    inline Type getType() const { return m_type; }

    inline int getNumber() const { return m_number; }

    inline void setNumber(int n) { m_number = n; }

public:
    static std::string getColorName(Color c);

    static std::string getTypeName(Type t);

public:
    // oggetto Position p per la posizione nella board
    Position m_pos;
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
    Type m_type;
    // Piece number relative to its type, i.e. Pawn 1, Pawn 2...
    int m_number = INVALID_NUMBER;
};

#endif
