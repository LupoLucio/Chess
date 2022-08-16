
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

template <typename Base, typename T>
inline bool instanceof (const T* ptr)
{
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

ChessBoard::ChessBoard()
{

    Kpieces.push_back(King("white king", 1, 1, Position(4, 0)));
    Qpieces.push_back(Queen("white queen", 1, 1, Position(3, 0)));
    Rpieces.push_back(Rook("white rook 1", 1, 1, Position(0, 0)));
    Rpieces.push_back(Rook("white rook 2", 1, 1, Position(7, 0)));
    Bpieces.push_back(Bishop("white bishop 1", 1, 1, Position(2, 0)));
    Bpieces.push_back(Bishop("white bishop 2", 1, 1, Position(5, 0)));
    KNpieces.push_back(Knight("white knight 1", 1, 1, Position(1, 0)));
    KNpieces.push_back(Knight("white knight 2", 1, 1, Position(6, 0)));
    Ppieces.push_back(Pawn("white pawn 1", 1, 1, Position(0, 1)));
    Ppieces.push_back(Pawn("white pawn 2", 1, 1, Position(1, 1)));
    Ppieces.push_back(Pawn("white pawn 3", 1, 1, Position(2, 1)));
    Ppieces.push_back(Pawn("white pawn 4", 1, 1, Position(3, 1)));
    Ppieces.push_back(Pawn("white pawn 5", 1, 1, Position(4, 1)));
    Ppieces.push_back(Pawn("white pawn 6", 1, 1, Position(5, 1)));
    Ppieces.push_back(Pawn("white pawn 7", 1, 1, Position(6, 1)));
    Ppieces.push_back(Pawn("white pawn 8", 1, 1, Position(7, 1)));

    Kpieces.push_back(King("black king", 0, 1, Position(4, 7)));
    Qpieces.push_back(Queen("black queen", 0, 1, Position(3, 7)));
    Rpieces.push_back(Rook("black rook 1", 0, 1, Position(0, 7)));
    Rpieces.push_back(Rook("black rook 2", 0, 1, Position(7, 7)));
    Bpieces.push_back(Bishop("black bishop 1", 0, 1, Position(2, 7)));
    Bpieces.push_back(Bishop("black bishop 2", 0, 1, Position(5, 7)));
    KNpieces.push_back(Knight("black knight 1", 0, 1, Position(1, 7)));
    KNpieces.push_back(Knight("black knight 2", 0, 1, Position(6, 7)));
    Ppieces.push_back(Pawn("black pawn 1", 0, 1, Position(0, 6)));
    Ppieces.push_back(Pawn("black pawn 2", 0, 1, Position(1, 6)));
    Ppieces.push_back(Pawn("black pawn 3", 0, 1, Position(2, 6)));
    Ppieces.push_back(Pawn("black pawn 4", 0, 1, Position(3, 6)));
    Ppieces.push_back(Pawn("black pawn 5", 0, 1, Position(4, 6)));
    Ppieces.push_back(Pawn("black pawn 6", 0, 1, Position(5, 6)));
    Ppieces.push_back(Pawn("black pawn 7", 0, 1, Position(6, 6)));
    Ppieces.push_back(Pawn("black pawn 8", 0, 1, Position(7, 6)));

    // pezzi di riserva
    ResQpieces.push_back(Queen("white queen 2", 1, 1, Position(5, 5)));
    ResQpieces.push_back(Queen("black queen 2", 0, 1, Position(4, 5)));

    ResRpieces.push_back(Rook("white rook 3", 1, 1, Position(3, 7)));
    ResRpieces.push_back(Rook("black rook 3", 0, 1, Position(3, 7)));

    ResBpieces.push_back(Bishop("white bishop 3", 1, 1, Position(3, 7)));
    ResBpieces.push_back(Bishop("black bishop 3", 0, 1, Position(3, 7)));

    ResKNpieces.push_back(Knight("white knight 3", 1, 1, Position(3, 7)));
    ResKNpieces.push_back(Knight("black knight 3", 0, 1, Position(3, 7)));

    for (auto& piece : Kpieces) {
        Pieces.push_back(&piece);
    }

    for (auto& piece : Qpieces) {
        Pieces.push_back(&piece);
    }

    for (auto& piece : Rpieces) {
        Pieces.push_back(&piece);
    }

    for (auto& piece : Bpieces) {
        Pieces.push_back(&piece);
    }

    for (auto& piece : KNpieces) {
        Pieces.push_back(&piece);
    }

    for (auto& piece : Ppieces) {
        Pieces.push_back(&piece);
    }

    generateAllPos();
}
void ChessBoard::printPieces()
{
    cout << "Pieces are :  " << endl;

    for (auto& piece : Pieces) {
        piece->printPiece();
    }

    cout << "End Pieces" << endl;
}

void ChessBoard::printChessBoard()
{
    Piece* p;
    cout << "    ";
    for (int i = 0; i < 8; i++) {
        cout << i << "  ";
    }
    for (int i = 0; i < 8; i++) {
        cout << endl;
        cout << i << "   ";
        for (int j = 0; j < 8; j++) {
            p = searchPiece(Position(i, j));
            if (p != NULL) {
                if (p->isLive) {
                    if (p->isWhite) {
                        if (instanceof <King>(p)) {
                            cout << "wK ";

                        } else if (instanceof <Queen>(p)) {
                            cout << "wq ";

                        } else if (instanceof <Rook>(p)) {
                            cout << "wr ";

                        } else if (instanceof <Bishop>(p)) {
                            cout << "wb ";

                        } else if (instanceof <Knight>(p)) {
                            cout << "wk ";

                        } else if (instanceof <Pawn>(p)) {
                            cout << "wp ";
                        }
                    } else {
                        if (instanceof <King>(p)) {
                            cout << "bK ";

                        } else if (instanceof <Queen>(p)) {
                            cout << "bq ";

                        } else if (instanceof <Rook>(p)) {
                            cout << "br ";

                        } else if (instanceof <Bishop>(p)) {
                            cout << "bb ";

                        } else if (instanceof <Knight>(p)) {
                            cout << "bk ";

                        } else if (instanceof <Pawn>(p)) {
                            cout << "bp ";
                        }
                    }
                }
            } else {
                cout << "   ";
            }
        }
    }
    cout << endl;
}

bool ChessBoard::isOccpied(Position p)
{

    for (auto& piece : Pieces) {
        if (piece->isLive) {
            if (piece->p == p) {
                return true;
            }
        }
    }
    return false;
}

Piece* ChessBoard::searchPiece(Position p)
{

    for (auto& piece : Pieces) {
        if (piece->isLive) {
            if (piece->p == p) {
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

void ChessBoard::generatePos(Piece* piece)
{
    // ogni volta che le genero le pulisco prima
    clearPos(piece);
    // check se è King
    if (instanceof <King>(piece)) {

        // check posizione alto a sx
        if (isPositionValid(Position((piece->p).getX() - 1, (piece->p).getY() + 1)) && !isOccpied(Position((piece->p).getX() - 1, (piece->p).getY() + 1))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() - 1, (piece->p).getY() + 1));
        }
        if (isPositionValid(Position((piece->p).getX() - 1, (piece->p).getY() + 1))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() - 1, (piece->p).getY() + 1));
        }

        // check posizione in alto
        if (isPositionValid(Position((piece->p).getX(), (piece->p).getY() + 1)) && !isOccpied(Position((piece->p).getX(), (piece->p).getY() + 1))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX(), (piece->p).getY() + 1));
        }
        if (isPositionValid(Position((piece->p).getX(), (piece->p).getY() + 1))) {
            (piece->controlledPos).push_back(Position((piece->p).getX(), (piece->p).getY() + 1));
        }

        // check posizione alto a dx
        if (isPositionValid(Position((piece->p).getX() + 1, (piece->p).getY() + 1)) && !isOccpied(Position((piece->p).getX() + 1, (piece->p).getY() + 1))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() + 1, (piece->p).getY() + 1));
        }
        if (isPositionValid(Position((piece->p).getX() + 1, (piece->p).getY() + 1))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() + 1, (piece->p).getY() + 1));
        }

        // check posizione a dx
        if (isPositionValid(Position((piece->p).getX() + 1, (piece->p).getY())) && !isOccpied(Position((piece->p).getX() + 1, (piece->p).getY()))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() + 1, (piece->p).getY()));
        }
        if (isPositionValid(Position((piece->p).getX() + 1, (piece->p).getY()))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() + 1, (piece->p).getY()));
        }
        // check posizione in basso a dx
        if (isPositionValid(Position((piece->p).getX() + 1, (piece->p).getY() - 1)) && !isOccpied(Position((piece->p).getX() + 1, (piece->p).getY() - 1))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() + 1, (piece->p).getY() - 1));
        }
        if (isPositionValid(Position((piece->p).getX() + 1, (piece->p).getY() - 1))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() + 1, (piece->p).getY() - 1));
        }
        // check posizione in basso
        if (isPositionValid(Position((piece->p).getX(), (piece->p).getY() - 1)) && !isOccpied(Position((piece->p).getX(), (piece->p).getY() - 1))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX(), (piece->p).getY() - 1));
        }
        if (isPositionValid(Position((piece->p).getX(), (piece->p).getY() - 1))) {
            (piece->controlledPos).push_back(Position((piece->p).getX(), (piece->p).getY() - 1));
        }
        // check posizione in basso a sx
        if (isPositionValid(Position((piece->p).getX() - 1, (piece->p).getY() - 1)) && !isOccpied(Position((piece->p).getX() - 1, (piece->p).getY() - 1))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() - 1, (piece->p).getY() - 1));
        }
        if (isPositionValid(Position((piece->p).getX() - 1, (piece->p).getY() - 1))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() - 1, (piece->p).getY() - 1));
        }
        // check posizione a sx
        if (isPositionValid(Position((piece->p).getX() - 1, (piece->p).getY())) && !isOccpied(Position((piece->p).getX() - 1, (piece->p).getY()))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() - 1, (piece->p).getY()));
        }
        if (isPositionValid(Position((piece->p).getX() - 1, (piece->p).getY()))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() - 1, (piece->p).getY()));
        }

    }
    // check se è Queen
    else if (instanceof <Queen>(piece)) {

        // check posizioni in alto sx
        int i = 1;

        while (isPositionValid(Position((piece->p).getX() - i, (piece->p).getY() + i)) && !isOccpied(Position((piece->p).getX() - i, (piece->p).getY() + i))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() - i, (piece->p).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX() - i, (piece->p).getY() + i))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() - i, (piece->p).getY() + i));
        }
        // check posizione in alto
        i = 1;

        while (isPositionValid(Position((piece->p).getX(), (piece->p).getY() + i)) && !isOccpied(Position((piece->p).getX(), (piece->p).getY() + i))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX(), (piece->p).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX(), (piece->p).getY() + i))) {
            (piece->controlledPos).push_back(Position((piece->p).getX(), (piece->p).getY() + i));
        }
        // check posizioni in alto a dx
        i = 1;

        while (isPositionValid(Position((piece->p).getX() + i, (piece->p).getY() + i)) && !isOccpied(Position((piece->p).getX() + i, (piece->p).getY() + i))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() + i, (piece->p).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX() + i, (piece->p).getY() + i))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() + i, (piece->p).getY() + i));
        }
        // check posizioni a dx
        i = 1;

        while (isPositionValid(Position((piece->p).getX() + i, (piece->p).getY())) && !isOccpied(Position((piece->p).getX() + i, (piece->p).getY()))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() + i, (piece->p).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX() + i, (piece->p).getY()))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() + i, (piece->p).getY()));
        }
        // check posizioni in basso a dx
        i = 1;
        while (isPositionValid(Position((piece->p).getX() + i, (piece->p).getY() - i)) && !isOccpied(Position((piece->p).getX() + i, (piece->p).getY() - i))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() + i, (piece->p).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX() + i, (piece->p).getY() - i))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() + i, (piece->p).getY() - i));
        }
        // check posizioni in basso
        i = 1;
        while (isPositionValid(Position((piece->p).getX(), (piece->p).getY() - i)) && !isOccpied(Position((piece->p).getX(), (piece->p).getY() - i))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX(), (piece->p).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX(), (piece->p).getY() - i))) {
            (piece->controlledPos).push_back(Position((piece->p).getX(), (piece->p).getY() - i));
        }
        // check posizioni in basso a sx
        i = 1;
        while (isPositionValid(Position((piece->p).getX() - i, (piece->p).getY() - i)) && !isOccpied(Position((piece->p).getX() - i, (piece->p).getY() - i))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() - i, (piece->p).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX() - i, (piece->p).getY() - i))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() - i, (piece->p).getY() - i));
        }
        // check posizioni a sx
        i = 1;
        while (isPositionValid(Position((piece->p).getX() - i, (piece->p).getY())) && !isOccpied(Position((piece->p).getX() - i, (piece->p).getY()))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() - i, (piece->p).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX() - i, (piece->p).getY()))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() - i, (piece->p).getY()));
        }

    }
    // check se è Rook
    else if (instanceof <Rook>(piece)) {
        // check posizione in alto
        int i = 1;

        while (isPositionValid(Position((piece->p).getX(), (piece->p).getY() + i)) && !isOccpied(Position((piece->p).getX(), (piece->p).getY() + i))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX(), (piece->p).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX(), (piece->p).getY() + i))) {
            (piece->controlledPos).push_back(Position((piece->p).getX(), (piece->p).getY() + i));
        }
        // check posizioni in basso
        i = 1;
        while (isPositionValid(Position((piece->p).getX(), (piece->p).getY() - i)) && !isOccpied(Position((piece->p).getX(), (piece->p).getY() - i))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX(), (piece->p).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX(), (piece->p).getY() - i))) {
            (piece->controlledPos).push_back(Position((piece->p).getX(), (piece->p).getY() - i));
        }
        // check posizioni a sx
        i = 1;
        while (isPositionValid(Position((piece->p).getX() - i, (piece->p).getY())) && !isOccpied(Position((piece->p).getX() - i, (piece->p).getY()))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() - i, (piece->p).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX() - i, (piece->p).getY()))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() - i, (piece->p).getY()));
        }
        // check posizioni a dx
        i = 1;

        while (isPositionValid(Position((piece->p).getX() + i, (piece->p).getY())) && !isOccpied(Position((piece->p).getX() + i, (piece->p).getY()))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() + i, (piece->p).getY()));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX() + i, (piece->p).getY()))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() + i, (piece->p).getY()));
        }

    }
    // check se è Bhishop
    else if (instanceof <Bishop>(piece)) {
        // check posizioni in alto sx
        int i = 1;

        while (isPositionValid(Position((piece->p).getX() - i, (piece->p).getY() + i)) && !isOccpied(Position((piece->p).getX() - i, (piece->p).getY() + i))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() - i, (piece->p).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX() - i, (piece->p).getY() + i))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() - i, (piece->p).getY() + i));
        }
        // check posizioni in alto a dx
        i = 1;

        while (isPositionValid(Position((piece->p).getX() + i, (piece->p).getY() + i)) && !isOccpied(Position((piece->p).getX() + i, (piece->p).getY() + i))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() + i, (piece->p).getY() + i));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX() + i, (piece->p).getY() + i))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() + i, (piece->p).getY() + i));
        }
        // check posizioni in basso a dx
        i = 1;
        while (isPositionValid(Position((piece->p).getX() + i, (piece->p).getY() - i)) && !isOccpied(Position((piece->p).getX() + i, (piece->p).getY() - i))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() + i, (piece->p).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX() + i, (piece->p).getY() - i))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() + i, (piece->p).getY() - i));
        }
        // check posizioni in basso a sx
        i = 1;
        while (isPositionValid(Position((piece->p).getX() - i, (piece->p).getY() - i)) && !isOccpied(Position((piece->p).getX() - i, (piece->p).getY() - i))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() - i, (piece->p).getY() - i));
            i++;
        }
        if (isPositionValid(Position((piece->p).getX() - i, (piece->p).getY() - i))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() - i, (piece->p).getY() - i));
        }

    }
    // check se è knight
    else if (instanceof <Knight>(piece)) {

        // check posizione medio alto sx
        if (isPositionValid(Position((piece->p).getX() - 2, (piece->p).getY() + 1)) && !isOccpied(Position((piece->p).getX() - 2, (piece->p).getY() + 1))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() - 2, (piece->p).getY() + 1));
        }
        if (isPositionValid(Position((piece->p).getX() - 2, (piece->p).getY() + 1))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() - 2, (piece->p).getY() + 1));
        }
        // check posizione alto sx
        if (isPositionValid(Position((piece->p).getX() - 1, (piece->p).getY() + 2)) && !isOccpied(Position((piece->p).getX() - 1, (piece->p).getY() + 2))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() - 1, (piece->p).getY() + 2));
        }
        if (isPositionValid(Position((piece->p).getX() - 1, (piece->p).getY() + 2))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() - 1, (piece->p).getY() + 2));
        }
        // check posizione alto dx
        if (isPositionValid(Position((piece->p).getX() + 1, (piece->p).getY() + 2)) && !isOccpied(Position((piece->p).getX() + 1, (piece->p).getY() + 2))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() + 1, (piece->p).getY() + 2));
        }
        if (isPositionValid(Position((piece->p).getX() + 1, (piece->p).getY() + 2))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() + 1, (piece->p).getY() + 2));
        }
        // check posizione medio alto dx
        if (isPositionValid(Position((piece->p).getX() + 2, (piece->p).getY() + 1)) && !isOccpied(Position((piece->p).getX() + 2, (piece->p).getY() + 1))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() + 2, (piece->p).getY() + 1));
        }
        if (isPositionValid(Position((piece->p).getX() + 2, (piece->p).getY() + 1))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() + 2, (piece->p).getY() + 1));
        }
        // check posizione medio basso dx
        if (isPositionValid(Position((piece->p).getX() + 2, (piece->p).getY() - 1)) && !isOccpied(Position((piece->p).getX() + 2, (piece->p).getY() - 1))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() + 2, (piece->p).getY() - 1));
        }
        if (isPositionValid(Position((piece->p).getX() + 2, (piece->p).getY() - 1))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() + 2, (piece->p).getY() - 1));
        }
        // check posizione basso dx
        if (isPositionValid(Position((piece->p).getX() + 1, (piece->p).getY() - 2)) && !isOccpied(Position((piece->p).getX() + 1, (piece->p).getY() - 2))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() + 1, (piece->p).getY() - 2));
        }
        if (isPositionValid(Position((piece->p).getX() + 1, (piece->p).getY() - 2))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() + 1, (piece->p).getY() - 2));
        }
        // check posizione basso sx
        if (isPositionValid(Position((piece->p).getX() - 1, (piece->p).getY() - 2)) && !isOccpied(Position((piece->p).getX() - 1, (piece->p).getY() - 2))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() - 1, (piece->p).getY() - 2));
        }
        if (isPositionValid(Position((piece->p).getX() - 1, (piece->p).getY() - 2))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() - 1, (piece->p).getY() - 2));
        }
        // check posizione medio basso sx
        if (isPositionValid(Position((piece->p).getX() - 2, (piece->p).getY() - 1)) && !isOccpied(Position((piece->p).getX() - 2, (piece->p).getY() - 1))) {
            (piece->accessiblePos).push_back(Position((piece->p).getX() - 2, (piece->p).getY() - 1));
        }
        if (isPositionValid(Position((piece->p).getX() - 2, (piece->p).getY() - 1))) {
            (piece->controlledPos).push_back(Position((piece->p).getX() - 2, (piece->p).getY() - 1));
        }

    }
    // check se è Pawn
    else if (instanceof <Pawn>(piece)) {
        //check if white
        if (piece->isWhite) {

            // check posizione alto a sx
            if (isPositionValid(Position((piece->p).getX() - 1, (piece->p).getY() + 1))) {
                (piece->controlledPos).push_back(Position((piece->p).getX() - 1, (piece->p).getY() + 1));
            }

            // check posizione alto a dx
            if (isPositionValid(Position((piece->p).getX() + 1, (piece->p).getY() + 1))) {
                (piece->controlledPos).push_back(Position((piece->p).getX() + 1, (piece->p).getY() + 1));
            }

            // check posizione alto unica per le accessibili
            if (isPositionValid(Position((piece->p).getX(), (piece->p).getY() + 1)) && !isOccpied(Position((piece->p).getX(), (piece->p).getY() + 1))) {
                (piece->accessiblePos).push_back(Position((piece->p).getX(), (piece->p).getY() + 1));
            }
            // check se è vergine
            if (piece->isVirgin) {
                // check posizione alto di 2
                if (isPositionValid(Position((piece->p).getX(), (piece->p).getY() + 2))) {
                    (piece->accessiblePos).push_back(Position((piece->p).getX(), (piece->p).getY() + 2));
                }
            }

        } else {
            // check posizione basso a sx
            if (isPositionValid(Position((piece->p).getX() - 1, (piece->p).getY() - 1))) {
                (piece->controlledPos).push_back(Position((piece->p).getX() - 1, (piece->p).getY() - 1));
            }
            // check posizione basso a dx
            if (isPositionValid(Position((piece->p).getX() + 1, (piece->p).getY() - 1))) {
                (piece->controlledPos).push_back(Position((piece->p).getX() + 1, (piece->p).getY() - 1));
            }
            // check posizione basso unica per le accessibili
            if (isPositionValid(Position((piece->p).getX(), (piece->p).getY() - 1)) && !isOccpied(Position((piece->p).getX(), (piece->p).getY() - 1))) {
                (piece->accessiblePos).push_back(Position((piece->p).getX(), (piece->p).getY() - 1));
            }
            // check se è vergine
            if (piece->isVirgin) {
                // check posizione basso di 2
                if (isPositionValid(Position((piece->p).getX(), (piece->p).getY() - 2))) {
                    (piece->accessiblePos).push_back(Position((piece->p).getX(), (piece->p).getY() - 2));
                }
            }
        }
    }

    mergePos(piece);
}

