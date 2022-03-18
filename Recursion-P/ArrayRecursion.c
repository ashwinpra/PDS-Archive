#include<stdio.h>

int findMax(int a[], int n){
    int temp;
    if (n==1) return a[0]; 
    temp = findMax(a,n-1);
    if(a[n-1]>temp) return a[n-1];
    else return temp;
}

int main(){
    int ar[] = {1,2,3,4,5,6,7,8,9};
    printf("max is %d\n",findMax(ar,9));


    return 0;
}