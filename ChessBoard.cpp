
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
void ChessBoard::printPieces(){
    cout << "ChessBoard is : " << endl;
    cout << "White pieces : " << endl;
    cout << "Pawns" << endl;
    for(int i=0;i<8;i++){
        Ppieces[i].printPiece();
    }
    cout << "Knights" << endl;
    for(int i=0;i<2;i++){
        KNpieces[i].printPiece();
    }
    cout << "Bhishops" << endl;
    for(int i=0;i<2;i++){
        Bpieces[i].printPiece();
    }
    cout << "Rooks" << endl;
    for(int i=0;i<2;i++){
        Rpieces[i].printPiece();
    }
    cout << "Queen" << endl;
    Qpieces[0].printPiece();
    cout << "King" << endl;
    Kpieces[0].printPiece();

    cout << "Black pieces : " << endl;

    cout << "Pawns" << endl;
    for(int i=8;i<16;i++){
        Ppieces[i].printPiece();
    }
    cout << "Knights" << endl;
    for(int i=2;i<4;i++){
        KNpieces[i].printPiece();
    }
    cout << "Bhishops" << endl;
    for(int i=2;i<4;i++){
        Bpieces[i].printPiece();
    }
    cout << "Rooks" << endl;
    for(int i=2;i<4;i++){
        Rpieces[i].printPiece();
    }
    cout << "Queen" << endl;
    Qpieces[1].printPiece();
    cout << "King" << endl;
    Kpieces[1].printPiece();
    cout << "ChessBoard end" << endl;
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
    for(int i=0;i<Kpieces.size();i++){
        if(Kpieces[i].isLive){
            if(Kpieces[i].p.getX() == p.getX() && Kpieces[i].p.getY() == p.getY()){
                return true;
            }
        }
    }
    // Searching for Qpieces
    for(int i=0;i<Qpieces.size();i++){
        if(Qpieces[i].isLive){
            if(Qpieces[i].p.getX() == p.getX() && Qpieces[i].p.getY() == p.getY()){
                return true;
            }
        }
    }
    // Searching for Rpieces
    for(int i=0;i<Rpieces.size();i++){
        if(Rpieces[i].isLive){
            if(Rpieces[i].p.getX() == p.getX() && Rpieces[i].p.getY() == p.getY()){
                return true;
            }
        }
    }
    // Searching for Bpieces
    for(int i=0;i<Bpieces.size();i++){
        if(Bpieces[i].isLive){
            if(Bpieces[i].p.getX() == p.getX() && Bpieces[i].p.getY() == p.getY()){
                return true;
            }
        }
    } 
    // Searching for KNpieces
    for(int i=0;i<KNpieces.size();i++){
        if(KNpieces[i].isLive){
            if(KNpieces[i].p.getX() == p.getX() && KNpieces[i].p.getY() == p.getY()){
                return true;
            }
        }
    }
    // Searching for Ppieces
    for(int i=0;i<Ppieces.size();i++){
        if(Ppieces[i].isLive){
            if(Ppieces[i].p.getX() == p.getX() && Ppieces[i].p.getY() == p.getY()){
                return true;
            }
        }
    }

    return false;
}

Piece *ChessBoard::searchPiece(Position p){
    // Searching Kpieces
    for(int i=0;i<Kpieces.size();i++){
        if(Kpieces[i].isLive){
            if(Kpieces[i].p == p){
                return &Kpieces[i];
            }
        }
    }
    // Searching for Qpieces
    for(int i=0;i<Qpieces.size();i++){
        if(Qpieces[i].isLive){
            if(Qpieces[i].p == p){
                return &Qpieces[i];
            }
        }
    }
    // Searching for Rpieces
    for(int i=0;i<Rpieces.size();i++){
        if(Rpieces[i].isLive){
            if(Rpieces[i].p == p){
                return &Rpieces[i];
            }
        }
    }
    // Searching for Bpieces
    for(int i=0;i<Bpieces.size();i++){
        if(Bpieces[i].isLive){
            if(Bpieces[i].p == p){
                return &Bpieces[i];
            }
        }
    } 
    // Searching for KNpieces
    for(int i=0;i<KNpieces.size();i++){
        if(KNpieces[i].isLive){
            if(KNpieces[i].p == p){
                return &KNpieces[i];
            }
        }
    }
    // Searching for Ppieces
    for(int i=0;i<Ppieces.size();i++){
        if(Ppieces[i].isLive){
            if(Ppieces[i].p == p){
                return &Ppieces[i];
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
    // check se ?? King
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
            (piece->accessiblePos).push_back(Position((piece->p).getX()-1,(piece->p).getY()+1));
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

        // check posizione alto a dx
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
    // check se ?? Queen
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
    // check se ?? Rook
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
    // check se ?? Bhishop
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
    // check se ?? knight
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
    // check se ?? Pawn
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
            // check se ?? vergine
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
            // check se ?? vergine
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
        KNpieces[index].isLive = 0;
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
    /* controllo se nelle controlled del piece c'?? pos
     se c'?? memorizzo in temp in pezzo in pos
     se il pezzo ?? di un altro colore (Opposite) uccido lui e muovo piece 
     */
    for(int i=0;i<piece->controlledPos.size();i++){
        if(piece->controlledPos[i] == pos){
            // pezzo che c'?? nella posizione pos
            Piece *temp = searchPiece(piece->controlledPos[i]);
            if(temp != NULL && piece->isOpposite(temp)){
                
                killPiece(temp);
                // controllo se ?? vergine, se lo ?? killo la sua verginit?? e muovo
                piece->move(pos);
                if(piece->isVirgin){
                    killPieceVerginity(piece);
                }
                
                if(canQueen(piece)){
                    queenning(piece);
                }
                generatePos(piece);
                // controllo re colore opposto se ?? in check
                setKingCheck(!piece->isWhite);
                if(isKingInCheck(!piece->isWhite)){
                    cout << "Re colore " << !piece->isWhite << "in Scacco" << endl;
                }
                return;
            }else{
                cout << "Impossibile catturare" << endl;
                piece->move(pos);
                generatePos(piece);
                setKingCheck(!piece->isWhite);
                if(isKingInCheck(!piece->isWhite)){
                    cout << "Re colore " << !piece->isWhite << "in Scacco" << endl;
                }
            }
        }
    }


    for(int i=0;i<piece->accessiblePos.size();i++){
        if(piece->accessiblePos[i] == pos){
            if(piece->isVirgin){
                killPieceVerginity(piece);
                }
            piece->move(pos);
            if(canQueen(piece)){
            queenning(piece);
            }
            return;
        }
    }
    cout << "mossa invalida" << endl;;
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
                }else{
                    ((King*)WK)->isInCheck = false;
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
                }else{
                    ((King*)WK)->isInCheck = false;
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
                }else{
                    ((King*)WK)->isInCheck = false;
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
                }else{
                    ((King*)WK)->isInCheck = false;
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
                }else{
                    ((King*)WK)->isInCheck = false;
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
                }else{
                    ((King*)WK)->isInCheck = false;
                }
            }
        }
    }

}
