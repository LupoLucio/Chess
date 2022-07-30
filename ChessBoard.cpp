
#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

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
inline bool instanceof(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}

ChessBoard::ChessBoard(){

        

        Kpieces.push_back(King("white king",1,1,Position(4,0)));
        Qpieces.push_back(Queen("white queen",1,1,Position(3,0)));
        Rpieces.push_back(Rook("white rook 1",1,1,Position(0,0)));
        Rpieces.push_back(Rook("white rook 2",1,1,Position(7,0)));
        Bpieces.push_back(Bishop("white bishop 1",1,1,Position(2,0)));
        Bpieces.push_back(Bishop("white bishop 2",1,1,Position(5,0)));
        KNpieces.push_back(Knight("white knight 1",1,1,Position(1,0)));
        KNpieces.push_back(Knight("white knight 2",1,1,Position(6,0)));
        Ppieces.push_back(Pawn("white pawn 1",1,1,Position(0,1)));
        Ppieces.push_back(Pawn("white pawn 2",1,1,Position(1,1)));
        Ppieces.push_back(Pawn("white pawn 3",1,1,Position(2,1)));
        Ppieces.push_back(Pawn("white pawn 4",1,1,Position(3,1)));
        Ppieces.push_back(Pawn("white pawn 5",1,1,Position(4,1)));
        Ppieces.push_back(Pawn("white pawn 6",1,1,Position(5,1)));
        Ppieces.push_back(Pawn("white pawn 7",1,1,Position(6,1)));
        Ppieces.push_back(Pawn("white pawn 8",1,1,Position(7,1)));

        Kpieces.push_back(King("black king",0,1,Position(4,7)));
        Qpieces.push_back(Queen("black queen",0,1,Position(3,7)));
        Rpieces.push_back(Rook("black rook 1",0,1,Position(0,7)));
        Rpieces.push_back(Rook("black rook 2",0,1,Position(7,7)));
        Bpieces.push_back(Bishop("black bishop 1",0,1,Position(2,7)));
        Bpieces.push_back(Bishop("black bishop 2",0,1,Position(5,7)));
        KNpieces.push_back(Knight("black knight 1",0,1,Position(1,7)));
        KNpieces.push_back(Knight("black knight 2",0,1,Position(6,7)));
        Ppieces.push_back(Pawn("black pawn 1",0,1,Position(0,6)));
        Ppieces.push_back(Pawn("black pawn 2",0,1,Position(1,6)));
        Ppieces.push_back(Pawn("black pawn 3",0,1,Position(2,6)));
        Ppieces.push_back(Pawn("black pawn 4",0,1,Position(3,6)));
        Ppieces.push_back(Pawn("black pawn 5",0,1,Position(4,6)));
        Ppieces.push_back(Pawn("black pawn 6",0,1,Position(5,6)));
        Ppieces.push_back(Pawn("black pawn 7",0,1,Position(6,6)));
        Ppieces.push_back(Pawn("black pawn 8",0,1,Position(7,6)));

        generateAllPos();

}
void ChessBoard::printPieces(){
    cout << "Pieces are :  " << endl;

    cout << "Pawns" << endl;
    for( auto& piece : Ppieces)
    {
        piece.printPiece();
    }
    cout << "Knights" << endl;
    for( auto& piece : KNpieces)
    {
        piece.printPiece();
    }
    cout << "Bishop" << endl;
    for( auto& piece : Bpieces)
    {
        piece.printPiece();
    }
    cout << "Rooks" << endl;
    for( auto& piece : Rpieces)
    {
        piece.printPiece();
    }
    cout << "Queens" << endl;
    for( auto& piece : Qpieces)
    {
        piece.printPiece();
    }
    cout << "Kings" << endl;
    for( auto& piece : Kpieces)
    {
        piece.printPiece();
    }

    cout << "End Pieces" << endl;
}

