#include "chessboard.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"

// FIXME: remove when user input and logic are fully separated
#include <iostream>
using namespace std;

/*

    0    1    2    3    4    5    6    7

    1

    2

    3

    4

    5

    6

    7

*/

ChessBoard::ChessBoard()
{
    Configuration defaultConf = {
        { Piece::Type::King, Position(4, 0) },   { Piece::Type::Queen, Position(3, 0) },
        { Piece::Type::Rook, Position(0, 0) },   { Piece::Type::Rook, Position(7, 0) },
        { Piece::Type::Bishop, Position(2, 0) }, { Piece::Type::Bishop, Position(5, 0) },
        { Piece::Type::Knight, Position(1, 0) }, { Piece::Type::Knight, Position(6, 0) },
        { Piece::Type::Pawn, Position(0, 1) },   { Piece::Type::Pawn, Position(1, 1) },
        { Piece::Type::Pawn, Position(2, 1) },   { Piece::Type::Pawn, Position(3, 1) },
        { Piece::Type::Pawn, Position(4, 1) },   { Piece::Type::Pawn, Position(5, 1) },
        { Piece::Type::Pawn, Position(6, 1) },   { Piece::Type::Pawn, Position(7, 1) }
    };

    initConfiguration(defaultConf);

    generateAllPos();
}

ChessBoard::~ChessBoard()
{
    clear();
}

void ChessBoard::clear()
{
    for (Piece *piece : pieceVector)
    {
        delete piece;
    }
    pieceVector.clear();
}

Piece *createPiece(Piece::Type type, Piece::Color color, const Position &pos)
{
    switch (type)
    {
    case Piece::Type::Bishop:
        return new Bishop(color, true, pos);
    case Piece::Type::King:
        return new King(color, true, pos);
    case Piece::Type::Knight:
        return new Knight(color, true, pos);
    case Piece::Type::Pawn:
        return new Pawn(color, true, pos);
    case Piece::Type::Queen:
        return new Queen(color, true, pos);
    case Piece::Type::Rook:
        return new Rook(color, true, pos);
    default:
        break;
    }

    return nullptr;
}

void ChessBoard::initConfiguration(const Configuration &conf)
{
    // Clear previous configuration
    clear();

    int counters[int(Piece::Type::NTypes)] = { 0 };

    for (auto pieceDef : conf)
    {
        // Mirror position for black piece
        Position blackPos = pieceDef.pos;
        blackPos.setY(7 - blackPos.getY());

        Piece *whitePiece = createPiece(pieceDef.type, Piece::Color::White, pieceDef.pos);
        Piece *blackPiece = createPiece(pieceDef.type, Piece::Color::Black, blackPos);
        ;

        int &num = counters[int(whitePiece->getType())];
        whitePiece->setNumber(num);
        blackPiece->setNumber(num);
        num++;

        pieceVector.push_back(whitePiece);
        pieceVector.push_back(blackPiece);
    }
}

void ChessBoard::printPieces()
{
    cout << "Pieces are :  " << endl;

    for (auto &piece : pieceVector)
    {
        piece->printPiece();
    }

    cout << "End Pieces" << endl;
}

bool ChessBoard::isOccpied(Position pos)
{
    return getPieceAtPos(pos) != nullptr;
}

Piece *ChessBoard::getPieceAtPos(Position pos)
{
    for (const auto &piece : pieceVector)
    {
        if (piece->isAlive && piece->m_pos == pos)
        {
            return piece;
        }
    }

    return nullptr;
}

Piece *ChessBoard::getPieceByType(Piece::Color color, Piece::Type type, int num)
{
    for (const auto &piece : pieceVector)
    {
        if (piece->getColor() == color && piece->getType() == type)
        {
            if (num == Piece::INVALID_NUMBER)
                return piece; // We don't care about number

            // We care about number
            if (piece->getNumber() == num)
                return piece;
        }
    }

    return nullptr;
}

bool ChessBoard::isPositionValid(Position p)
{
    return (p.getX() <= 7 && p.getX() >= 0 && p.getY() <= 7 && p.getY() >= 0);
}

