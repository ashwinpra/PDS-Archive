/*Program to print first "k" terms of the pattern 4,8,14,22,32 . . . .
Also to find different between (n+1)th and nth term when "n" is given

Logic behind pattern: The difference between consecutive terms are in Arithmetic Progression (4,6,8...)
Such pattern will have nth term of the form an^2+bn+c
We can find a,b,c by substituting 1st term = 4, 2nd term = 8, 3rd term = 14
nth term: n^2 + n + 2 */
#include<stdio.h>
#include<math.h>

int main(){
    //Declaring required variables, also pattern which will store corresponding term in pattern every iteration
    int k,n,pattern;
    //Taking user input for above variables
    printf("k: ");
    scanf("%d",&k);
    printf("n: ");
    scanf("%d",&n);

    //looping from 1 to k and printing the corresponding term in pattern
    for(int i=1;i<=k;i++){
        //Printing "i"th term of pattern, separated by a space
        pattern = pow(i,2)+i+2;
        printf("%d ",pattern);
    }
    // (n+1)th term - nth term = 2n+2
    printf("\nDifference between %dth and %dth term: %d",(n+1),n,(2*n+2));

    return 0;
}