void ChessBoard::printChessBoard(){
    Piece *p;
    cout << "    ";
    for(int i=0;i<8;i++){
        cout << i << "  ";
    }
    for(int i=0;i<8;i++){
        cout << endl;
        cout << i << "   ";
        for(int j=0;j<8;j++){
            p = searchPiece(Position(i,j));
            if(p!=NULL){
                if(p->isLive){
                        if(p->isWhite){
                            if(instanceof<King>(p)){
                                cout << "wK ";

                            }else if(instanceof<Queen>(p)){
                                cout << "wq ";

                            }else if(instanceof<Rook>(p)){
                                cout << "wr ";

                            }else if(instanceof<Bishop>(p)){
                                cout << "wb ";

                            }else if(instanceof<Knight>(p)){
                                cout << "wk ";

                            }else if(instanceof<Pawn>(p)){
                                cout << "wp ";

                            }
                        }else{
                            if(instanceof<King>(p)){
                                cout << "bK ";

                            }else if(instanceof<Queen>(p)){
                                cout << "bq ";

                            }else if(instanceof<Rook>(p)){
                                cout << "br ";

                            }else if(instanceof<Bishop>(p)){
                                cout << "bb ";

                            }else if(instanceof<Knight>(p)){
                                cout << "bk ";

                            }else if(instanceof<Pawn>(p)){
                                cout << "bp ";
                            }                    
                        }


                }
            }else{
                    cout << "   ";
            }


        }
    }
    cout << endl;
}

bool ChessBoard::isOccpied(Position p){
    // Searching Kpieces
    for( auto& piece : Kpieces)
    {
        if(piece.isLive){
            if(piece.p == p){
                return true;
            }
        }
    }
    // Searching for Qpieces
    for( auto& piece : Qpieces)
    {
        if(piece.isLive){
            if(piece.p == p){
                return true;
            }
        }
    }
    // Searching for Rpieces
    for( auto& piece : Rpieces)
    {
        if(piece.isLive){
            if(piece.p == p){
                return true;
            }
        }
    }
    // Searching for Bpieces
    for( auto& piece : Bpieces)
    {
        if(piece.isLive){
            if(piece.p == p){
                return true;
            }
        }
    }
    // Searching for KNpieces
    for( auto& piece : KNpieces)
    {
        if(piece.isLive){
            if(piece.p == p){
                return true;
            }
        }
    }
    // Searching for Ppieces
    for( auto& piece : Ppieces)
    {
        if(piece.isLive){
            if(piece.p == p){
                return true;
            }
        }
    }


    return false;
}

Piece *ChessBoard::searchPiece(Position p){
    // Searching Kpieces
    for( auto& piece : Kpieces)
    {
        if(piece.isLive){
            if(piece.p == p){
                return &piece;
            }
        }
    }
    // Searching for Qpieces
    for( auto& piece : Qpieces)
    {
        if(piece.isLive){
            if(piece.p == p){
                return &piece;
            }
        }
    }
    // Searching for Rpieces
    for( auto& piece : Rpieces)
    {
        if(piece.isLive){
            if(piece.p == p){
                return &piece;
            }
        }
    }
    // Searching for Bpieces
    for( auto& piece : Bpieces)
    {
        if(piece.isLive){
            if(piece.p == p){
                return &piece;
            }
        }
    } 
    // Searching for KNpieces
    for( auto& piece : KNpieces)
    {
        if(piece.isLive){
            if(piece.p == p){
                return &piece;
            }
        }
    }
    // Searching for Ppieces
    for( auto& piece : Ppieces)
    {
        if(piece.isLive){
            if(piece.p == p){
                return &piece;
            }
        }
    }

    return NULL;

}



bool isPositionValid(Position p){
    return (p.getX()<=7 && p.getX() >= 0 && p.getY()<=7 && p.getY()>=0);
}

