#include<stdio.h>
int main(int argc, char const *argv[])
{
    // V V IMP
    //when we assign a pointer to array, it points to first elemtent of it 
    // we can represent elements of an array using pointers 
    // *(arr+i) == arr[i] !!!
    // arr is a pointer of arr[0] , and arr + i is a pointer of arr[i]

    int arr[5]={1,2,3,4,5};
    int i;
    for(i=0;i<5;i++){
        printf("%d\n",&arr[i]);
        printf("%d\n",*(arr+i));
    }
    return 0;
}
