#include "Bishop.h"
#include "ChessBoard.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

template<typename Base, typename T>
inline bool instanceof (const T *ptr)
{
    return dynamic_cast<const Base *>(ptr) != nullptr;
}

void ChessBoard::generateIpoPos(Piece *piece)
{
    // ogni volta che le genero le pulisco prima
    clearIpoPos(piece);
    // check se è King
    if (instanceof <King>(piece))
    {

        // check posizione alto a sx
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1))
            && !isOccpied(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1));
        }

        // check posizione in alto
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1))
            && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1)))
        {
            (piece->ipoAccessiblePos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1)))
        {
            (piece->ipoControlledPos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1));
        }

        // check posizione alto a dx
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1))
            && !isOccpied(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1));
        }

        // check posizione a dx
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY()))
            && !isOccpied(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY())))
        {
            (piece->ipoAccessiblePos).push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY()));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY())))
        {
            (piece->ipoControlledPos).push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY()));
        }
        // check posizione in basso a dx
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1))
            && !isOccpied(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1));
        }
        // check posizione in basso
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1))
            && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1)))
        {
            (piece->ipoAccessiblePos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1)))
        {
            (piece->ipoControlledPos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1));
        }
        // check posizione in basso a sx
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1))
            && !isOccpied(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1));
        }
        // check posizione a sx
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY()))
            && !isOccpied(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY())))
        {
            (piece->ipoAccessiblePos).push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY()));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY())))
        {
            (piece->ipoControlledPos).push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY()));
        }
    }
    // check se è Queen
    else if (instanceof <Queen>(piece))
    {

        // check posizioni in alto sx
        int i = 1;

        while (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i))
               && !isOccpied(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i));
        }
        // check posizione in alto
        i = 1;

        while (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i))
               && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i)))
        {
            (piece->ipoAccessiblePos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i)))
        {
            (piece->ipoControlledPos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i));
        }
        // check posizioni in alto a dx
        i = 1;

        while (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i))
               && !isOccpied(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i));
        }
        // check posizioni a dx
        i = 1;

        while (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()))
               && !isOccpied(Position((piece->m_pos).getX() + i, (piece->m_pos).getY())))
        {
            (piece->ipoAccessiblePos).push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY())))
        {
            (piece->ipoControlledPos).push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()));
        }
        // check posizioni in basso a dx
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i))
               && !isOccpied(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i));
        }
        // check posizioni in basso
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i))
               && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i)))
        {
            (piece->ipoAccessiblePos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i)))
        {
            (piece->ipoControlledPos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i));
        }
        // check posizioni in basso a sx
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i))
               && !isOccpied(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i));
        }
        // check posizioni a sx
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()))
               && !isOccpied(Position((piece->m_pos).getX() - i, (piece->m_pos).getY())))
        {
            (piece->ipoAccessiblePos).push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY())))
        {
            (piece->ipoControlledPos).push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()));
        }
    }
    // check se è Rook
    else if (instanceof <Rook>(piece))
    {
        // check posizione in alto
        int i = 1;

        while (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i))
               && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i)))
        {
            (piece->ipoAccessiblePos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i)))
        {
            (piece->ipoControlledPos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i));
        }
        // check posizioni in basso
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i))
               && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i)))
        {
            (piece->ipoAccessiblePos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i)))
        {
            (piece->ipoControlledPos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i));
        }
        // check posizioni a sx
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()))
               && !isOccpied(Position((piece->m_pos).getX() - i, (piece->m_pos).getY())))
        {
            (piece->ipoAccessiblePos).push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY())))
        {
            (piece->ipoControlledPos).push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()));
        }
        // check posizioni a dx
        i = 1;

        while (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()))
               && !isOccpied(Position((piece->m_pos).getX() + i, (piece->m_pos).getY())))
        {
            (piece->ipoAccessiblePos).push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY())))
        {
            (piece->ipoControlledPos).push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()));
        }
    }
    // check se è Bhishop
    else if (instanceof <Bishop>(piece))
    {
        // check posizioni in alto sx
        int i = 1;

        while (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i))
               && !isOccpied(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() + i));
        }
        // check posizioni in alto a dx
        i = 1;

        while (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i))
               && !isOccpied(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() + i));
        }
        // check posizioni in basso a dx
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i))
               && !isOccpied(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY() - i));
        }
        // check posizioni in basso a sx
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i))
               && !isOccpied(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY() - i));
        }
    }
    // check se è knight
    else if (instanceof <Knight>(piece))
    {

        // check posizione medio alto sx
        if (isPositionValid(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() + 1))
            && !isOccpied(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() + 1)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() + 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() + 1)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() + 1));
        }
        // check posizione alto sx
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 2))
            && !isOccpied(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 2)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 2));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 2)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 2));
        }
        // check posizione alto dx
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 2))
            && !isOccpied(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 2)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 2));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 2)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 2));
        }
        // check posizione medio alto dx
        if (isPositionValid(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() + 1))
            && !isOccpied(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() + 1)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() + 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() + 1)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() + 1));
        }
        // check posizione medio basso dx
        if (isPositionValid(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() - 1))
            && !isOccpied(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() - 1)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() - 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() - 1)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() + 2, (piece->m_pos).getY() - 1));
        }
        // check posizione basso dx
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 2))
            && !isOccpied(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 2)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 2));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 2)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 2));
        }
        // check posizione basso sx
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 2))
            && !isOccpied(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 2)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 2));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 2)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 2));
        }
        // check posizione medio basso sx
        if (isPositionValid(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() - 1))
            && !isOccpied(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() - 1)))
        {
            (piece->ipoAccessiblePos)
                    .push_back(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() - 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() - 1)))
        {
            (piece->ipoControlledPos)
                    .push_back(Position((piece->m_pos).getX() - 2, (piece->m_pos).getY() - 1));
        }
    }
    // check se è Pawn
    else if (instanceof <Pawn>(piece))
    {
        // check if white
        if (piece->getColor() == Piece::Color::White)
        {

            // check posizione alto a sx
            if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1)))
            {
                (piece->ipoControlledPos)
                        .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1));
            }

            // check posizione alto a dx
            if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1)))
            {
                (piece->ipoControlledPos)
                        .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1));
            }

            // check posizione alto unica per le accessibili
            if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1))
                && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1)))
            {
                (piece->ipoAccessiblePos)
                        .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1));
            }
            // check se è vergine
            if (piece->isVirgin)
            {
                // check posizione alto di 2
                if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 2)))
                {
                    (piece->ipoAccessiblePos)
                            .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 2));
                }
            }
        }
        else
        {
            // check posizione basso a sx
            if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1)))
            {
                (piece->ipoControlledPos)
                        .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1));
            }
            // check posizione basso a dx
            if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1)))
            {
                (piece->ipoControlledPos)
                        .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1));
            }
            // check posizione basso unica per le accessibili
            if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1))
                && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1)))
            {
                (piece->ipoAccessiblePos)
                        .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1));
            }
            // check se è vergine
            if (piece->isVirgin)
            {
                // check posizione basso di 2
                if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 2)))
                {
                    (piece->ipoAccessiblePos)
                            .push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 2));
                }
            }
        }
    }
}
void ChessBoard::generateAllIpoPos(Piece::Color color)
{
    for (auto &piece : Pieces)
    {
        if (piece->getColor() == color)
        {
            generateIpoPos(piece);
        }
    }
}
bool ChessBoard::willKingBeIpoInCheck(Piece::Color color)
{
    Position pos;
    Piece *K;
    //FIXME: get piece by type and color instead of by name
    if (color == Piece::Color::White)
    {
        K = searchPieceByName("white king");
        pos = K->m_pos;
    }
    else
    {
        K = searchPieceByName("black king");
        pos = K->m_pos;
    }

    for (auto &piece : Pieces)
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

void ChessBoard::clearIpoPos(Piece *piece)
{
    piece->ipoAccessiblePos.clear();
    piece->ipoControlledPos.clear();
}

/*uccido piece che è il pezzo che devo controllare se è pinnato, per tutti i pezzi opposti calcolo
le loro ipoControlledPos, se il re dello stesso colore di piece risulta in una delle
ipoControlledPos di uccisione
dei pezzi opposti ritorno true. !!Devo creare un metodo che genera le ipoControlledPos!!*/
bool ChessBoard::isPinned(Piece *piece)
{
    /*manca se piece isBetween prima devo controllare che anche piece sia nelle controllate dei
    pezzo opposti, se lo è, poi verifico che uccidendolo se il re del colore di piece risulta nella
    controllate del pezzo opposto allora true, questo per ogni pezzo*/

    // uccido il pezzo
    killPiece(piece);
    // genero le posizioni ipo dei pezzi del colore opposto a piece con lui morto
    generateAllIpoPos(Piece::getOppositColor(piece->getColor()));
    // se il re colore del pezzo risulta ipoteticamnete in sacco ritorno true, se no false
    if (willKingBeIpoInCheck(piece->getColor()))
    {
        revivePiece(piece);
        return true;
    }
    else
    {
        revivePiece(piece);
        return false;
    }
}

void ChessBoard::revive(Piece *piece, int index)
{
    if (index < 0 || index > 32)
    {
        printf("INDICE NON VALIDO");
        return;
    }
    Pieces[index]->isAlive = 1;
}

void ChessBoard::revivePiece(Piece *piece)
{
    int index = indexOfPiece(piece);
    revive(piece, index);
    return;
}

bool ChessBoard::canMove(Piece *piece, Position pos)
{
    // se la posizione non è valida ritorno false
    if (!isPositionValid(pos))
        return false;
    // se è pinnato ritorno false
    if (isPinned(piece))
    {
        cout << "PEZZO PINNATO" << endl;
        return false;
    }
    // se pos sta nelle accessibili ritorno true
    for (const Position p : piece->accessiblePos)
    {
        if (p == pos)
        {
            return true;
        }
    }

    return false;
}