void ChessBoard::generatePos(Piece *piece){
    // ogni volta che le genero le pulisco prima
    clearPos(piece);
    // check se è King
    if(instanceof<King>(piece)){

        // check posizione alto a sx
        if(isPositionValid(Position((piece->p).getX()-1,(piece->p).getY()+1)) && !isOccpied(Position((piece->p).getX()-1,(piece->p).getY()+1))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()-1,(piece->p).getY()+1));
        }
        if(isPositionValid(Position((piece->p).getX()-1,(piece->p).getY()+1))){
            (piece->controlledPos).push_back(Position((piece->p).getX()-1,(piece->p).getY()+1));
        }

        // check posizione in alto
        if(isPositionValid(Position((piece->p).getX(),(piece->p).getY()+1)) && !isOccpied(Position((piece->p).getX(),(piece->p).getY()+1))){
            (piece->accessiblePos).push_back(Position((piece->p).getX(),(piece->p).getY()+1));
        }
        if(isPositionValid(Position((piece->p).getX(),(piece->p).getY()+1))){
            (piece->controlledPos).push_back(Position((piece->p).getX(),(piece->p).getY()+1));
        }

        // check posizione alto a dx
        if(isPositionValid(Position((piece->p).getX()+1,(piece->p).getY()+1)) && !isOccpied(Position((piece->p).getX()+1,(piece->p).getY()+1))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()+1,(piece->p).getY()+1));
        }
        if(isPositionValid(Position((piece->p).getX()+1,(piece->p).getY()+1))){
            (piece->controlledPos).push_back(Position((piece->p).getX()+1,(piece->p).getY()+1));
        }

        // check posizione a dx
        if(isPositionValid(Position((piece->p).getX()+1,(piece->p).getY())) && !isOccpied(Position((piece->p).getX()+1,(piece->p).getY()))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()+1,(piece->p).getY()));
        }
        if(isPositionValid(Position((piece->p).getX()+1,(piece->p).getY()))){
            (piece->controlledPos).push_back(Position((piece->p).getX()+1,(piece->p).getY()));
        }
        // check posizione in basso a dx
        if(isPositionValid(Position((piece->p).getX()+1,(piece->p).getY()-1)) && !isOccpied(Position((piece->p).getX()+1,(piece->p).getY()-1))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()+1,(piece->p).getY()-1));
        }
        if(isPositionValid(Position((piece->p).getX()+1,(piece->p).getY()-1))){
            (piece->controlledPos).push_back(Position((piece->p).getX()+1,(piece->p).getY()-1));
        }
        // check posizione in basso
        if(isPositionValid(Position((piece->p).getX(),(piece->p).getY()-1)) && !isOccpied(Position((piece->p).getX(),(piece->p).getY()-1))){
            (piece->accessiblePos).push_back(Position((piece->p).getX(),(piece->p).getY()-1));
        }
        if(isPositionValid(Position((piece->p).getX(),(piece->p).getY()-1))){
            (piece->controlledPos).push_back(Position((piece->p).getX(),(piece->p).getY()-1));
        }
        // check posizione in basso a sx
        if(isPositionValid(Position((piece->p).getX()-1,(piece->p).getY()-1)) && !isOccpied(Position((piece->p).getX()-1,(piece->p).getY()-1))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()-1,(piece->p).getY()-1));
        }
        if(isPositionValid(Position((piece->p).getX()-1,(piece->p).getY()-1))){
            (piece->controlledPos).push_back(Position((piece->p).getX()-1,(piece->p).getY()-1));
        }
        // check posizione a sx
        if(isPositionValid(Position((piece->p).getX()-1,(piece->p).getY())) && !isOccpied(Position((piece->p).getX()-1,(piece->p).getY()))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()-1,(piece->p).getY()));
        }
        if(isPositionValid(Position((piece->p).getX()-1,(piece->p).getY()))){
            (piece->controlledPos).push_back(Position((piece->p).getX()-1,(piece->p).getY()));
        }

    }
    // check se è Queen
    else if(instanceof<Queen>(piece)){

        // check posizioni in alto sx
        int i = 1;
        
        while(isPositionValid(Position((piece->p).getX()-i,(piece->p).getY()+i)) && !isOccpied(Position((piece->p).getX()-i,(piece->p).getY()+i))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()-i,(piece->p).getY()+i));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX()-i,(piece->p).getY()+i))){
            (piece->controlledPos).push_back(Position((piece->p).getX()-i,(piece->p).getY()+i));
        }
        // check posizione in alto
        i = 1;
        
        while(isPositionValid(Position((piece->p).getX(),(piece->p).getY()+i)) && !isOccpied(Position((piece->p).getX(),(piece->p).getY()+i))){
            (piece->accessiblePos).push_back(Position((piece->p).getX(),(piece->p).getY()+i));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX(),(piece->p).getY()+i))){
            (piece->controlledPos).push_back(Position((piece->p).getX(),(piece->p).getY()+i));
        }
        // check posizioni in alto a dx
        i = 1;
        
        while(isPositionValid(Position((piece->p).getX()+i,(piece->p).getY()+i)) && !isOccpied(Position((piece->p).getX()+i,(piece->p).getY()+i))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()+i,(piece->p).getY()+i));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX()+i,(piece->p).getY()+i))){
            (piece->controlledPos).push_back(Position((piece->p).getX()+i,(piece->p).getY()+i));
        }
        // check posizioni a dx
        i = 1;
        
        while(isPositionValid(Position((piece->p).getX()+i,(piece->p).getY())) && !isOccpied(Position((piece->p).getX()+i,(piece->p).getY()))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()+i,(piece->p).getY()));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX()+i,(piece->p).getY()))){
            (piece->controlledPos).push_back(Position((piece->p).getX()+i,(piece->p).getY()));
        }
        // check posizioni in basso a dx
        i = 1;
        while(isPositionValid(Position((piece->p).getX()+i,(piece->p).getY()-i)) && !isOccpied(Position((piece->p).getX()+i,(piece->p).getY()-i))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()+i,(piece->p).getY()-i));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX()+i,(piece->p).getY()-i))){
            (piece->controlledPos).push_back(Position((piece->p).getX()+i,(piece->p).getY()-i));
        }
        // check posizioni in basso
        i = 1;
        while(isPositionValid(Position((piece->p).getX(),(piece->p).getY()-i)) && !isOccpied(Position((piece->p).getX(),(piece->p).getY()-i))){
            (piece->accessiblePos).push_back(Position((piece->p).getX(),(piece->p).getY()-i));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX(),(piece->p).getY()-i))){
            (piece->controlledPos).push_back(Position((piece->p).getX(),(piece->p).getY()-i));
        }
        // check posizioni in basso a sx
        i = 1;
        while(isPositionValid(Position((piece->p).getX()-i,(piece->p).getY()-i)) && !isOccpied(Position((piece->p).getX()-i,(piece->p).getY()-i))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()-i,(piece->p).getY()-i));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX()-i,(piece->p).getY()-i))){
            (piece->controlledPos).push_back(Position((piece->p).getX()-i,(piece->p).getY()-i));
        }
        // check posizioni a sx
        i = 1;
        while(isPositionValid(Position((piece->p).getX()-i,(piece->p).getY())) && !isOccpied(Position((piece->p).getX()-i,(piece->p).getY()))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()-i,(piece->p).getY()));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX()-i,(piece->p).getY()))){
            (piece->controlledPos).push_back(Position((piece->p).getX()-i,(piece->p).getY()));
        }

    }
    // check se è Rook
    else if(instanceof<Rook>(piece)){
        // check posizione in alto
        int i = 1;
        
        while(isPositionValid(Position((piece->p).getX(),(piece->p).getY()+i)) && !isOccpied(Position((piece->p).getX(),(piece->p).getY()+i))){
            (piece->accessiblePos).push_back(Position((piece->p).getX(),(piece->p).getY()+i));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX(),(piece->p).getY()+i))){
            (piece->controlledPos).push_back(Position((piece->p).getX(),(piece->p).getY()+i));
        }
        // check posizioni in basso
        i = 1;
        while(isPositionValid(Position((piece->p).getX(),(piece->p).getY()-i)) && !isOccpied(Position((piece->p).getX(),(piece->p).getY()-i))){
            (piece->accessiblePos).push_back(Position((piece->p).getX(),(piece->p).getY()-i));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX(),(piece->p).getY()-i))){
            (piece->controlledPos).push_back(Position((piece->p).getX(),(piece->p).getY()-i));
        }
        // check posizioni a sx
        i = 1;
        while(isPositionValid(Position((piece->p).getX()-i,(piece->p).getY())) && !isOccpied(Position((piece->p).getX()-i,(piece->p).getY()))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()-i,(piece->p).getY()));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX()-i,(piece->p).getY()))){
            (piece->controlledPos).push_back(Position((piece->p).getX()-i,(piece->p).getY()));
        }
        // check posizioni a dx
        i = 1;
        
        while(isPositionValid(Position((piece->p).getX()+i,(piece->p).getY())) && !isOccpied(Position((piece->p).getX()+i,(piece->p).getY()))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()+i,(piece->p).getY()));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX()+i,(piece->p).getY()))){
            (piece->controlledPos).push_back(Position((piece->p).getX()+i,(piece->p).getY()));
        }

    }
    // check se è Bhishop
    else if(instanceof<Bishop>(piece)){
        // check posizioni in alto sx
        int i = 1;
        
        while(isPositionValid(Position((piece->p).getX()-i,(piece->p).getY()+i)) && !isOccpied(Position((piece->p).getX()-i,(piece->p).getY()+i))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()-i,(piece->p).getY()+i));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX()-i,(piece->p).getY()+i))){
            (piece->controlledPos).push_back(Position((piece->p).getX()-i,(piece->p).getY()+i));
        }
        // check posizioni in alto a dx
        i = 1;
        
        while(isPositionValid(Position((piece->p).getX()+i,(piece->p).getY()+i)) && !isOccpied(Position((piece->p).getX()+i,(piece->p).getY()+i))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()+i,(piece->p).getY()+i));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX()+i,(piece->p).getY()+i))){
            (piece->controlledPos).push_back(Position((piece->p).getX()+i,(piece->p).getY()+i));
        }
        // check posizioni in basso a dx
        i = 1;
        while(isPositionValid(Position((piece->p).getX()+i,(piece->p).getY()-i)) && !isOccpied(Position((piece->p).getX()+i,(piece->p).getY()-i))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()+i,(piece->p).getY()-i));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX()+i,(piece->p).getY()-i))){
            (piece->controlledPos).push_back(Position((piece->p).getX()+i,(piece->p).getY()-i));
        }
        // check posizioni in basso a sx
        i = 1;
        while(isPositionValid(Position((piece->p).getX()-i,(piece->p).getY()-i)) && !isOccpied(Position((piece->p).getX()-i,(piece->p).getY()-i))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()-i,(piece->p).getY()-i));
            i++;
        }
        if(isPositionValid(Position((piece->p).getX()-i,(piece->p).getY()-i))){
            (piece->controlledPos).push_back(Position((piece->p).getX()-i,(piece->p).getY()-i));
        }

    }
    // check se è knight
    else if(instanceof<Knight>(piece)){

        // check posizione medio alto sx
        if(isPositionValid(Position((piece->p).getX()-2,(piece->p).getY()+1)) && !isOccpied(Position((piece->p).getX()-2,(piece->p).getY()+1))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()-2,(piece->p).getY()+1));
        }
        if(isPositionValid(Position((piece->p).getX()-2,(piece->p).getY()+1))){
            (piece->controlledPos).push_back(Position((piece->p).getX()-2,(piece->p).getY()+1));
        }
        // check posizione alto sx
        if(isPositionValid(Position((piece->p).getX()-1,(piece->p).getY()+2)) && !isOccpied(Position((piece->p).getX()-1,(piece->p).getY()+2))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()-1,(piece->p).getY()+2));
        }
        if(isPositionValid(Position((piece->p).getX()-1,(piece->p).getY()+2))){
            (piece->controlledPos).push_back(Position((piece->p).getX()-1,(piece->p).getY()+2));
        }
        // check posizione alto dx
        if(isPositionValid(Position((piece->p).getX()+1,(piece->p).getY()+2)) && !isOccpied(Position((piece->p).getX()+1,(piece->p).getY()+2))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()+1,(piece->p).getY()+2));
        }
        if(isPositionValid(Position((piece->p).getX()+1,(piece->p).getY()+2))){
            (piece->controlledPos).push_back(Position((piece->p).getX()+1,(piece->p).getY()+2));
        }
        // check posizione medio alto dx
        if(isPositionValid(Position((piece->p).getX()+2,(piece->p).getY()+1)) && !isOccpied(Position((piece->p).getX()+2,(piece->p).getY()+1))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()+2,(piece->p).getY()+1));
        }
        if(isPositionValid(Position((piece->p).getX()+2,(piece->p).getY()+1))){
            (piece->controlledPos).push_back(Position((piece->p).getX()+2,(piece->p).getY()+1));
        }
        // check posizione medio basso dx
        if(isPositionValid(Position((piece->p).getX()+2,(piece->p).getY()-1)) && !isOccpied(Position((piece->p).getX()+2,(piece->p).getY()-1))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()+2,(piece->p).getY()-1));
        }
        if(isPositionValid(Position((piece->p).getX()+2,(piece->p).getY()-1))){
            (piece->controlledPos).push_back(Position((piece->p).getX()+2,(piece->p).getY()-1));
        }
        // check posizione basso dx
        if(isPositionValid(Position((piece->p).getX()+1,(piece->p).getY()-2)) && !isOccpied(Position((piece->p).getX()+1,(piece->p).getY()-2))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()+1,(piece->p).getY()-2));
        }
        if(isPositionValid(Position((piece->p).getX()+1,(piece->p).getY()-2))){
            (piece->controlledPos).push_back(Position((piece->p).getX()+1,(piece->p).getY()-2));
        }
        // check posizione basso sx
        if(isPositionValid(Position((piece->p).getX()-1,(piece->p).getY()-2)) && !isOccpied(Position((piece->p).getX()-1,(piece->p).getY()-2))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()-1,(piece->p).getY()-2));
        }
        if(isPositionValid(Position((piece->p).getX()-1,(piece->p).getY()-2))){
            (piece->controlledPos).push_back(Position((piece->p).getX()-1,(piece->p).getY()-2));
        }
        // check posizione medio basso sx
        if(isPositionValid(Position((piece->p).getX()-2,(piece->p).getY()-1)) && !isOccpied(Position((piece->p).getX()-2,(piece->p).getY()-1))){
            (piece->accessiblePos).push_back(Position((piece->p).getX()-2,(piece->p).getY()-1));
        }
        if(isPositionValid(Position((piece->p).getX()-2,(piece->p).getY()-1))){
            (piece->controlledPos).push_back(Position((piece->p).getX()-2,(piece->p).getY()-1));
        }

    }
    // check se è Pawn
    else if(instanceof<Pawn>(piece)){
        //check if white
        if(piece->isWhite){

            // check posizione alto a sx
            if(isPositionValid(Position((piece->p).getX()-1,(piece->p).getY()+1))){
                (piece->controlledPos).push_back(Position((piece->p).getX()-1,(piece->p).getY()+1));
            }

            // check posizione alto a dx
            if(isPositionValid(Position((piece->p).getX()+1,(piece->p).getY()+1))){
                (piece->controlledPos).push_back(Position((piece->p).getX()+1,(piece->p).getY()+1));
            }

            // check posizione alto unica per le accessibili
            if(isPositionValid(Position((piece->p).getX(),(piece->p).getY()+1)) && !isOccpied(Position((piece->p).getX(),(piece->p).getY()+1))){
                (piece->accessiblePos).push_back(Position((piece->p).getX(),(piece->p).getY()+1));
            }
            // check se è vergine
            if(piece->isVirgin){
                // check posizione alto di 2
                if(isPositionValid(Position((piece->p).getX(),(piece->p).getY()+2))){
                    (piece->accessiblePos).push_back(Position((piece->p).getX(),(piece->p).getY()+2));
                }                
            }


        }else{
            // check posizione basso a sx
            if(isPositionValid(Position((piece->p).getX()-1,(piece->p).getY()-1))){
                (piece->controlledPos).push_back(Position((piece->p).getX()-1,(piece->p).getY()-1));
            }
            // check posizione basso a dx
            if(isPositionValid(Position((piece->p).getX()+1,(piece->p).getY()-1))){
                (piece->controlledPos).push_back(Position((piece->p).getX()+1,(piece->p).getY()-1));
            }
            // check posizione basso unica per le accessibili
            if(isPositionValid(Position((piece->p).getX(),(piece->p).getY()-1)) && !isOccpied(Position((piece->p).getX(),(piece->p).getY()-1))){
                (piece->accessiblePos).push_back(Position((piece->p).getX(),(piece->p).getY()-1));
            } 
            // check se è vergine
            if(piece->isVirgin){
                // check posizione basso di 2
                if(isPositionValid(Position((piece->p).getX(),(piece->p).getY()-2))){
                    (piece->accessiblePos).push_back(Position((piece->p).getX(),(piece->p).getY()-2));
                }                
            }

        }


    }
}

