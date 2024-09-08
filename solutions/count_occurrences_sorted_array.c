#include <stdio.h>
#include <stdbool.h>

// A:array. n:size of array. x: the target integer. searchFirst: flag to swap between first/last occurrence
// This is a variation of BinarySearch algorithm to count frequences
int BinarySearch(int* A,int n,int x, bool searchFirst);


int main(){
    int x;
    printf("Enter the number you want to count: ");
    scanf("%d",&x);
    // Aarray must be sorted as prerequest.
    int A[] = {1,2,3,4,4,4,5,5,6};

    int firstIndex = BinarySearch(A,sizeof(A)/sizeof(A[0]),x,true);
    if(firstIndex == -1){
        printf("Count of %d is %d\n", x, 0);
    }else{

    int lastIndex = BinarySearch(A,sizeof(A)/sizeof(A[0]),x,false);
    printf("The count of number %d is :%d\n" ,x, (lastIndex - firstIndex) + 1);
    }
    return 0;
}
// Variation of finding first/last occurence using flag(searchFirst)
 int BinarySearch(int* A,int n,int x, bool searchFirst){

    int L = 0 , R = n - 1, result = -1;

    while (L <= R) {

    int mid = (L + R) / 2;
    if (A[mid] > x){
        R = mid - 1;
    }
    else if (A[mid] < x){
        L = mid + 1;
    } else{
        if(searchFirst){
        result = mid;
        // Go on searching towards left (lower indices)
        R = mid - 1;
        }else{
        result = mid;
        // Go on searching towards right (higher indices)
        L = mid + 1;
        }
    }

    }
    return result;

 }
