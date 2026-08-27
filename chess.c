#include<stdio.h>
#include<stdbool.h>


typedef enum {NONE, PAWN, ROOK, KNIGHT, BISHOP, KING, QUEEN} PIECE;

typedef enum  {BLACK, WHITE, NONES} COLOR;

typedef enum {FALSE, TRUE} ENPASSANT;

// typedef enum {TRUE, FALSE} PAWNDOUBLE;


typedef struct{
     PIECE piece;
     COLOR color;
     ENPASSANT enpassant;
    //  PAWNDOUBLE pawndouble;
}square;

const char* piece_list[] ={
    " ",
    "P",
    "R",
    "K",
    "B",
    "Ki",
    "Q"
};


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

    printf("checking which piece is it? for position %d to position %d\n",from,to);
    
    from_row = from/10;
    from_col = (from - from_row*10);

    printf("The piece is: %s\n",piece_list[S[from_row][from_col].piece]);
    printf("From row and From col is : %d %d \n",from_row,from_col);
    to_row = to/10;
    to_col = (to - to_row*10);
    printf("To row and to col is : %d %d \n",to_row,to_col);
    diff = to-from;
    from_color = S[from_row][from_col].color;
    from_piece = S[from_row][from_col].piece;
    to_color = S[to_row][to_col].color;
    to_piece = S[to_row][to_col].piece;
    bool to_en = S[to_row][to_col].enpassant;
    bool from_en = S[from_row][from_col].enpassant;
    
    int i;
    printf("the diff is %d",diff);

    switch(from_piece){

        // pawn piece
        case 1:
            
            printf("\n The piece is pawn\n");

            if(((diff==10 || diff==20) || (diff==-10 || diff==-20)) && to_piece==0){
                printf("The pawn move is valid for straight move\n");
            
                if (((to>from) && from_color==0 ) || ((to<from) && from_color==1)){
                //moving straight
                printf("moving straight\n");
                
                    if (diff == 10 || diff ==-10){
                        printf("moving 1 step\n");
                        S[to_row][to_col].enpassant=0;
                        
                    }
                    else{
                        printf("moving 2 step\n");
                        S[to_row][to_col].enpassant=1; //enpassant activate
                    }
                    S[to_row][to_col].piece = 1;
                    S[from_row][from_col].piece=0;
                    S[from_row][from_col].color=2;
                    S[to_row][to_col].color=from_color;
                }
            }

                //capturing diagonal pawn
            else if(((diff==9 || diff==11) || (diff=-9 || diff==-11)) && to_piece>0 && (from_color!=to_color)){
                    printf("Pawn move is valid for capturing diagonal\n");
                    S[to_row][to_col].piece = from_piece;
                    S[to_row][to_col].color = from_color;
                    S[from_row][from_col].piece = 0;
                    S[from_row][from_col].color = 2;
                    S[to_row][to_col].enpassant=0;
                    
                }

                //en-passant
            else if(((from_color==0 && to_color==1 && to_en)||(from_color==1 && to_color==0 && from_en))){
                    // white 
                    printf("Pawn move is valid for enpassant\n");
                        if (from_color==1 && S[to_row-1][to_col].piece==0){
                            printf("white enpassanting black\n");
                            S[to_row-1][to_col].piece = from_piece;
                            S[to_row-1][to_col].color = from_color;
                            S[to_row][to_col].piece = 0;
                            S[to_row][to_col].color = 2;
                            S[from_row][from_col].piece = 0;
                            S[from_row][from_col].color = 2;
                            S[to_row-1][to_col].enpassant = 0;
                           
                        }
                    // black
                        else if(from_color==0 && S[to_row+1][to_col].piece==0){
                            printf("black enpassanting white");
                            S[to_row+1][to_col].piece = from_piece;
                            S[to_row+1][to_col].color = from_color;
                            S[to_row][to_col].piece = 0;
                            S[to_row][to_col].color = 2;
                            S[from_row][from_col].piece = 0;
                            S[from_row][from_col].color = 2;
                            S[to_row-1][to_col].enpassant = 0; 

                            printf("valid pawn move \n");
                        }

                }
            
            else{
                printf("Invalid pawn move");
            }
    

        // THE ROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOK
        case 2:
            printf("The piece is rooook");
            if(from_row==to_row){
                if(from_col>to_col){
                    for(i=from_col;i>to_col;i--){
                        if (S[from_row][i].piece==0);
                        else {
                            printf("invalid rook move\n");
                            break;
                    }
                }
            }

            if(from_col<to_col){
                    for(i=from_col;i<to_col;i++){
                        if (S[from_row][i].piece==0);
                        else {
                            printf("invalid rook move\n");
                            break;
                    }
                }
            }
            }
            else if(from_col==to_col){
                if(from_row>to_row){
                            for(i=from_row;i>to_col;i--){
                                if (S[i][from_col].piece==0);
                                else {
                                    printf("invalid rook move\n");
                                    break;
                            }
                        }
                    }

                else if(from_row<to_row){
                            for(i=from_row;i<to_row;i++){
                                if (S[i][from_col].piece==0);
                                else {
                                    printf("invalid rook move\n");
                                    break;
                            }
                        }
                    }
        }
    }
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
    int j=0;
    printf("\n");
    for(int i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("\t%d  %s\t",S[i][j].color,piece_list[S[i][j].piece]);
        }
        j=0;
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
    view_board(S);

    do{

    printf("\nMoving pieces: Tell FROM which position TO which position you want to move?\n");
    printf("Give both position in range of 11 to 88: ");
    
    scanf("%d",&from);
    scanf("%d",&to);
    printf("%d \t %d\n",from,to);
    from = from-11;
    to = to-11;

    valid_moves(S,from,to);
    view_board(S);
    }while(1);
}

