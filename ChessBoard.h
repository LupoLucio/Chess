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

    std::vector<Piece*> Pieces;

    // pezzi di riserva
    std::vector<Queen> ResQpieces;
    std::vector<Rook> ResRpieces;
    std::vector<Bishop> ResBpieces;
    std::vector<Knight> ResKNpieces;

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
    // pulisce elimina le posizoini ipotetiche (controllate e accessibili) di piece
    void clearIpoPos(Piece *piece);
    // ritorna se il pezzo puo' muovere
    bool canMove(Piece* piece,Position pos);
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
    // ritorna se il pezzo re è in scacco COMPLETARE
    bool isKingInCheck(int color);
    // ritorna se il re nell'ipotetica posizione pos sarebbe in scacco
    bool willKingBeInCheck(bool color,Position pos);
    // ritorna la posizione del pezzo con lo stesso nome
    Piece *searchPieceByName(string name);
    // ritorna se il pezzo puo' mangiare in quella posizione
    bool canEat(Piece *piece,Position pos);
    // fa le azioni neccessarie per mangiare
    void eat(Piece *piece,Position pos);
    // le controllate in cui in pezzo puo' mangiare vengono anche messe nelle accessibili 
    void mergePos(Piece *piece);
    // ritorna se il pezzo è pinnato da COMPLETARE
    bool isPinned(Piece *piece);
    // genera le posizioni virtuali controllate del piece
    void generateIpoPos(Piece *piece);
    // ritorna se la posizione è valida nella scacchiera
    bool isPositionValid(Position p);
    // genera le ipopos di tutti i pezzi del colore color
    void generateAllIpoPos(bool color);
    // ritorna se le controllate ipotetiche dei pezzi del colore opposto ce il king di color color
    bool willKingBeIpoInCheck(bool color);
    // funzione interna di resuscitazione del pezzo
    void revive(Piece *piece,int index);
    // funzione esterna di resuscitazione del pezzo
    void revivePiece(Piece *piece);

};


#endif