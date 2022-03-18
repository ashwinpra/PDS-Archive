/*Program to check whether 2 numbers are a Zazzy pair, conditions for which are:
1: They have same length, and this length is even
2: The number formed by digits of first half of first number (MSB) = Number formed by reverse of 
digits of second half of secondnumber (LSB) 
*/
#include<stdio.h>
#include<math.h>
//Function declarations
int digitCount(int);
int reverseNum(int);
int checkDigit(int, int);
int isZazzy(int, int);

int main(){
    //Declaring 2 numbers and taking user input for them
    int n1,n2;
    printf("Number 1 = ");
    scanf("%d",&n1);
    printf("Number 2 = ");
    scanf("%d",&n2);
    //Checking if both required conditions are satisfied
    if(checkDigit(n1,n2)==1 && isZazzy(n1,n2)==1) printf("Zazzy pair");
    else printf("Not a Zazzy pair");
    return 0;
}
//Function to count digits of a number
int digitCount(int n){
    //Variable to store number of digits
    int d=0;
    while(n!=0){
    //no. of digits is incremented and number divided by 10 until it becomes 0 (ie all digits are counted)
        n/=10;
        d++;
    }
    //d (no. of digits) is returned
    return d;
}
//Function to reverse a number
int reverseNum(int n){
    int dig,num=0,i=1;
    //digits of n obtained using previously defined fn
    int dn = digitCount(n);
    while(n!=0){
        //each digit(dig) is found, and it is added by multiplying with corresponding decimal index power
        dig = n%10;
        num+=dig*pow(10,(dn-i));
        n/=10;
        i++;
    }
    //num (reverse of original no.) is returned
    return num;
}
//Function to check if digits of 2 numbers are equal and length is even (ie, condition 1)
int checkDigit(int a,int b){
    //digits of a and b obtained using previously defined fn
    int da=digitCount(a);
    int db=digitCount(b);
    //checking if digit counts are same and even
    if(da==db && da%2==0) return 1;
    else return 0;
}
//Function to check condition 2
int isZazzy(int a,int b){
    int msb=0,lsb=0,digit;
    //digits of a and b obtained using previously defined fn
    int da=digitCount(a);
    int db=digitCount(b);
    //msb is found by getting floor of number / 10^(d/2)
    msb = (int)(a/(pow(10,(da/2))));
    //lsb is found by reversing the last half (b_end), which is modulo of number with 10^(d/2) 
    int b_end = (int)(b%(int)((pow(10,(db/2)))));
    //reversed using previously defined fn
    lsb = reverseNum(b_end);
    
    //checking if they are both equal
    if (msb==lsb) return 1;
    else return 0;
}