void ChessBoard::clearPos(Piece *piece){

        piece->accessiblePos.clear();
        piece->controlledPos.clear();

}
int ChessBoard::indexOfPiece(Piece *piece){
    if(instanceof<King>(piece)){
        for(int i=0;i<Kpieces.size();i++){
            if(Kpieces[i] == piece)
                return i;
        }
    }else if(instanceof<Queen>(piece)){
        for(int i=0;i<Qpieces.size();i++){
            if(Qpieces[i] == piece)
                return i;
        }
    }else if(instanceof<Rook>(piece)){
        for(int i=0;i<Rpieces.size();i++){
            if(Rpieces[i] == piece)
                return i;
        }        
    }else if(instanceof<Bishop>(piece)){
        for(int i=0;i<Bpieces.size();i++){
            if(Bpieces[i] == piece)
                return i;
        }          
    }else if(instanceof<Knight>(piece)){
        for(int i=0;i<KNpieces.size();i++){
            if(KNpieces[i] == piece)
                return i;
        }        
    }else if(instanceof<Pawn>(piece)){
        for(int i=0;i<Ppieces.size();i++){
            if(Ppieces[i] == piece)
                return i;
        }
    }

    return -1;
}
void ChessBoard::kill(Piece *piece,int index){
    if(instanceof<King>(piece)){
        Kpieces[index].isLive = 0;
    }else if(instanceof<Queen>(piece)){
        Qpieces[index].isLive = 0;
    }else if(instanceof<Rook>(piece)){
        Rpieces[index].isLive = 0;
    }else if(instanceof<Bishop>(piece)){
        Bpieces[index].isLive = 0;
    }else if(instanceof<Knight>(piece)){
        KNpieces[index].isLive = 0;
    }else if(instanceof<Pawn>(piece)){
        Ppieces[index].isLive = 0;
    }
}
void ChessBoard::killPiece(Piece *piece){
    int index = indexOfPiece(piece);
    kill(piece,index);
    return;
}
void ChessBoard::killVerginity(Piece *piece,int index){
    if(instanceof<King>(piece)){
        Kpieces[index].isVirgin = 0;
    }else if(instanceof<Queen>(piece)){
        KNpieces[index].isVirgin = 0;
    }else if(instanceof<Rook>(piece)){
        Rpieces[index].isVirgin = 0;
    }else if(instanceof<Bishop>(piece)){
        Bpieces[index].isVirgin = 0;
    }else if(instanceof<Knight>(piece)){
        KNpieces[index].isVirgin = 0;
    }else if(instanceof<Pawn>(piece)){
        Ppieces[index].isVirgin = 0;
    }
}
void ChessBoard::killPieceVerginity(Piece *piece){
    int index = indexOfPiece(piece);
    killVerginity(piece,index);
    return;
}
bool ChessBoard::isKingInCheck(int color){
    return color ? Kpieces[0].isInCheck : Kpieces[1].isInCheck;
}
void ChessBoard::move(Piece *piece,Position pos){
    /* controllo se nelle controlled del piece c'è pos
     se c'è memorizzo in temp in pezzo in pos
     se il pezzo è di un altro colore (Opposite) uccido lui e muovo piece 
     */
    for(int i=0;i<piece->controlledPos.size();i++){
        if(piece->controlledPos[i] == pos){
            if(canEat(piece,pos)){
                eat(piece,pos);
                return;
            }
        }
    }

    // ora cerco nelle accessibili
    for(int i=0;i<piece->accessiblePos.size();i++){
        if(piece->accessiblePos[i] == pos){
            piece->move(pos);
            if(piece->isVirgin){
                killPieceVerginity(piece);
            }
            
            if(canQueen(piece)){
            queenning(piece);
            }
            
            generateAllPos();
            setKingCheck(!piece->isWhite);
            setKingCheck(piece->isWhite);
            if(isKingInCheck(!piece->isWhite)){
                cout << "Re colore " << !piece->isWhite << "in Scacco" << endl;
            }
            return;
        }
    }
    
}
void ChessBoard::queenning(Piece *pawn){
    if(!instanceof<Pawn>(pawn)) return;

    if(pawn!= NULL){
        if(pawn->isWhite){
            if(pawn->p.getY() == 7){
                int x = pawn->p.getX();
                killPiece(pawn);
                Qpieces.push_back(Queen("white queen 2",1,1,Position(x,7)));
            }
        }else{
            if(pawn->p.getY() == 0){
                int x = pawn->p.getX();
                killPiece(pawn);
                Qpieces.push_back(Queen("black queen 2",1,1,Position(x,0)));
            }
        }
    }
}

