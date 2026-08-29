#include <stdio.h>
#include <stdbool.h>
#include "headers.h"

void valid_moves(square S[][8], int from, int to)
{
    int from_row;
    int from_col;
    int to_row;
    int to_col;
    int from_piece = 0;
    int diff;
    int from_color;
    // int from_piece;
    int to_color;
    int to_piece;

    printf("checking which piece is it? for position %d to position %d\n", from, to);

    from_row = from / 10;
    from_col = (from - from_row * 10);

    printf("The piece is: %s\n", piece_list[S[from_row][from_col].data.piece]);
    printf("From row and From col is : %d %d \n", from_row, from_col);
    to_row = to / 10;
    to_col = (to - to_row * 10);
    printf("To row and to col is : %d %d \n", to_row, to_col);
    diff = to - from;
    from_color = S[from_row][from_col].data.color;
    from_piece = S[from_row][from_col].data.piece;
    to_color = S[to_row][to_col].data.color;
    to_piece = S[to_row][to_col].data.piece;

    int i;
    printf("the diff is %d\n", diff);

    switch (from_piece)
    {

    // pawn piece
    case 1:

    {
        bool to_en = S[to_row][to_col].data.metadata.pawnmetadata.enpassant;
        bool from_en = S[from_row][from_col].data.metadata.pawnmetadata.enpassant;
        bool from_pd = S[from_row][from_col].data.metadata.pawnmetadata.pawndouble;
        bool to_pd = S[to_row][to_col].data.metadata.pawnmetadata.pawndouble;

        printf("\n The piece is pawn\n");
        if (((diff == 10 || diff == 20) || (diff == -10 || diff == -20)) && to_piece == 0)
        {
            printf("The pawn move is valid for straight move\n");

            if (((to > from) && from_color == 0) || ((to < from) && from_color == 1))
            {
                // moving straight
                printf("moving straight\n");

                if (diff == 10 || diff == -10)
                {
                    printf("moving 1 step\n");
                    S[from_row][from_col].data.metadata.pawnmetadata.enpassant = 0;
                    S[from_row][from_col].data.metadata.pawnmetadata.pawndouble = 0;
                }
                else if (S[from_row][from_col].data.metadata.pawnmetadata.pawndouble == 1)
                {
                    printf("moving 2 step\n");
                    S[from_row][from_col].data.metadata.pawnmetadata.pawndouble = 0;
                    S[from_row][from_col].data.metadata.pawnmetadata.enpassant = 1; // enpassant activate
                }
                else
                {
                    printf("invalid pawn move\n");
                    break;
                }

                S[to_row][to_col].data = S[from_row][from_col].data;
                S[from_row][from_col].data = empty;
            }
        }

        // capturing diagonal pawn
        else if (((diff == 9 || diff == 11) || (diff == -9 || diff == -11)) && to_piece > 0 && (from_color != to_color))
        {
            S[from_row][from_col].data.metadata.pawnmetadata.pawndouble = 0;
            printf("Pawn move is valid for capturing diagonal\n");
            S[to_row][to_col].data = S[from_row][from_col].data;
            S[from_row][from_col].data = empty;
            S[to_row][to_col].data.metadata.pawnmetadata.enpassant = 0;
        }

        // en-passant
        else if (((from_color == 0 && to_color == 1 && to_en) || (from_color == 1 && to_color == 0 && from_en)))
        {
            // white
            printf("Pawn move is valid for enpassant\n");
            if (from_color == 1 && S[to_row - 1][to_col].data.piece == 0)
            {
                S[from_row][from_col].data.metadata.pawnmetadata.pawndouble = 0;
                printf("white enpassanting black\n");
                S[to_row - 1][to_col].data = S[from_row][from_col].data;
                S[from_row][from_col].data = empty;
                S[to_row - 1][to_col].data.metadata.pawnmetadata.enpassant = 0;
            }
            // black
            else if (from_color == 0 && S[to_row + 1][to_col].data.piece == 0)
            {
                S[from_row][from_col].data.metadata.pawnmetadata.pawndouble = 0;
                printf("black enpassanting white");
                S[to_row + 1][to_col].data = S[from_row][from_col].data;
                S[from_row][from_col].data = empty;
                S[to_row - 1][to_col].data.metadata.pawnmetadata.enpassant = 0;

                printf("valid pawn move \n");
            }
        }

        else
        {
            printf("Invalid pawn move\n");
        }
        break;
    }
    // THE ROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOK
    case 2:
    {
        printf("The piece is rooook\n");
        if (from_row == to_row) //horizontal movement
        {
            printf("the from_col: %d == to_col: %d\n",from_col,to_col);
            if (from_col > to_col)  //right to left
            {
                printf("right to left\n");
                for (i = from_col-1; i > to_col; i--)
                {
                    if (S[from_row][i].data.piece == 0);
                    else //something blocks the rook
                    {
                        printf("invalid rook move\n");
                        goto invalid_move;
                    }
                }
            }

            if (from_col < to_col) //left to right
            {
                printf("left to right\n");
                for (i = from_col+1; i < to_col; i++)
                {
                    if (S[from_row][i].data.piece == 0);
                    else //something blocks the rook
                    {
                        printf("invalid rook move\n");
                        goto invalid_move;
                    }
                }
            }
            S[to_row][to_col].data = S[from_row][from_col].data;
            S[from_row][from_col].data = empty;
            S[to_row][to_col].data.metadata.rookmetadata.rookcastle = 0;

        }
        else if (from_col == to_col) //vertical movement
        {
            printf("the from_row: %d == to_row: %d\n",from_row,to_row);
            if (from_row > to_row) //down to up 
            {
                printf("down to up\n");
                for (i = from_row-1; i > to_row; i--)
                {
                    if (S[i][from_col].data.piece == 0){
                    printf(" %d %d after if\n",i, to_col);
                }
                    else
                    {
                        printf("inside else\n");
                        printf("invalid rook move\n");
                        goto invalid_move;
                    }
                }
            }

            else if (from_row < to_row) //up to down
            {
                printf("up to down\n");
                for (i = from_row+1; i < to_row; i++)
                {
                    if (S[i][from_col].data.piece == 0);
                    else
                    {
                        printf("invalid rook move\n");
                        goto invalid_move;
                    }
                }
                
            }
            S[to_row][to_col].data = S[from_row][from_col].data;
            S[from_row][from_col].data = empty;
            S[to_row][to_col].data.metadata.rookmetadata.rookcastle = 0;
        }
    }
    invalid_move:
    break;
    }
}

