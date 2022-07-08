/*Program to separate a user-inputed floating point number into integer and decimal part, 
then convert each part to binary and display it accordinly */
#include<stdio.h>
//Function declarations
void int_to_bin(int, int[]); //To convert integral part to binary and store in array
void dec_to_bin(float, int[]); //TO convert decimal part to binary and store in array

int last_index_in = 0, last_index_dec = 0; 
/* To store the index last used in the functions of int_to_bin and dec_to_bin respectively, 
which will be helpful in printing only required portions of integer and decimal arrays*/

int main()
{   //Declaring variables to store decimal number, its integral part, and its fractional part
    //Also arrays of size 16 to store binary of integral part and of decimal part 
    int in, in_ar[16],frac_ar[16];
    float num,frac;
    //Taking user input for decimal number
    printf("Enter a decimal number\n");
    scanf("%f", &num);
    //Getting integral and fractional part of number 
    in = (int)(num);
    frac = (float)(num-in);
    //Displaying obtained integer part and fractional part
    printf("Integer part %d\n",in);
    printf("Decimal part %f\n",frac);
    //Calling functions in main()
    int_to_bin(in,in_ar);
    dec_to_bin(frac,frac_ar);
    //Displaying binary equivalent of number
    printf("Binary equivalent: \n");

     //The array has stored it in reverse order, so we must reverse it
    for(int i=(last_index_in-1);i>=0;i--){
        printf("%d",in_ar[i]);
    }
    printf("."); //Printing decimal point in between integer and decimal parts

    //The current order is already the right one, so we print it in that order itself
    for(int i=0;i<last_index_dec;i++){
        printf("%d",frac_ar[i]);
    }
    
    return 0;
}

void int_to_bin(int n,int a[16]){
    static int i=0; //counter variable to move to next element of array
    if (n==0) {
        last_index_in=i;
        return;
    } //Base condition, also last used index is returned when it reaches base condition
    a[i++]=n%2; //Modulo of n with 2 is stored in array and counter is incremented
    int_to_bin(n/2,a); //Recursive condition, it is repeated with (n/2)
}

void dec_to_bin(float f,int b[16]){
    static int j=0; //Counter variable to move to next element of array
    if (j==16) {
        last_index_dec=16;
        return;
        }  //Terminate when array is full, if base condition is not fulfilled by then, and in this case last index=16
    int in = (int)(2*f); //Storing integer part of 2*f
    b[j++] = in; //This integer part is stored in array, and counter is incremented
    float d = (float)(2*f-in); //Storing fractional part of 2*f
    if(d==0) {
        last_index_dec=j;
        return;
    } //Base condition, also last used index is returned when it reaches base condition
    dec_to_bin(d,b); //Recursive condition, it is repeated with fractional part of 2*f
}
