//Program to print the nth term of a sequence a_n, where a_n = 2*(a_n-1)+3*(a_n-2), a_0=a_1=1
#include<stdio.h>
//Declaring function
int pattern(int); 

int main()
{
    //Taking user input for n
    int n;
    printf("Enter n: " );
    scanf("%d", &n);
    //Checking if n is out of range, if yes, display error and scan until it is within the range
    while(n>20){
        printf("Out of Range\n");
        scanf("%d", &n);
    }
    //Displaying a_n for corresponding n
    printf("a_%d = %d\n",n,pattern(n));
    return 0;
}

int pattern(int n){
    if (n==0 || n==1) return 1; //Base condition
    else return 2*(pattern(n-1))+3*(pattern(n-2)); //Recursive condition, based on pattern
}