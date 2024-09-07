#include <stdio.h>
// A:array. n:size of array. x: the target integer
int find_first(int* A,int n,int x);
int find_last(int A[],int n,int x);

int main(){
    int x = 4;
    int A[] = {1,2,3,4,4,4,5,6};

    int first = find_first(A,8,x);
    int last = find_last(A,8,x);
    printf("The first index that number %d appear is :%d\n" ,x, first);
    printf("The last index that number %d appear is :%d\n" ,x, last);
    return 0;
}
 int find_first(int A[],int n,int x){

    int L = 0 , R = n - 1, result = -1;

    while (L <= R) {

    int mid = (L + R) / 2;
    if (A[mid] > x){
        R = mid - 1;
    }
    else if (A[mid] < x){
        L = mid + 1;
    } else{
        result = mid;
        R = mid - 1;
    }

    }
    return result;

 }

 int find_last(int A[],int n,int x){

    int L = 0 , R = n - 1, result = -1;

    while (L <= R) {

    int mid = (L + R) / 2;
    if (A[mid] > x){
        R = mid - 1;
    }
    else if (A[mid] < x){
        L = mid + 1;
    } else{
        result = mid;
        L = mid + 1;
    }

    }
    return result;

 }