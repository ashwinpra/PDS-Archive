#include<stdio.h>
int main(int argc, char const *argv[])
{
    int x;
    printf("Enter either 2 or 3\n") ;
    scanf("%d", &x);
    // argument for switch is either int or char 
    // case value is also either int or char 
    // case must come inside switch always (obv)
    // "break" is not a must!
    //  hold alt to select multiple lines 
    // ctrl + / to comment line directly 
    switch(x){
        case 2:
        printf ("Value is 2\n");
        break;
        case 3: 
        printf("Value is 3\n");
        break;
        default: // in case none of the other cases are satisfied
        printf("Dont disobey me, inferior being\n");
        break;
    }
    return 0;
}