void ChessBoard::generatePos(Piece *piece)
{
    // ogni volta che le genero le pulisco prima
    clearPos(piece);
    // check se è King
    if (piece->getType() == Piece::Type::King)
    {
        // check posizione alto a sx
        Position pos = piece->m_pos + Position(-1, 1);
        if (isPositionValid(pos))
        {
            piece->controlledPos.push_back(pos);
            if (!isOccpied(pos))
                piece->accessiblePos.push_back(pos);
        }

        // check posizione in alto
        pos = piece->m_pos + Position(0, 1);
        if (isPositionValid(pos))
        {
            piece->controlledPos.push_back(pos);
            if (!isOccpied(pos))
                piece->accessiblePos.push_back(pos);
        }

        // check posizione alto a dx
        pos = piece->m_pos + Position(1, 1);
        if (isPositionValid(pos))
        {
            piece->controlledPos.push_back(pos);
            if (!isOccpied(pos))
                piece->accessiblePos.push_back(pos);
        }

        // check posizione a dx
        pos = piece->m_pos + Position(1, 0);
        if (isPositionValid(pos))
        {
            piece->controlledPos.push_back(pos);
            if (!isOccpied(pos))
                piece->accessiblePos.push_back(pos);
        }

        // check posizione in basso a dx
        pos = piece->m_pos + Position(1, -1);
        if (isPositionValid(pos))
        {
            piece->controlledPos.push_back(pos);
            if (!isOccpied(pos))
                piece->accessiblePos.push_back(pos);
        }

        // check posizione in basso
        pos = piece->m_pos + Position(0, -1);
        if (isPositionValid(pos))
        {
            piece->controlledPos.push_back(pos);
            if (!isOccpied(pos))
                piece->accessiblePos.push_back(pos);
        }

        // check posizione in basso a sx
        pos = piece->m_pos + Position(-1, -1);
        if (isPositionValid(pos))
        {
            piece->controlledPos.push_back(pos);
            if (!isOccpied(pos))
                piece->accessiblePos.push_back(pos);
        }

        // check posizione a sx
        pos = piece->m_pos + Position(-1, 0);
        if (isPositionValid(pos))
        {
            piece->controlledPos.push_back(pos);
            if (!isOccpied(pos))
                piece->accessiblePos.push_back(pos);
        }
    }
    // check se è Queen
    else if (piece->getType() == Piece::Type::Queen)
    {
        // check posizioni in alto sx
        int i = 1;

        while (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i))
               && !isOccpied(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i));
        }
        // check posizione in alto
        i = 1;

        while (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i))
               && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i));
        }
        // check posizioni in alto a dx
        i = 1;

        while (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i))
               && !isOccpied(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i));
        }
        // check posizioni a dx
        i = 1;

        while (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()))
               && !isOccpied(Position((piece->m_pos).getX() + i, (piece->m_pos).getY())))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY())))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()));
        }
        // check posizioni in basso a dx
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i))
               && !isOccpied(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i));
        }
        // check posizioni in basso
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i))
               && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i));
        }
        // check posizioni in basso a sx
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i))
               && !isOccpied(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i));
        }
        // check posizioni a sx
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()))
               && !isOccpied(Position((piece->m_pos).getX() - i, (piece->m_pos).getY())))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY())))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()));
        }
    }
    // check se è Rook
    else if (piece->getType() == Piece::Type::Rook)
    {
        // check posizione in alto
        int i = 1;

        while (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i))
               && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i));
        }
        // check posizioni in basso
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i))
               && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i));
        }
        // check posizioni a sx
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()))
               && !isOccpied(Position((piece->m_pos).getX() - i, (piece->m_pos).getY())))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY())))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()));
        }
        // check posizioni a dx
        i = 1;

        while (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()))
               && !isOccpied(Position((piece->m_pos).getX() + i, (piece->m_pos).getY())))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY())))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()));
        }
    }
    // check se è Bhishop
    else if (piece->getType() == Piece::Type::Bishop)
    {
        // check posizioni in alto sx
        int i = 1;

        while (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i))
               && !isOccpied(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i));
        }
        // check posizioni in alto a dx
        i = 1;

        while (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i))
               && !isOccpied(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i));
        }
        // check posizioni in basso a dx
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i))
               && !isOccpied(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i));
        }
        // check posizioni in basso a sx
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i))
               && !isOccpied(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i));
        }
    }
    // check se è knight
    else if (piece->getType() == Piece::Type::Knight)
    {

        // check posizione medio alto sx
        if (isPositionValid(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() + 1))
            && !isOccpied(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() + 1)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() + 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() + 1)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() + 1));
        }
        // check posizione alto sx
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 2))
            && !isOccpied(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 2)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 2));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 2)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 2));
        }
        // check posizione alto dx
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 2))
            && !isOccpied(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 2)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 2));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 2)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 2));
        }
        // check posizione medio alto dx
        if (isPositionValid(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() + 1))
            && !isOccpied(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() + 1)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() + 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() + 1)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() + 1));
        }
        // check posizione medio basso dx
        if (isPositionValid(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() - 1))
            && !isOccpied(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() - 1)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() - 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() - 1)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() - 1));
        }
        // check posizione basso dx
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 2))
            && !isOccpied(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 2)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 2));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 2)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 2));
        }
        // check posizione basso sx
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 2))
            && !isOccpied(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 2)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 2));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 2)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 2));
        }
        // check posizione medio basso sx
        if (isPositionValid(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() - 1))
            && !isOccpied(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() - 1)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() - 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() - 1)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() - 1));
        }
    }
    // check se è Pawn
    else if (piece->getType() == Piece::Type::Pawn)
    {
        // check if white
        if (piece->getColor() == Piece::Color::White)
        {

            // check posizione alto a sx
            if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1)))
            {
                (piece->controlledPos)
                        .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1));
            }

            // check posizione alto a dx
            if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1)))
            {
                (piece->controlledPos)
                        .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1));
            }

            // check posizione alto unica per le accessibili
            if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1))
                && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1)))
            {
                (piece->accessiblePos)
                        .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1));
            }
            // check se è vergine
            if (piece->isVirgin)
            {
                // check posizione alto di 2
                if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 2)))
                {
                    (piece->accessiblePos)
                            .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 2));
                }
            }
        }
        else
        {
            // check posizione basso a sx
            if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1)))
            {
                (piece->controlledPos)
                        .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1));
            }
            // check posizione basso a dx
            if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1)))
            {
                (piece->controlledPos)
                        .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1));
            }
            // check posizione basso unica per le accessibili
            if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1))
                && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1)))
            {
                (piece->accessiblePos)
                        .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1));
            }
            // check se è vergine
            if (piece->isVirgin)
            {
                // check posizione basso di 2
                if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 2)))
                {
                    (piece->accessiblePos)
                            .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 2));
                }
            }
        }
    }

    mergePos(piece);
}

