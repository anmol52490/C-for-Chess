#include<stdio.h>
#include<stdbool.h>


typedef enum {NONE, PAWN, ROOK, KNIGHT, BISHOP, KING, QUEEN} PIECE;

typedef enum  {BLACK, WHITE, NONES} COLOR;

typedef enum {FALSE, TRUE} ENPASSANT;


typedef struct{
     PIECE piece;
     COLOR color;
     ENPASSANT enpassant;
}square;


void valid_moves(square S[][8], int from, int to){
    int from_row;
    int from_col;
    int to_row;
    int to_col;
    int from_piece;
    int diff;
    int from_color;
    // int from_piece;
    int to_color;
    int to_piece;

    printf("checking which piece is it? for position %d",from);
    from_row = from/10;
    from_col = (from - from_row)/10;
    printf("From row and From col is : %d %d",from_row,from_col);
    to_row = to/10;
    to_col = (to - to_row)/10;
    diff = to-from;
    from_color = S[from_row][from_col].color;
    from_piece = S[from_row][from_col].piece;
    to_color = S[to_row][to_col].color;
    to_piece = S[to_row][to_col].piece;
    bool en = S[to_row][to_col].enpassant;


    switch(from_piece){

        // pawn piece
        case 1:
            printf("\n The piece is pawn");
            if (((to>from) && from_color==0 ) ||((to<from) && to_color==1)){
                //moving straight
                if(((diff==10 || diff==20) || (diff=-10 || diff==-10)) && to_piece==0){
                    if (diff == 10 || diff ==-10){
                        S[to_row][to_col].enpassant=0;
                    }
                    else{
                        S[to_row][to_col].enpassant=1; //enpassant activate
                    }
                    to_piece = 1;
                    from_piece=0;
                }

                //capturing diagonal pawn
                else if(((diff==9 || diff==11) || (diff=-9 || diff==-11)) && to_piece==1 && (from_color!=to_color)){
                    to_piece = from_piece;
                    to_color = from_color;
                    from_piece = 0;
                    S[to_row][to_col].enpassant=0;
            
                }

                //en-passant
                else if(en==1  && ((from_color==0 && to_color==1)||(from_color==1 && to_color==0))){
                    // white 
                        if (from_color==1 && (diff>0 || diff<0) && S[to_row-1][to_col].piece==0){
                            S[to_row-1][to_col].piece = from_piece;
                            S[to_row-1][to_col].color = from_color;
                            S[to_row][to_col].piece = 0;
                            S[to_row][to_col].color = 2;

                        }
                    // black
                        else if(from_color==0 && S[to_row+1][to_col].piece==0){
                            S[to_row+1][to_col].piece = from_piece;
                            S[to_row+1][to_col].color = from_color;
                            S[to_row][to_col].piece = 0;
                            S[to_row][to_col].color = 2;
                        }

                }
    }
    };
}


void struct_board(square S[][8]){
    int pieces_initial[8][8] =
    {
        {2,3,4,5,6,4,3,2},
        {1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {2,3,4,5,6,4,3,2},
    };
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            
            S[i][j].piece=pieces_initial[i][j];
            if (i==0 || i==1){
                S[i][j].color = 0;
            }
            else if (i==6 || i==7){
                S[i][j].color=1;
            }
            else{
                S[i][j].color=2;
            }
            S[i][j].enpassant=0;
        }
    }
}


void view_board(square S[][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("\t%d %d\t",S[i][j].color,S[i][j].piece);
        }
        printf("\n");
    }
}

int main(){

    int row = 8;
    int col = 8;
    int chessarr[row][col];
    int from=0;
    int to=0;
    square S[8][8];

    struct_board(S);


    printf("\nMoving pieces: Tell which FROM which position TO which position you want to move?\n");
    printf("Give both position in range of 11 to 88: ");
    
    scanf("%d",&from);
    scanf("%d",&to);
    printf("%d \t %d\n",from,to);
    from = from-11;
    to = to-11;


    valid_moves(S,from,to);
}