void ChessBoard::clearPos(Piece* piece)
{

    piece->accessiblePos.clear();
    piece->controlledPos.clear();
}
int ChessBoard::indexOfPiece(Piece* piece)
{

    for (int i = 0; i < Pieces.size(); i++) {
        if (Pieces[i] == piece) {
            return i;
        }
    }

    return -1;
}
void ChessBoard::kill(Piece* piece, int index)
{

    if (index < 0 || index > 32) {
        printf("INDICE NON VALIDO");
        return;
    }
    Pieces[index]->isLive = 0;
}
void ChessBoard::killPiece(Piece* piece)
{
    int index = indexOfPiece(piece);
    kill(piece, index);
    return;
}
void ChessBoard::killVerginity(Piece* piece, int index)
{

    if (index < 0 || index > 32) {
        printf("INDICE NON VALIDO");
        return;
    }
    Pieces[index]->isVirgin = 0;
}
void ChessBoard::killPieceVerginity(Piece* piece)
{
    int index = indexOfPiece(piece);
    killVerginity(piece, index);
    return;
}
bool ChessBoard::isKingInCheck(int color)
{

    return color ? ((King*)Pieces[0])->isInCheck : ((King*)Pieces[1])->isInCheck;
}
void ChessBoard::move(Piece* piece, Position pos)
{

    // controllo se posso puo' mangiare, se puo' ritorno la mossa è finita
    if (canEat(piece, pos)) {
        eat(piece, pos);
        return;
    }
    // controllo se il pezzo puo' muovere
    if (canMove(piece, pos)) {
        piece->move(pos);
        // uccido la sua verginita (setto a 0 il suo isVirgin)
        if (piece->isVirgin) {
            killPieceVerginity(piece);
        }
        // controllo se dopo aver mosso posso Queenare, se puo' Queenno
        if (canQueen(piece)) {
            queenning(piece);
        }
        // genero le posizioni per tutti i pezzi (posizioni accessibili e controllate cambiano per ogni pezzo)
        generateAllPos();
        // setto se il re opposto al pezzo mosso è in Scacco
        setKingCheck(!piece->isWhite);
        // setto se il re che ha mosso è in Scacco (nel caso in cui va a mangiare (liberandosi dallo scacco), il suo isInCheck da 1 va a 0)
        setKingCheck(piece->isWhite);
        // se il re del colore opposto è in scacco faccio una stampa
        if (isKingInCheck(!piece->isWhite)) {
            cout << "Re colore " << !piece->isWhite << "in Scacco" << endl;
        }
        return;
    }
}
void ChessBoard::queenning(Piece* pawn)
{
    if (! instanceof <Pawn>(pawn))
        return;

    if (pawn != NULL) {
        if (pawn->isWhite) {
            if (pawn->p.getY() == 7) {
                int x = pawn->p.getX();
                int choice = -1;
                Position pos = Position(x, 7);

                while (choice < 0 || choice > 4) {

                    cout << "0 per Queen" << endl;
                    cout << "1 per Rook" << endl;
                    cout << "2 per Bishop" << endl;
                    cout << "3 per Knight" << endl;
                    cin >> choice;

                    switch (choice) {
                    case 0:
                        ResQpieces[0].setPosition(pos);
                        Pieces[indexOfPiece(pawn)] = &ResQpieces[0];
                        break;

                    case 1:
                        ResRpieces[0].setPosition(pos);
                        Pieces[indexOfPiece(pawn)] = &ResRpieces[0];
                        break;

                    case 2:
                        ResBpieces[0].setPosition(pos);
                        Pieces[indexOfPiece(pawn)] = &ResBpieces[0];
                        break;

                    case 3:
                        ResKNpieces[0].setPosition(pos);
                        Pieces[indexOfPiece(pawn)] = &ResKNpieces[0];
                        break;

                    default:
                        cout << "SCELTA INVALIDA" << endl;
                        break;
                    }
                }
            }
        } else {
            if (pawn->p.getY() == 0) {
                int x = pawn->p.getX();
                int choice = -1;
                Position pos = Position(x, 0);

                while (choice < 0 || choice > 4) {

                    cout << "0 per Queen" << endl;
                    cout << "1 per Rook" << endl;
                    cout << "2 per Bishop" << endl;
                    cout << "3 per Knight" << endl;
                    cin >> choice;

                    switch (choice) {
                    case 0:
                        ResQpieces[1].p = pos;
                        Pieces[indexOfPiece(pawn)] = &ResQpieces[1];
                        break;

                    case 1:
                        ResRpieces[1].p = pos;
                        Pieces[indexOfPiece(pawn)] = &ResRpieces[1];
                        break;

                    case 2:
                        ResBpieces[1].p = pos;
                        Pieces[indexOfPiece(pawn)] = &ResBpieces[1];
                        break;

                    case 3:
                        ResKNpieces[1].p = pos;
                        Pieces[indexOfPiece(pawn)] = &ResKNpieces[1];
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

bool ChessBoard::canQueen(Piece* p)
{
    if (! instanceof <Pawn>(p))
        return false;

    if (p->isWhite) {
        return p->p.getY() == 7;
    } else {
        return p->p.getY() == 0;
    }
}
Piece* ChessBoard::searchPieceByName(string name)
{
    for (auto& piece : Pieces) {
        if (instanceof <King>(piece)) {
            if (((King*)piece)->name == name) {
                return piece;
            }
        } else if (instanceof <Queen>(piece)) {
            if (((Queen*)piece)->name == name) {
                return piece;
            }
        } else if (instanceof <Rook>(piece)) {
            if (((Rook*)piece)->name == name) {
                return piece;
            }
        } else if (instanceof <Bishop>(piece)) {
            if (((Bishop*)piece)->name == name) {
                return piece;
            }
        } else if (instanceof <Knight>(piece)) {
            if (((Knight*)piece)->name == name) {
                return piece;
            }
        } else if (instanceof <Pawn>(piece)) {
            if (((Pawn*)piece)->name == name) {
                return piece;
            }
        }
    }

    return NULL;
}
void ChessBoard::setKingCheck(int color)
{
    cout << "Try Check" << endl;
    string name = "white king";
    if (!color) {
        name = "black king";
    }

    Piece* WK = searchPieceByName(name);

    for (auto& piece : Pieces) {
        if (piece->isWhite != color) {
            for (const Position& p : piece->controlledPos) {
                if (p == WK->p) {
                    ((King*)WK)->isInCheck = true;
                    return;
                }
            }
        }
    }

    ((King*)WK)->isInCheck = false;
}

void ChessBoard::generateAllPos()
{
    for (auto& piece : Pieces) {
        generatePos(piece);
    }
}

bool ChessBoard::canEat(Piece* piece, Position pos)
{
    Piece* temp = searchPiece(pos);
    if (! instanceof <King>(piece)) {
        return temp != NULL && piece->isOpposite(temp);
    } else {
        return !willKingBeInCheck(piece->isWhite, pos);
    }
}

void ChessBoard::eat(Piece* piece, Position pos)
{
    Piece* temp = searchPiece(pos);

    if (canEat(piece, pos)) {
        killPiece(temp);

        piece->move(pos);
        if (piece->isVirgin) {
            killPieceVerginity(piece);
        }

        if (canQueen(piece)) {
            queenning(piece);
        }

        generateAllPos();
        // controllo re colore opposto se è in check
        setKingCheck(!piece->isWhite);
        setKingCheck(piece->isWhite);
        if (isKingInCheck(!piece->isWhite)) {
            cout << "Re colore " << !piece->isWhite << "in Scacco" << endl;
        }
    }
}

void ChessBoard::mergePos(Piece* piece)
{

    for (int i = 0; i < piece->controlledPos.size(); i++) {
        // se la nella posizione controllata posso mangiare, allora la faccio diventare accessibile
        if (canEat(piece, piece->controlledPos[i])) {
            piece->accessiblePos.push_back(piece->controlledPos[i]);
        }
    }
}
bool ChessBoard::willKingBeInCheck(bool color, Position pos)
{
    for (auto& piece : Pieces) {
        if (piece->isWhite != color) {
            for (const Position& p : piece->controlledPos) {
                if (p == pos) {
                    return true;
                }
            }
        }
    }

    // se si è arrivati qua piece è re e pos non è controllata da nessun pezzo opposto
    return false;
}
