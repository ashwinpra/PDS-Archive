#include<stdio.h>
//Program to find sum of squares of numbers between two numbers, both inclusive

int sumofsquare(int m,int n){
    if (m==n) return m*m;
    else{
        int mid = (m+n)/2;
        return sumofsquare(m,mid) + sumofsquare(mid+1,n);
    }
}
int main(int argc, char const *argv[])
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("Sum of squares between %d and %d is %d",a,b,sumofsquare(a,b));
    return 0;
}
