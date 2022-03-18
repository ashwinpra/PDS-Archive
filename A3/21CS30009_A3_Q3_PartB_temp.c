//To print "n" terms of a summation and find their sum ("x")
//General term: (n*(n+1))^3/(n*(n+1)*(n+n+1))^2 = n*(n+1)/(2n+1)^2
//Also to check whether the floor of x multiplied with "k" is prime or not
#include<stdio.h>
#include<math.h>

int main(){
    //Declaring required variables
    //pattern for storing corresponding term of summation
    int n,k;
    float x=0;
    //Taking user input for n and k 
    printf("n=");
    scanf("%d",&n);
    printf("k=");
    scanf("%d",&k);

    //looping from 1 to n and adding corresponding terms of summation to x
    for(int i=1;i<=n;i++){
        x+=(float)((i*(i+1))/(pow((2*i+1),2)));
    }
    //Displaying value of x upto 3 decimal places 
    printf("%0.3f\n",x);


    return 0;
}