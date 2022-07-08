#include<stdio.h>
#include<math.h>
//Declaring required functions
int isNarcissistic(int); 
int digits(int); //returns no. of digits of number

int main() {
    int n;
    printf("Enter number to check: ");
    scanf("%d", &n);
    int numd = digits(n); //using fn to get no. of digits
    printf("Number of digits = ");
    //displaying approppriate output based on no. of digits
    if(numd%2) printf("odd\n");
    else printf("even\n");
    //displaying approppriate output based on whether or not its narcissistic
    if(isNarcissistic(n)) printf("Number is a Narcissistic number\n");
    else printf("Number is not a Narcissistic number\n");
    return 0;
}

int digits(int n){
    int nd=0; //variable to store num of digits by incrementing
    int p = n; //dummy variable for looping
    while(p!=0){
        nd++;
        p/=10;
    }
    return nd;
}

int isNarcissistic(int n){
    int d = digits(n); //using previously made fn.
    int narcsum=0; //variable to store sum of digits raised to power
    int q=n; //dummy variable for looping
    while(q!=0){
        narcsum += pow(q%10,d); //adding to narcsum each digit raised to no. of digits
        q/=10;
    }
    //now checking if condition is satisfied
    if(narcsum==n) return 1;
    else return 0;
}
