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
void binaryToStr(int*, int);
void charToBinary(char, int,int*);
void strToBinary(char*, int*);

int main() {
    char str[200];
    int bin[1600];
    int st = 7;
    printf("Enter string to encrypt: ");
    scanf("%[^\n]s",str);
    strToBinary(str,bin);
    for (int i = 0; i < 8*strlen(str); i++) 
    {
        printf("%d",bin[i]);
    }
    binaryToStr(bin,8*strlen(str));
    
    return 0;
}

//converts char to binary and stores digits one by one in array
//parameters: char, starting index (to store in integer array), integer array
void charToBinary(char c,int start, int* a){
    //typecasting character to get ascii value 
    int n = (int)c;
    int i = start; //declaring "i" which will be used for looping
    int bitcount=0;
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
void binaryToStr(int* a, int size){
    int j=0; //for index of string
    int power = 5; //for power when converting to decimal
    int num; //to store decimal equivalent of each 6 bits
    char c; //will store character obtained by converting each binary
    for (int i = 0; i < size; i++)
    {
        num+=(int)(a[i]*pow(2,power));
        power-=1;
        //when done with 6 bits, or if end of array is reached
        if(power==0 || i==size-1){
            power=5; //value of power is reset 
            //obtained number is converted to char following given rules and added to string
            /* note: ascii value of A -> 65
                ascii value of a -> 97
                ascii value of 0 -> 48
            so accordingly we can shift the value and typecast */
            if(num>=0 && num<=25) c = (char)(num+65); //uppercase
            else if(num>=26 && num <=51) c = (char)(num+71); //lowercase
            else if(num>=52 && num<=61) c = (char)(num-4); //numbers 
            else if(num==62 || num==63) c = '9'; //2 extra cases to be considered as 9 itself
            printf("%c",c);
            num=0; //value of num is reset 
        }
    } 
}