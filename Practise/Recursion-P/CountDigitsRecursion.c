#include<stdio.h>

int countDigits (int n){
    int count;
    if(n!=0) return 1+countDigits(n/10);
    else if (n==0) return 0;

}


int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);    
    printf("Number of digits is %d",countDigits(n));
    return 0;
}
