#include<stdio.h>
int CircularlyArraySearch(int* A, int n, int x);
int main(){
    int C[] = {12,14,15,21,0,4,5,8,9,11};
    int x;
    printf("Enter number to search: ");
    scanf("%d", &x);
    int index = CircularlyArraySearch(C,10,x);
    if (index == -1){
        printf("%d is not found\n",x);
    }else{

    printf("The number %d was found at index %d\n",x, index);
    }
    return 0;
}

// This algorithm return the index of searched number x
    int
    CircularlyArraySearch(int *A, int n, int x)
{   int low = 0, high = n - 1;
while(low <= high){
    int mid = (low + high) / 2;
    // Case 1: Found x
    if (A[mid] == x) return mid;

    // Case 2: right half is sorted
    if (A[mid] <= A[high]){
        if(x >= A[mid] && x <= A[high])
        low = mid + 1; // go searching in right sorted half
        else high = mid - 1; // go searching left
    }
    // Case 3: left half is sorted
    else {
        if (x <= A[mid] && x >= A[low])
        high = mid - 1 ; // go searching in left sorted half
        else low = mid + 1;
    }
}

    return -1;
}
