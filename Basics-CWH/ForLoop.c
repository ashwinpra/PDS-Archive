#include<stdio.h>
int main(int argc, char const *argv[])
{
    //expression 1  (here, x=0) is optional
    // we can have more than 1 initialisiation in expression 1 
    // expression 2 (here, x<=num) is also optional
    // it can have more than 1 condition, but loop will iterate until last condition becomes false. other conditions will be treated as statements
    // can perform task of exp 1 and 3 also (initialsiation/updating loop variable)
    // expression 3 (here, i++) is also optional
    // we can update multiple variables with it  
    int x;
    int num;
    printf("Enter upper limit:\n");
    scanf("%d",&num);
    for(x=0; x<=num; x++){
        printf("%d\n",x);
    }
    return 0;
}
