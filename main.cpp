#include "chessboard.h"
#include "piece.h"
#include "chessboardprinter.h"

#include <iostream>
using namespace std;

void execQueenning(ChessBoard &cb, Piece *piece)
{
    while (true)
    {
        const int Noptions = 4;
        Piece::Type arr[Noptions] = { Piece::Type::Queen, Piece::Type::Rook, Piece::Type::Bishop,
                                      Piece::Type::Knight };

        cout << "Devi effettuare la promozione del pedone. Scegli:" << endl;
        for (int i = 0; i < Noptions; i++)
        {
            cout << i << " per " << Piece::getTypeName(arr[i]);
        }

        int choice = 0;
        cin >> choice;

        if (choice < 0 || choice >= Noptions)
        {
            cout << "Scelta non valida. Riprovare" << endl;
            continue;
        }

        Piece::Type newType = arr[choice];
        cb.queenning(piece, newType);
    }
}

bool execTurn(ChessBoard &cb, Piece::Color color)
{
    int turn = 1;
    int x, y;
    cb.printPieces();

    cout << "Inserisci x : ";
    cin >> x;
    cout << "Inserisci y : ";
    cin >> y;

    Position pos(x, y);

    Piece *piece = cb.getPieceAtPos(pos);
    if (!piece)
    {
        cout << "Pezzo assente" << endl;
        return false;
    }

    if (piece->getColor() != color)
    {
        cout << "Pezzo del colore sbagliato" << endl;
        return false;
    }

    cout << "Turno " << Piece::getColorName(color) << endl;
    piece->printPiece();
    piece->printControlledPos();
    piece->printAccessiblePos();

    // muovo il pezzo
    cout << "Inserisci posizione in cui muoverlo" << endl;
    cout << "Inserisci x : ";
    cin >> x;
    cout << "Inserisci y : ";
    cin >> y;

    if (cb.beginMove(piece, Position(x, y)))
    {
        // controllo se dopo aver mosso posso Queenare, se puo' Queenno
        if (cb.canQueen(piece))
        {
            execQueenning(cb, piece);
        }
        cb.endMove(piece);
    }

    cb.printPieces();

    ChessBoardPrinter printer(cb);
    printer.setCurPiece(piece);
    printer.printChessBoardToStdout();

    return true;
}

int main()
{
    ChessBoard cb = ChessBoard();
    Piece *piece;
    Position p;
    int turn = int(Piece::Color::White);

    while (turn == 1 || turn == 0)
    {
        execTurn(cb, Piece::Color(turn));

        cout << "Inserisci turno : " << endl;
        cin >> turn;
    }

    return 0;
}