bool ChessBoard::canQueen(Piece *p){
    if(!instanceof<Pawn>(p)) return false;

    if(p->isWhite){
        return p->p.getY() == 7;
    }else{
        return p->p.getY() == 0;
    }
}
Piece* ChessBoard::searchPieceByName(string name){
    for( auto& piece : Kpieces)
    {
        if(piece.name == name){
            return &piece;
        }
    }
    for( auto& piece : Qpieces)
    {
        if(piece.name == name){
            return &piece;
        }
    }
    for( auto& piece : Rpieces)
    {
        if(piece.name == name){
            return &piece;
        }
    }
    for( auto& piece : Bpieces)
    {
        if(piece.name == name){
            return &piece;
        }
    }
    for( auto& piece : KNpieces)
    {
        if(piece.name == name){
            return &piece;
        }
    }
    for( auto& piece : Ppieces)
    {
        if(piece.name == name){
            return &piece;
        }
    }

    return NULL;
}
void ChessBoard::setKingCheck(int color){
    cout << "Try Check" << endl;
    string name = "white king";
    if(!color)
    {
        name = "black king";
    }
    
    Piece *WK = searchPieceByName(name);
    for(const auto& piece : Kpieces){
        if(piece.isWhite != color){
            for(const Position& p : piece.controlledPos){
                if(p == WK->p){
                    ((King*)WK)->isInCheck = true;
                    return;
                }
            }
        }
    }
    for(const auto& piece : Qpieces){
        if(piece.isWhite != color){
            for(const Position& p : piece.controlledPos){
                if(p == WK->p){
                    ((King*)WK)->isInCheck = true;
                    return;
                }
            }
        }
    }
    for(const auto& piece : Rpieces){
        if(piece.isWhite != color){
            for(const Position& p : piece.controlledPos){
                if(p == WK->p){
                    ((King*)WK)->isInCheck = true;
                    return;
                }
            }
        }
    }
    for(const auto& piece : Bpieces){
        if(piece.isWhite != color){
            for(const Position& p : piece.controlledPos){
                if(p == WK->p){
                    ((King*)WK)->isInCheck = true;
                    return;
                }
            }
        }
    }
    for(const auto& piece : KNpieces){
        cout << piece.name << endl;
        cout << piece.controlledPos.size() << endl;
        if(piece.isWhite != color){
            for(const Position& p : piece.controlledPos){
                if(p == WK->p){
                    ((King*)WK)->isInCheck = true;
                    return;
                }
            }
        }
    }
    for(const auto& piece : Ppieces){
        if(piece.isWhite != color){
            for(const Position& p : piece.controlledPos){
                if(p == WK->p){
                    ((King*)WK)->isInCheck = true;
                    return;
                }
            }
        }
    }

    ((King*)WK)->isInCheck = false;
}

