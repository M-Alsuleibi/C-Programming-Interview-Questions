#include<stdio.h>
// m: #rows, n: # colm
void SpiralOrder(int m, int n, int matrix[m][n]);

int main(){
    
    int matrix[4][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9},
                        {10,11,12}};
    SpiralOrder(4,3,matrix); // output: 1 2 3 6 9 12 11 10 7 4 5 8
    return 0;
}
// Print in spiral order

// m, n must be passed before the 2D array to avoid 
//expression must be a pointer to a complete object typeC/C++ ERROR
void SpiralOrder(int m, int n, int matrix[m][n])
{
    //Set boundries of the matrix 
    // top, left, right, bottom respectivly
    int T = 0, L =0, R = n - 1, B = m - 1;
    //directions: right : 0, down : 1, left : 2, up : 3
    int direction = 0;
    while(L <= R && T <= B){
    if(direction == 0){
        for (int i = L; i<=R; i++){
            printf("%d ",matrix[T][i]);
        }
        T ++ ;
        // direction ++;
    }    
    else if(direction == 1){
        for (int i = T; i <= B; i++){
            printf("%d ",matrix[i][R]);
        }
        R -- ;
        // direction ++;
    }    
    else if(direction == 2){
        for (int i = R; i>=R; i--){
            printf("%d ",matrix[B][i]);
        }
        B -- ;
        // direction ++;
    }    
    else if(direction == 3){
        for (int i = B; i >= T; i--){
            printf("%d ",matrix[i][L]);
        }
        L ++ ;
        // direction ++;
    }    
    direction = (direction + 1) % 4;
    }
    printf("\n");
}
