#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "Position.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
/*
Classe che definisce la ChessBoard nella quale giocano i pezzi
*/

class ChessBoard{

    public:
    // vector dei tipi di pezzi
    std::vector<King> Kpieces;
    std::vector<Queen> Qpieces;
    std::vector<Rook> Rpieces;
    std::vector<Bishop> Bpieces;
    std::vector<Knight> KNpieces;
    std::vector<Pawn> Ppieces;

    

    // matrice di char
    char chessBoard[8][8];
    
    ChessBoard();

    // stampa i pezzi e i loro parametri
    void printPieces();
    // stampa la scacchiera (matrtice di char)
    void printChessBoard();
    // ritorna se la posizione è occupata
    bool isOccpied(Position p);
    // ritorna un puntatore al pezzo nella posizione p
    Piece* searchPiece(Position p);
    // genera le posizioni controllate e accessibili di piece
    void generatePos(Piece *piece);
    // pulisce elimina le posizoini controllate e accessibili di piece
    void clearPos(Piece *piece);
    // muove piece in pos mangiando se cio' accade
    void move(Piece *piece,Position pos);
    // genera le poisizioni di tutti i pezzi
    void generateAllPos();

    // ritorna l'indice di piece nel vector del suo tipo corrispondente
    int indexOfPiece(Piece *piece);
    // funzione interna di uccisione di piece
    void kill(Piece *piece,int index);
    // funzione esterna (da chiamare) per unccidere piece
    void killPiece(Piece *piece);
    // funzione interna di uccisione della verginita' di piece
    void killVerginity(Piece *piece,int index);
    // funzione esterna (da chiamare) per uccidere la verginita' di piece
    void killPieceVerginity(Piece *piece);
    // promozione da pedone a regina
    void queenning(Piece *pawn);
    // ritorna se il pezzo puo' fare la promozione
    bool canQueen(Piece *piece);
    // prova a settare in parametro isInCheck (se la sua pos è nelle controllate dei pezzi opposti) 
    void setKingCheck(int color);
    // ritorne se il pezzo re è in scacco COMPLETARE
    bool isKingInCheck(int color);
    // ritorna la posizione del pezzo con lo stesso nome
    Piece *searchPieceByName(string name);
    // ritorna se il pezzo puo' mangiare in quella posizione
    bool canEat(Piece *piece,Position pos);
    // fa le azioni neccessarie per mangiare
    void eat(Piece *piece,Position pos);

    

};


#endif