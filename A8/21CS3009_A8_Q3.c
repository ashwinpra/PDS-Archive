/*
Input a string and it is encrypted following given steps: 
1) each character is typecasted to int and converted to 8 bit binary
2) each 6 bits of concatenated binary number obtained following 1) is converted to char, 
   0 => A, 1=> B.... 25 => Z
   26 => a, 27 => b, ... 51 =>z
   52 => 0 , 53 =>1, ... 61/62/63 => 9
 */
#include<stdio.h>
#include<math.h>
#include<string.h>
//Declaring required functions (uses written above functions after main)
void binaryToStr(int*, int, char*);
void charToBinary(char, int,int*);
void strToBinary(char*, int*);

int main() {
    //declaring and taking user input for string 
    //also declaring string to store encrypted string
    char str[200],enc[200];
    //declaring integer array to store binary representation
    int bin[1600];
    printf("Enter string to encrypt: ");
    scanf("%[^\n]s",str);
    //Running required functions
    strToBinary(str,bin);
    binaryToStr(bin,8*strlen(str),enc);
    
    return 0;
}

//converts char to binary and stores digits one by one in array, used in strToBinary function
//parameters: char, starting index (to store in integer array), integer array
void charToBinary(char c,int start, int* a){
    //typecasting character to get ascii value 
    int n = (int)c;
    int i = start; //declaring "i" which will be used for looping
    int bitcount=0; //to keep track of number of bits
    while(n!=0){
        //converting to binary and storing in array 
        *(a+i--) = n%2;
        n/=2;
        bitcount++;
    }
    //if number is not 8 bits yet, we add 0s to the start to make it 8 bits 
    while(n==0 && bitcount<8){
        *(a+i--) = 0;
        bitcount++;
    }
}
//converts string to binary by converting each char to binary and storing in array 
//parameters: string, int array to store binary
void strToBinary(char* s, int* a){
    int j=7; //starting index of initial binary (such that we get 8 places)
    //looping through characters of string and converting them to binary using charToBinary
    for (int i = 0; *(s+i) != '\0';i++)
    {
    charToBinary(*(s+i),j,a);
    j+=8; //index incremented by 8 to get 8 more places for new binary
    }
}
//to convert integer array to string using given guidelines
//parameters: int array, size of int array, string in which encrypted string is stored
void binaryToStr(int* a, int size, char *s){

    int power = 5; //for power when converting to decimal
    int j=0; //for index of string
    int num=0; //to store decimal equivalent of each 6 bits
    char c; //will store character obtained by converting each binary
    while(size%6!=0){
        a[size++]=0;
    } //to add trailing zeroes such that size is a multiple of 6, ie all 6 bits can be obtained

    //looping through integer array 
    for (int i = 0; i < size; i++)
    {
        //converting each digit to decimal by multiplying by 2^power (power is decremented every step till 0)
        num+=(int)(a[i]*pow(2,power--));
        //when done with 6 bits, or if end of array is reached
        //we are checking -1 instead of 0 because it was decremented by 1 again 
        if(power==-1){
            power=5; //value of power is reset 
            //obtained number is converted to char following given rules and added to string
            /* note: ascii value of A -> 65
                ascii value of a -> 97
                ascii value of 0 -> 48
            so accordingly we shift the value and typecast */
            if(num>=0 && num<=25) c = (char)(num+65); //uppercase
            else if(num>=26 && num <=51) c = (char)(num+71); //lowercase
            else if(num>=52 && num<=61) c = (char)(num-4); //numbers 
            else if(num==62 || num==63) c = '9'; //2 extra cases to be considered as 9 itself
            *(s+j++) = c;
            num=0; //value of num is reset 
        }
    } 
    s[j] = '\0'; //adding null character at end to complete string
    printf("%s",s); //displaying string
}

