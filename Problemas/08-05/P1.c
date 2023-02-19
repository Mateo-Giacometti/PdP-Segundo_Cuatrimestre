#include <stdio.h>

const int X = 2;
const int Y = 3;

int main(void){
    int mat[X][Y];
    int x = 0, y = 0;

    for (x = 0; x < X; x++){
        for (y = 0; y < Y; y++){
            mat[x][y] = 4;

        }
    }
    return 0;
}