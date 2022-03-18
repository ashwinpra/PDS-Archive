#include<stdio.h>

void copy(int a[],int b[],int n){
    b[n]=a[n];
    if (n==5) return;
    copy(a,b,n+1);
}
int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4,5};
    int b[5];
    copy(a,b,0);
    for(int i=0;i<5;i++){
        printf("%d ",b[i]);
    }
    return 0;
}
