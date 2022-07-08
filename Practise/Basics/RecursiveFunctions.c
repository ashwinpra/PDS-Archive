#include <stdio.h>
int factorial(int n)
{

    if (n == 1 || n == 0)
        return 1; //this is base case
    else
        return n * factorial(n - 1); // this is recurrence
}
int main(int argc, char const *argv[])
{
    int num;
    printf("Enter number whose factorial you want to find:\n");
    scanf("%d", &num);
    printf("%d! is %d", num, factorial(num));
    return 0;
}
