#include<stdio.h>
int FindRotationCount(int *A, int n);

int main(){
    int A[] = {12,33,43,56,73,2,5,7,8,10};
    int n = sizeof(A) / sizeof(A[0]);
    int count = FindRotationCount(A,n);
    printf("The array is rotated %d times\n", count); // 5

    return 0;
}
// This is a variation of Binary Search to find how many times sorted array(unique elemnts) rotated:

// No duplicates is a condition in this circularly sorted array
// Pivot proprety -> next and prev are both greater.
// ex. 12,33,43,56,73,2,5,7,8,10 -> 2 is the Pivot 
int FindRotationCount(int a[], int n){
int low = 0, high = n - 1 ;

while (low <= high){
    int mid = (low+high)/2;
    if(a[low] < a[high]){ // case 1
        return low;
    }
    int next = (mid+1) % n, prev = (mid+n-1) % n;
    if (a[mid] < a[prev] && a[mid] < a[next]){ // case 2
        return mid;
    }
    // case 3 : the pivot will be in lower portion
    else if(a[mid] < a[high]) high = mid - 1;
    // case 4 the pivot will be in higher portion 
    else if(a[mid] > a[low]) low = mid + 1; 
}
return -1;

}