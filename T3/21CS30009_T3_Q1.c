/* Checks if a no. is narcissistic, ie,
it is equal to sum of its digits each raised to no. of digits */
#include<stdio.h>
#include<math.h>
//Declaring required functions
int isNarcissistic(int); 
int digits(int); //returns no. of digits of number

int main() {
    //Declaring and taking user input for number
    int n;
    printf("Enter number to check: ");
    scanf("%d", &n);

    int numd = digits(n); //using fn to get no. of digits and displaying  it approppriately
    printf("Number of digits = ");
    if(numd%2) printf("odd\n");
    else printf("even\n");

    //displaying approppriate output based on whether or not its narcissistic, using function
    if(isNarcissistic(n)) printf("Number is a Narcissistic number\n");
    else printf("Number is not a Narcissistic number\n");
    return 0;
}

int digits(int n){
    int nd=0; //counter store num of digits by incrementing
    int p = n; //dummy variable for looping

    while(p!=0){
        nd++; //counter incremented in every iterations
        p/=10; //looping statement, everytime digits of no. decreases
    }

    //no. of digits is returned
    return nd;
}

int isNarcissistic(int n){
    int d = digits(n); //using previously made fn. to get no. of digits
    int narcsum=0; //counter to store sum of digits raised to power
    int q=n; //dummy variable for looping

    while(q!=0){
        narcsum += pow(q%10,d); //adding to narcsum each digit raised to no. of digits
        //^digit is obtained by taking modulo with 10 
        q/=10; //looping statement, everytime digits of no. decreases and moves to next digit
    }
    //now checking if condition is satisfied and returning approppriate value
    if(narcsum==n) return 1;
    else return 0;
}
