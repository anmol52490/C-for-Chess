#include<stdio.h>


//Making a dummy board

void manual_board(){
    int i = 1;
    int j = 1;
    int k = 1;
    for (i; i<9; i++){
        for (j;j<9 ; j++){
            printf("\t %d \t", k);
            k++;
        }
        j = 1;
        printf("\n\n");
    }
}


void show_chess_board(int chessarr[][8], int row, int col){
    int i = 0;
    int j = 0;
    int k = 0;
    for (i;i<row;i++){
        for (j; j<col; j++){
            printf("\t %d \t",chessarr[i][j]);
            // k++;
        }
        j = 0;
        printf("\n");
    }

}


void create_array_board(int chessarr[][8], int row){
    int i = 0;
    int j = 0;

    for(i;i<row;i++){
        for (j;j<row;j++){
            chessarr[i][j]=(i+1)*10+(j+1);
            // printf("\t%d\n",chessarr[i][j]);
        }
        j= 0;
    }
    show_chess_board(chessarr, row, row);
}





int main(){

    int row = 8;
    int col = 8;
    int chessarr[row][col];

    // manual_board();
    create_array_board(chessarr, row);
}

