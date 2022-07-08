#include<stdio.h>
//Program to find nuber of zeroes in a number 
int zeroes(int n){
    if (n<10) return 0;
    if (n%10==0) return (1+zeroes(n/10));
    else return zeroes(n/10);
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    printf("Number of zeroes in n is %d\n",zeroes(n));
    return 0;
}
