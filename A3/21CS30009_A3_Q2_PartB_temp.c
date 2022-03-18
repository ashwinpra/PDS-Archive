//Program to print first "k" terms of the pattern 4,8,14,22,32 . . . .
//Also to find different between (n+1)th and nth term when n is given


#include<stdio.h>
#include<math.h>
int main(){
    //Declaring required variables, also pattern which will store each term in pattern 
    int k,n,pattern;
    //Taking user input for above variables
    printf("k: ");
    scanf("%d",&k);
    printf("n: ");
    scanf("%d",&n);

    //looping from 1 to k and printing the corresponding term in pattern
    for(int i=1;i<=k;i++){
        pattern = pow(i,2)+i+2;
        printf("%d ",pattern);
    }
    return 0;
}