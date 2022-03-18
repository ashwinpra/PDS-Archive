#include<stdio.h>

int fact(int n){
    int val=1,count=0;
    if(n>1) val = n*fact(n-1);
    //it goes on until it reaches fact(1), then only the bottom code is implemented, then it keeps 
    //going back
    count++;
    printf("count = %d, n = %d\n",count,n);
    return val;
}

int main(){
    int x;
    scanf("%d",&x);
    printf("%d",fact(x));
    return 0; 
}