void ChessBoard::clearPos(Piece *piece)
{
    piece->accessiblePos.clear();
    piece->controlledPos.clear();
}

void ChessBoard::killPiece(Piece *piece)
{
    piece->isAlive = false;
    return;
}

void ChessBoard::killPieceVerginity(Piece *piece)
{
    piece->isVirgin = false;
    return;
}

bool ChessBoard::isKingInCheck(Piece::Color color)
{
    // FIXME: find piece by type and color instead of index
    return color == Piece::Color::Black ? ((King *)pieceVector[0])->isInCheck
                                        : ((King *)pieceVector[1])->isInCheck;
}

bool ChessBoard::beginMove(Piece *piece, Position pos)
{
    // controllo se il pezzo puo' muovere
    if (!canMove(piece, pos))
        return false;

    // controllo se posso puo' mangiare, se puo' ritorno la mossa è finita
    if (canEat(piece, pos))
    {
        //Eat opposite piece
        Piece *temp = getPieceAtPos(pos);
        killPiece(temp);
    }

    piece->move(pos);
    // uccido la sua verginita (setto a 0 il suo isVirgin)
    if (piece->isVirgin)
    {
        killPieceVerginity(piece);
    }

    return true;
}

void ChessBoard::endMove(Piece *piece)
{
    // genero le posizioni per tutti i pezzi (posizioni accessibili e controllate cambiano per
    // ogni pezzo)
    generateAllPos();
    mergePos(piece);
    // setto se il re opposto al pezzo mosso è in Scacco
    setKingCheck(Piece::getOppositColor(piece->getColor()));
    // setto se il re che ha mosso è in Scacco (nel caso in cui va a mangiare (liberandosi dallo
    // scacco), il suo isInCheck da 1 va a 0)
    setKingCheck(piece->getColor());
    // se il re del colore opposto è in scacco faccio una stampa
    if (isKingInCheck(Piece::getOppositColor(piece->getColor())))
    {
        cout << "Re colore " << Piece::getColorName(Piece::getOppositColor(piece->getColor()))
             << "in Scacco" << endl;
    }
}

