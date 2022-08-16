
#include "ChessBoard.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

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

template<typename Base, typename T>
inline bool instanceof (const T *ptr)
{
    return dynamic_cast<const Base *>(ptr) != nullptr;
}

ChessBoard::ChessBoard()
{
    /*
    Kpieces.push_back(King("white king", Piece::Color::White, true, Position(4, 0)));
    Qpieces.push_back(Queen("white queen", Piece::Color::White, true, Position(3, 0)));
    Rpieces.push_back(Rook("white rook 1", Piece::Color::White, true, Position(0, 0)));
    Rpieces.push_back(Rook("white rook 2", Piece::Color::White, true, Position(7, 0)));
    Bpieces.push_back(Bishop("white bishop 1", Piece::Color::White, true, Position(2, 0)));
    Bpieces.push_back(Bishop("white bishop 2", Piece::Color::White, true, Position(5, 0)));
    KNpieces.push_back(Knight("white knight 1", Piece::Color::White, true, Position(1, 0)));
    KNpieces.push_back(Knight("white knight 2", Piece::Color::White, true, Position(6, 0)));
    Ppieces.push_back(Pawn("white pawn 1", Piece::Color::White, true, Position(0, 1)));
    Ppieces.push_back(Pawn("white pawn 2", Piece::Color::White, true, Position(1, 1)));
    Ppieces.push_back(Pawn("white pawn 3", Piece::Color::White, true, Position(2, 1)));
    Ppieces.push_back(Pawn("white pawn 4", Piece::Color::White, true, Position(3, 1)));
    Ppieces.push_back(Pawn("white pawn 5", Piece::Color::White, true, Position(4, 1)));
    Ppieces.push_back(Pawn("white pawn 6", Piece::Color::White, true, Position(5, 1)));
    Ppieces.push_back(Pawn("white pawn 7", Piece::Color::White, true, Position(6, 1)));
    Ppieces.push_back(Pawn("white pawn 8", Piece::Color::White, true, Position(7, 1)));

    Kpieces.push_back(King("black king", Piece::Color::Black, true, Position(4, 7)));
    Qpieces.push_back(Queen("black queen", Piece::Color::Black, true, Position(3, 7)));
    Rpieces.push_back(Rook("black rook 1", Piece::Color::Black, true, Position(0, 7)));
    Rpieces.push_back(Rook("black rook 2", Piece::Color::Black, true, Position(7, 7)));
    Bpieces.push_back(Bishop("black bishop 1", Piece::Color::Black, true, Position(2, 7)));
    Bpieces.push_back(Bishop("black bishop 2", Piece::Color::Black, true, Position(5, 7)));
    KNpieces.push_back(Knight("black knight 1", Piece::Color::Black, true, Position(1, 7)));
    KNpieces.push_back(Knight("black knight 2", Piece::Color::Black, true, Position(6, 7)));
    Ppieces.push_back(Pawn("black pawn 1", Piece::Color::Black, true, Position(0, 6)));
    Ppieces.push_back(Pawn("black pawn 2", Piece::Color::Black, true, Position(1, 6)));
    Ppieces.push_back(Pawn("black pawn 3", Piece::Color::Black, true, Position(2, 6)));
    Ppieces.push_back(Pawn("black pawn 4", Piece::Color::Black, true, Position(3, 6)));
    Ppieces.push_back(Pawn("black pawn 5", Piece::Color::Black, true, Position(4, 6)));
    Ppieces.push_back(Pawn("black pawn 6", Piece::Color::Black, true, Position(5, 6)));
    Ppieces.push_back(Pawn("black pawn 7", Piece::Color::Black, true, Position(6, 6)));
    Ppieces.push_back(Pawn("black pawn 8", Piece::Color::Black, true, Position(7, 6)));

    // pezzi di riserva
    ResQpieces.push_back(Queen("white queen 2", Piece::Color::White, true, Position(5, 5)));
    ResQpieces.push_back(Queen("black queen 2", Piece::Color::Black, true, Position(4, 5)));

    ResRpieces.push_back(Rook("white rook 3", Piece::Color::White, true, Position(3, 7)));
    ResRpieces.push_back(Rook("black rook 3", Piece::Color::Black, true, Position(3, 7)));

    ResBpieces.push_back(Bishop("white bishop 3", Piece::Color::White, true, Position(3, 7)));
    ResBpieces.push_back(Bishop("black bishop 3", Piece::Color::Black, true, Position(3, 7)));

    ResKNpieces.push_back(Knight("white knight 3", Piece::Color::White, true, Position(3, 7)));
    ResKNpieces.push_back(Knight("black knight 3", Piece::Color::Black, true, Position(3, 7)));

    for (auto &piece : Kpieces)
    {
        Pieces.push_back(&piece);
    }

    for (auto &piece : Qpieces)
    {
        Pieces.push_back(&piece);
    }

    for (auto &piece : Rpieces)
    {
        Pieces.push_back(&piece);
    }

    for (auto &piece : Bpieces)
    {
        Pieces.push_back(&piece);
    }

    for (auto &piece : KNpieces)
    {
        Pieces.push_back(&piece);
    }

    for (auto &piece : Ppieces)
    {
        Pieces.push_back(&piece);
    }*/

    Configuration defaultConf = {
        {Piece::Type::King, Position(4, 0)},
        {Piece::Type::Queen, Position(3, 0)},
        {Piece::Type::Rook, Position(0, 0)},
        {Piece::Type::Rook, Position(7, 0)},
        {Piece::Type::Bishop, Position(2, 0)},
        {Piece::Type::Bishop, Position(5, 0)},
        {Piece::Type::Knight, Position(1, 0)},
        {Piece::Type::Knight, Position(6, 0)},
        {Piece::Type::Pawn, Position(0, 1)},
        {Piece::Type::Pawn, Position(1, 1)},
        {Piece::Type::Pawn, Position(2, 1)},
        {Piece::Type::Pawn, Position(3, 1)},
        {Piece::Type::Pawn, Position(4, 1)},
        {Piece::Type::Pawn, Position(5, 1)},
        {Piece::Type::Pawn, Position(6, 1)},
        {Piece::Type::Pawn, Position(7, 1)}
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
    for(Piece *piece : pieceVector)
    {
        delete piece;
    }
    pieceVector.clear();
}

Piece *createPiece(Piece::Type type, Piece::Color color, const Position& pos)
{
    switch (type)
    {
    case Piece::Type::Bishop:
        return new Bishop("", color, true, pos);
    case Piece::Type::King:
        return new King("", color, true, pos);
    case Piece::Type::Knight:
        return new Knight("", color, true, pos);
    case Piece::Type::Pawn:
        return new Pawn("", color, true, pos);
    case Piece::Type::Queen:
        return new Queen("", color, true, pos);
    case Piece::Type::Rook:
        return new Rook("", color, true, pos);
    default:
        break;
    }

    return nullptr;
}

void ChessBoard::initConfiguration(const Configuration &conf)
{
    //Clear previous configuration
    clear();

    int counters[int(Piece::Type::NTypes)] = {0};

    for(auto pieceDef : conf)
    {
        //Mirror position for black piece
        Position blackPos = pieceDef.second;
        blackPos.setY(7 - blackPos.getY());

        Piece *whitePiece = createPiece(pieceDef.first, Piece::Color::White, pieceDef.second);
        Piece *blackPiece = createPiece(pieceDef.first, Piece::Color::Black, blackPos);;

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

void ChessBoard::printChessBoard()
{
    Piece *p;
    cout << "    ";
    for (int i = 0; i < 8; i++)
    {
        cout << i << "  ";
    }
    for (int i = 0; i < 8; i++)
    {
        cout << endl;
        cout << i << "   ";
        for (int j = 0; j < 8; j++)
        {
            p = searchPiece(Position(i, j));
            if (p != NULL)
            {
                if (p->isAlive)
                {
                    if (p->getColor() == Piece::Color::White)
                    {
                        if (instanceof <King>(p))
                        {
                            cout << "wK ";
                        }
                        else if (instanceof <Queen>(p))
                        {
                            cout << "wq ";
                        }
                        else if (instanceof <Rook>(p))
                        {
                            cout << "wr ";
                        }
                        else if (instanceof <Bishop>(p))
                        {
                            cout << "wb ";
                        }
                        else if (instanceof <Knight>(p))
                        {
                            cout << "wk ";
                        }
                        else if (instanceof <Pawn>(p))
                        {
                            cout << "wp ";
                        }
                    }
                    else
                    {
                        if (instanceof <King>(p))
                        {
                            cout << "bK ";
                        }
                        else if (instanceof <Queen>(p))
                        {
                            cout << "bq ";
                        }
                        else if (instanceof <Rook>(p))
                        {
                            cout << "br ";
                        }
                        else if (instanceof <Bishop>(p))
                        {
                            cout << "bb ";
                        }
                        else if (instanceof <Knight>(p))
                        {
                            cout << "bk ";
                        }
                        else if (instanceof <Pawn>(p))
                        {
                            cout << "bp ";
                        }
                    }
                }
            }
            else
            {
                cout << "   ";
            }
        }
    }
    cout << endl;
}

bool ChessBoard::isOccpied(Position p)
{
    for (auto &piece : pieceVector)
    {
        if (piece->isAlive)
        {
            if (piece->m_pos == p)
            {
                return true;
            }
        }
    }
    return false;
}

Piece *ChessBoard::searchPiece(Position p)
{
    for (auto &piece : pieceVector)
    {
        if (piece->isAlive)
        {
            if (piece->m_pos == p)
            {
                return piece;
            }
        }
    }

    return NULL;
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
    if (instanceof <King>(piece))
    {

        // check posizione alto a sx
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1))
            && !isOccpied(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() + 1));
        }

        // check posizione in alto
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1))
            && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1)))
        {
            (piece->accessiblePos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1)))
        {
            (piece->controlledPos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + 1));
        }

        // check posizione alto a dx
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1))
            && !isOccpied(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() + 1));
        }

        // check posizione a dx
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY()))
            && !isOccpied(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY())))
        {
            (piece->accessiblePos).push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY()));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY())))
        {
            (piece->controlledPos).push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY()));
        }
        // check posizione in basso a dx
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1))
            && !isOccpied(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() + 1, (piece->m_pos).getY() - 1));
        }
        // check posizione in basso
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1))
            && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1)))
        {
            (piece->accessiblePos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1)))
        {
            (piece->controlledPos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - 1));
        }
        // check posizione in basso a sx
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1))
            && !isOccpied(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1)))
        {
            (piece->accessiblePos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1)))
        {
            (piece->controlledPos)
                    .push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY() - 1));
        }
        // check posizione a sx
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY()))
            && !isOccpied(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY())))
        {
            (piece->accessiblePos).push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY()));
        }
        if (isPositionValid(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY())))
        {
            (piece->controlledPos).push_back(Position((piece->m_pos).getX() - 1, (piece->m_pos).getY()));
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
            (piece->accessiblePos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i)))
        {
            (piece->controlledPos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i));
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
            (piece->accessiblePos).push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY())))
        {
            (piece->controlledPos).push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()));
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
            (piece->accessiblePos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i)))
        {
            (piece->controlledPos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i));
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
            (piece->accessiblePos).push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY())))
        {
            (piece->controlledPos).push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()));
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
            (piece->accessiblePos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i)))
        {
            (piece->controlledPos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() + i));
        }
        // check posizioni in basso
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i))
               && !isOccpied(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i)))
        {
            (piece->accessiblePos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i)))
        {
            (piece->controlledPos).push_back(Position((piece->m_pos).getX(), (piece->m_pos).getY() - i));
        }
        // check posizioni a sx
        i = 1;
        while (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()))
               && !isOccpied(Position((piece->m_pos).getX() - i, (piece->m_pos).getY())))
        {
            (piece->accessiblePos).push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() - i, (piece->m_pos).getY())))
        {
            (piece->controlledPos).push_back(Position((piece->m_pos).getX() - i, (piece->m_pos).getY()));
        }
        // check posizioni a dx
        i = 1;

        while (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()))
               && !isOccpied(Position((piece->m_pos).getX() + i, (piece->m_pos).getY())))
        {
            (piece->accessiblePos).push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->m_pos).getX() + i, (piece->m_pos).getY())))
        {
            (piece->controlledPos).push_back(Position((piece->m_pos).getX() + i, (piece->m_pos).getY()));
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
    else if (instanceof <Knight>(piece))
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
    else if (instanceof <Pawn>(piece))
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

int ChessBoard::indexOfPiece(Piece *piece)
{
    for (int i = 0; i < pieceVector.size(); i++)
    {
        if (pieceVector[i] == piece)
        {
            return i;
        }
    }

    return -1;
}

void ChessBoard::kill(Piece *piece, int index)
{
    if (index < 0 || index > 32)
    {
        printf("INDICE NON VALIDO");
        return;
    }
    pieceVector[index]->isAlive = 0;
}

void ChessBoard::killPiece(Piece *piece)
{
    int index = indexOfPiece(piece);
    kill(piece, index);
    return;
}

void ChessBoard::killVerginity(Piece *piece, int index)
{
    if (index < 0 || index > 32)
    {
        printf("INDICE NON VALIDO");
        return;
    }
    pieceVector[index]->isVirgin = 0;
}

void ChessBoard::killPieceVerginity(Piece *piece)
{
    int index = indexOfPiece(piece);
    killVerginity(piece, index);
    return;
}

bool ChessBoard::isKingInCheck(Piece::Color color)
{
    //FIXME: find piece by type and color instead of index
    return color == Piece::Color::Black ? ((King *)pieceVector[0])->isInCheck : ((King *)pieceVector[1])->isInCheck;
}

void ChessBoard::move(Piece *piece, Position pos)
{
    // controllo se posso puo' mangiare, se puo' ritorno la mossa è finita
    if (canEat(piece, pos))
    {
        eat(piece, pos);
        return;
    }
    // controllo se il pezzo puo' muovere
    if (canMove(piece, pos))
    {
        piece->move(pos);
        // uccido la sua verginita (setto a 0 il suo isVirgin)
        if (piece->isVirgin)
        {
            killPieceVerginity(piece);
        }
        // controllo se dopo aver mosso posso Queenare, se puo' Queenno
        if (canQueen(piece))
        {
            queenning(piece);
        }
        // genero le posizioni per tutti i pezzi (posizioni accessibili e controllate cambiano per
        // ogni pezzo)
        generateAllPos();
        // setto se il re opposto al pezzo mosso è in Scacco
        setKingCheck(Piece::getOppositColor(piece->getColor()));
        // setto se il re che ha mosso è in Scacco (nel caso in cui va a mangiare (liberandosi dallo
        // scacco), il suo isInCheck da 1 va a 0)
        setKingCheck(piece->getColor());
        // se il re del colore opposto è in scacco faccio una stampa
        if (isKingInCheck(Piece::getOppositColor(piece->getColor())))
        {
            cout << "Re colore " << Piece::getColorName(Piece::getOppositColor(piece->getColor())) << "in Scacco" << endl;
        }
        return;
    }
}
void ChessBoard::queenning(Piece *pawn)
{
    if (! instanceof <Pawn>(pawn))
        return;

    if (pawn != NULL)
    {
        if (pawn->getColor() == Piece::Color::White)
        {
            if (pawn->m_pos.getY() == 7)
            {
                int x = pawn->m_pos.getX();
                int choice = -1;
                Position pos = Position(x, 7);

                while (choice < 0 || choice > 4)
                {

                    cout << "0 per Queen" << endl;
                    cout << "1 per Rook" << endl;
                    cout << "2 per Bishop" << endl;
                    cout << "3 per Knight" << endl;
                    cin >> choice;

                    switch (choice)
                    {
                    case 0:
                        ResQpieces[0].setPosition(pos);
                        pieceVector[indexOfPiece(pawn)] = &ResQpieces[0];
                        break;

                    case 1:
                        ResRpieces[0].setPosition(pos);
                        pieceVector[indexOfPiece(pawn)] = &ResRpieces[0];
                        break;

                    case 2:
                        ResBpieces[0].setPosition(pos);
                        pieceVector[indexOfPiece(pawn)] = &ResBpieces[0];
                        break;

                    case 3:
                        ResKNpieces[0].setPosition(pos);
                        pieceVector[indexOfPiece(pawn)] = &ResKNpieces[0];
                        break;

                    default:
                        cout << "SCELTA INVALIDA" << endl;
                        break;
                    }
                }
            }
        }
        else
        {
            if (pawn->m_pos.getY() == 0)
            {
                int x = pawn->m_pos.getX();
                int choice = -1;
                Position pos = Position(x, 0);

                while (choice < 0 || choice > 4)
                {

                    cout << "0 per Queen" << endl;
                    cout << "1 per Rook" << endl;
                    cout << "2 per Bishop" << endl;
                    cout << "3 per Knight" << endl;
                    cin >> choice;

                    switch (choice)
                    {
                    case 0:
                        ResQpieces[1].m_pos = pos;
                        pieceVector[indexOfPiece(pawn)] = &ResQpieces[1];
                        break;

                    case 1:
                        ResRpieces[1].m_pos = pos;
                        pieceVector[indexOfPiece(pawn)] = &ResRpieces[1];
                        break;

                    case 2:
                        ResBpieces[1].m_pos = pos;
                        pieceVector[indexOfPiece(pawn)] = &ResBpieces[1];
                        break;

                    case 3:
                        ResKNpieces[1].m_pos = pos;
                        pieceVector[indexOfPiece(pawn)] = &ResKNpieces[1];
                        break;

                    default:
                        cout << "SCELTA INVALIDA" << endl;
                        break;
                    }
                }
            }
        }
    }
}

bool ChessBoard::canQueen(Piece *p)
{
    if (! instanceof <Pawn>(p))
    {
        return false;
    }
    else if (p->getColor() == Piece::Color::White)
    {
        return p->m_pos.getY() == 7;
    }
    else
    {
        return p->m_pos.getY() == 0;
    }
}

Piece *ChessBoard::searchPieceByName(string name)
{
    for (auto &piece : pieceVector)
    {
        if (instanceof <King>(piece))
        {
            if (((King *)piece)->name == name)
            {
                return piece;
            }
        }
        else if (instanceof <Queen>(piece))
        {
            if (((Queen *)piece)->name == name)
            {
                return piece;
            }
        }
        else if (instanceof <Rook>(piece))
        {
            if (((Rook *)piece)->name == name)
            {
                return piece;
            }
        }
        else if (instanceof <Bishop>(piece))
        {
            if (((Bishop *)piece)->name == name)
            {
                return piece;
            }
        }
        else if (instanceof <Knight>(piece))
        {
            if (((Knight *)piece)->name == name)
            {
                return piece;
            }
        }
        else if (instanceof <Pawn>(piece))
        {
            if (((Pawn *)piece)->name == name)
            {
                return piece;
            }
        }
    }

    return NULL;
}
void ChessBoard::setKingCheck(Piece::Color color)
{
    cout << "Try Check" << endl;
    string name = "white king";
    if (color == Piece::Color::Black)
    {
        name = "black king";
    }

    Piece *WK = searchPieceByName(name);

    for (auto &piece : pieceVector)
    {
        if (piece->getColor() != color)
        {
            for (const Position &p : piece->controlledPos)
            {
                if (p == WK->m_pos)
                {
                    ((King *)WK)->isInCheck = true;
                    return;
                }
            }
        }
    }

    ((King *)WK)->isInCheck = false;
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
    Piece *temp = searchPiece(pos);
    if (! instanceof <King>(piece))
    {
        return temp != NULL && piece->isOppositeColor(temp);
    }
    else
    {
        return !willKingBeInCheck(piece->getColor(), pos);
    }
}

void ChessBoard::eat(Piece *piece, Position pos)
{
    Piece *temp = searchPiece(pos);

    if (canEat(piece, pos))
    {
        killPiece(temp);

        piece->move(pos);
        if (piece->isVirgin)
        {
            killPieceVerginity(piece);
        }

        if (canQueen(piece))
        {
            queenning(piece);
        }

        generateAllPos();
        // controllo re colore opposto se è in check
        setKingCheck(Piece::getOppositColor(piece->getColor()));
        setKingCheck(piece->getColor());
        if (isKingInCheck(Piece::getOppositColor(piece->getColor())))
        {
            cout << "Re colore " << Piece::getColorName(Piece::getOppositColor(piece->getColor())) << "in Scacco" << endl;
        }
    }
}

void ChessBoard::mergePos(Piece *piece)
{
    for (int i = 0; i < piece->controlledPos.size(); i++)
    {
        // se la nella posizione controllata posso mangiare, allora la faccio diventare accessibile
        if (canEat(piece, piece->controlledPos[i]))
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
