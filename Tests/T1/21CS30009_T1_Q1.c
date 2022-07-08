//Program to take 2 binary numbers from user (error if not binary), 
//and they must have same number of bits (otherwise error), then perform bitwise XOR operation
#include<stdio.h>

int main(){
    //Declaring the two binary numbers
    //t1,t2 are temp variables to check digits and no. of digits of n1,n2
    long long int n1,n2,t1,t2;
    //count1,count2 stores no. of digits, digit1,digit2 store digits 
    int count1=0,count2=0,digit1,digit2;
    //Taking user input for the two binary numbers
    scanf("%lld",&n1);
    scanf("%lld",&n2);
    //storing n1,n2 in t1,t2 in order to count digits
    t1=n1;
    t2=n2;

    //while loop for counting no. of digits as well as checking digits
    while(t1!=0 || t2!=0){
        if (t1!=0) {
            count1+=1;
            digit1=t1%10;
        }
        if (t2!=0) {
            count2+=1;
            digit2=t2%10;
        }
        //dividing by 10 in order to move on to next digit
        t1/=10;
        t2/=10;
        //checking whether numbers are binary by checking if digits are 1 or 0
        //if not, display error and exit from program
        if(digit1!=0 && digit1!=1) {
            printf("Error");
            return 0;
        }
        else if (digit2!=0 && digit2!=1) {
            printf("Error");
            return 0;
        }
    }
    //proceeding for bitwise XOR operation if bits are equal
    if (count1==count2){
        while(n1!=0 || n2!=0){
            //getting digits of n1,n2 one by one
            if(n1!=0){
                digit1=n1%10;
            }
            if(n2!=0){
                digit2=n2%10;
            }
            //dividing by 10 in order to move on to next digit
            n1/=10;
            n2/=10;
            //if they are equal, result is 0, otherwise 1
            if(digit1==digit2) printf("0");
            else printf("1"); 
        }
    }
    //showing error and exiting from program if bits are not equal
    else if (count1!=count2) {
        printf("Error");
        return 0;
    }

    return 0;
}