Piece *ChessBoard::queenning(Piece *pawn, Piece::Type newType)
{
    if (!pawn || pawn->getType() != Piece::Type::Pawn)
        return pawn;

    if (pawn->getColor() == Piece::Color::White && pawn->m_pos.getY() != 7)
        return pawn;

    if (pawn->getColor() == Piece::Color::Black && pawn->m_pos.getY() != 0)
        return pawn;

    Piece *replacement = createPiece(newType, pawn->getColor(), pawn->m_pos);

    replacement->setNumber(pawn->getNumber() + 2); //Add 2 for knight, rook, bishop

    for(int i = 0; i < pieceVector.size(); i++)
    {
        if(pieceVector[i] == pawn)
        {
            //Replace
            pieceVector[i] = replacement;

            //Delete old pawn
            delete pawn;
            pawn = nullptr;
            break;
        }
    }

    if(pawn)
    {
        //We did not find it in piece vector
        cout << "Queening error: piece not found" << endl;
        pawn->printPiece();
        cout << "Keeping old piece" << endl;

        delete replacement;
        replacement = nullptr;

        return pawn;
    }

    return replacement;
}

bool ChessBoard::canQueen(Piece *piece)
{
    if (piece->getType() != Piece::Type::Pawn)
    {
        return false; // Only Pawns can became Queens
    }
    else if (piece->getColor() == Piece::Color::White)
    {
        return piece->m_pos.getY() == 7;
    }
    else
    {
        return piece->m_pos.getY() == 0;
    }
}

void ChessBoard::setKingCheck(Piece::Color color)
{
    cout << "Try Check" << endl;

    King *K = static_cast<King *>(getPieceByType(color, Piece::Type::King));

    for (auto &piece : pieceVector)
    {
        if (piece->getColor() != color)
        {
            for (const Position &p : piece->controlledPos)
            {
                if (p == K->m_pos)
                {
                    K->isInCheck = true;
                    return;
                }
            }
        }
    }

    K->isInCheck = false;
}

void ChessBoard::generateAllPos()
{
    for (auto &piece : pieceVector)
    {
        generatePos(piece);
    }
}

bool ChessBoard::canEat(Piece *piece, Position pos)
{
    Piece *temp = getPieceAtPos(pos);
    if (piece->getType() != Piece::Type::King)
    {
        return temp && piece->isOppositeColor(temp);
    }
    else
    {
        return !willKingBeInCheck(piece->getColor(), pos);
    }
}

void ChessBoard::mergePos(Piece *piece)
{
    for (int i = 0; i < piece->controlledPos.size(); i++)
    {
        // se la nella posizione controllata posso mangiare e la posizione non è gia presente, allora la faccio diventare accessibile
        if (canEat(piece, piece->controlledPos[i]) && !isInAccessiblePos(piece,piece->controlledPos[i]))
        {
            piece->accessiblePos.push_back(piece->controlledPos[i]);
        }
    }
}
bool ChessBoard::willKingBeInCheck(Piece::Color color, Position pos)
{
    for (auto &piece : pieceVector)
    {
        if (piece->getColor() != color)
        {
            for (const Position &p : piece->controlledPos)
            {
                if (p == pos)
                {
                    return true;
                }
            }
        }
    }

    // se si è arrivati qua piece è re e pos non è controllata da nessun pezzo opposto
    return false;
}

bool ChessBoard::isInAccessiblePos(Piece *piece, Position p){
    for(int i = 0; i < piece->accessiblePos.size(); i++){
        if(piece->accessiblePos[i] == p) return true;
    }

    return false;
}
bool ChessBoard::isInControlledPos(Piece *piece, Position p){
    for(int i = 0; i < piece->controlledPos.size(); i++){
        if(piece->controlledPos[i] == p) return true;
    }

    return false;    
}