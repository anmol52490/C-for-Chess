#include<stdio.h>


#Making a dummy board

int main(){
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