void ChessBoard::generateAllPos(){
        for( auto& piece : Kpieces)
        {
            generatePos(&piece);
        }
        for( auto& piece : Qpieces)
        {
            generatePos(&piece);
        }
        for( auto& piece : Rpieces)
        {
            generatePos(&piece);
        }
        for( auto& piece : Bpieces)
        {
            generatePos(&piece);
        }
        for( auto& piece : KNpieces)
        {
            generatePos(&piece);
        }
        for( auto& piece : Ppieces)
        {
            generatePos(&piece);
        }
}

bool ChessBoard::canEat(Piece *piece,Position pos){
    Piece *temp = searchPiece(pos);
    if(!instanceof<King>(piece)){
        return temp != NULL && piece->isOpposite(temp);
    }else{
        // cerco nelle posizioni controllate dei pezzi del colore opposto al re
        for( auto p : Kpieces)
        {
            if(piece->isWhite != p.isWhite){
                for(auto position : p.controlledPos){
                    if(position == pos){
                        return false;
                    }
                }
            }
            
        }
        for( auto p : Qpieces)
        {
            if(piece->isWhite != p.isWhite){
                for(auto position : p.controlledPos){
                    if(position == pos){
                        return false;
                    }
                }
            }
            
        }
        for( auto p : Rpieces)
        {
            if(piece->isWhite != p.isWhite){
                for(auto position : p.controlledPos){
                    if(position == pos){
                        return false;
                    }
                }
            }
            
        }
         for( auto p : Bpieces)
        {
            if(piece->isWhite != p.isWhite){
                for(auto position : p.controlledPos){
                    if(position == pos){
                        return false;
                    }
                }
            }
            
        }
         for( auto p : KNpieces)
        {
            if(piece->isWhite != p.isWhite){
                for(auto position : p.controlledPos){
                    if(position == pos){
                        return false;
                    }
                }
            }
            
        }
        for( auto p : Ppieces)
        {
            if(piece->isWhite != p.isWhite){
                for(auto position : p.controlledPos){
                    if(position == pos){
                        return false;
                    }
                }
            }
            
        }
    // se si è arrivati qua piece è re e pos non è controllata da nessun pezzo opposto
    return true;
    }


}

void ChessBoard::eat(Piece *piece,Position pos){
    Piece *temp = searchPiece(pos);

    if(canEat(piece,pos)){
        killPiece(temp);
            
        piece->move(pos);
        if(piece->isVirgin){
            killPieceVerginity(piece);
        }
        
        if(canQueen(piece)){
            queenning(piece);
        }
        
        generateAllPos();
        // controllo re colore opposto se è in check
        setKingCheck(!piece->isWhite);
        setKingCheck(piece->isWhite);
        if(isKingInCheck(!piece->isWhite)){
            cout << "Re colore " << !piece->isWhite << "in Scacco" << endl;
        }
        
    }

}