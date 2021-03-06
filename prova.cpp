#include "Piece.h"
#include "ChessBoard.h"



int main(){

    ChessBoard cb = ChessBoard();
    Piece *piece;
    Position p;
    int turn = 1;
    int x,y;
    cb.printPieces();


    while(turn == 1 || turn == 0){

        cout << "Inserisci x : ";
        cin >> x;
        cout << "Inserisci y : ";
        cin >> y;       
        p = Position(x,y);
        piece = cb.searchPiece(p);
        if(piece != NULL){
            if(turn == 1){
                cout << "Turno Bianco" << endl;
                if(!piece->isWhite){
                    cout << "Pezzo del colore sbagliato" << endl;
                }else{
                    piece->printPiece();
                    piece->printControlledPos();
                    piece->printAccessiblePos();
                    // muovo il pezzo
                    cout << "Inserisci posizione in cui muoverlo" << endl;
                    cout << "Inserisci x : ";
                    cin >> x;
                    cout << "Inserisci y : ";
                    cin >> y;
                    cb.move(piece,Position(x,y));
                    cb.printPieces();
                    cb.printChessBoard();
                }
                
            }else{
                cout << "Turno nero" << endl;
                if(piece->isWhite){
                    cout << "Pezzo del colore sbagliato" << endl;
                }else{
                    piece->printPiece();
                    cb.generatePos(piece);
                    piece->printControlledPos();
                    piece->printAccessiblePos();
                    
                    // muovo il pezzo
                    cout << "Inserisci posizione in cui muoverlo" << endl;
                    cout << "Inserisci x : ";
                    cin >> x;
                    cout << "Inserisci y : ";
                    cin >> y;
                    cb.move(piece,Position(x,y));
                    cb.printPieces();
                    cb.printChessBoard();
                }
            }
        }else{
            cout << "Pezzo non trovato" << endl;
        }

        cout << "Inserisci turno : " << endl;
        cin >> turn;
    }








    return 0;
}