void struct_board(square S[][8])
{
    int pieces_initial[8][8] =
        {
            {2, 3, 4, 5, 6, 4, 3, 2},
            {1, 1, 1, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1},
            {2, 3, 4, 5, 6, 4, 3, 2},
        };

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            S[i][j].data=empty;
            S[i][j].data.piece = pieces_initial[i][j];

            if (i == 0 || i == 1)
            {
                S[i][j].data.color = 0;
            }
            else if (i == 6 || i == 7)
            {
                S[i][j].data.color = 1;
            }
            else
            {
                S[i][j].data.color = 2;
            }

            if (S[i][j].data.piece==PAWN){
                S[i][j].data.metadata.pawnmetadata.enpassant = 0;
                S[i][j].data.metadata.pawnmetadata.pawndouble = 1;
            }
            
            else if(S[i][j].data.piece==ROOK){
                S[i][j].data.metadata.rookmetadata.rookcastle = true;
                
            }

            
            
        }
    }
}

void view_board(square S[][8])
{
    int j = 0;
    printf("\n");
    for (int i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("\t%d  %s\t", S[i][j].data.color, piece_list[S[i][j].data.piece]);
        }
        j = 0;
        printf("\n");
    }
}

int main()
{

    int row = 8;
    int col = 8;

    int from = 0;
    int to = 0;
    square S[8][8];

    struct_board(S);
    view_board(S);

    do
    {

        printf("\nMoving pieces: Tell FROM which position TO which position you want to move?\n");
        printf("Give both position in range of 11 to 88: ");

        scanf("%d", &from);
        scanf("%d", &to);
        printf("%d \t %d\n", from, to);
        from = from - 11;
        to = to - 11;

        valid_moves(S, from, to);
        view_board(S);
    } while (1);
}
