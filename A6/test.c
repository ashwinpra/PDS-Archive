//Function to separate a floating point number into integer and decimal part, then convert each to binary
#include<stdio.h>
//Function declaration
void int_to_bin(int, int[]); //keep dividing by 2
void dec_to_bin(float, int[]); //keep multiplying by 2

int main()
{   //Declaring variables to store decimal number, its integral part, and its fractional part, with approppriate type
    //Also arrays of size 16 to store binary of integral part and of decimal part 
    int in, in_ar[]={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},frac_ar[]={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    float num,frac;
    //Taking user input for decial number
    printf("Enter a decimal number: ");
    scanf("%f", &num);
    //Getting integral and fractional part of number 
    in = (int)(num);
    frac = (float)(num-in);
    //Displaying obtained integer part and fractional part
    printf("Integer part %d\n",in);
    printf("Decimal part %f\n",frac);
    //Displaying binary equivalent of number
    printf("Binary equivalent: \n");
    //Calling functions in main()
    int_to_bin(in,in_ar);
    dec_to_bin(frac,frac_ar);
    int count=0;
    for(int i=15;i>=0;i--){
    //The array has stored it in reverse order, so we must reverse it
        if (in_ar[i]==1 || in_ar[i]==0) printf("%d",in_ar[i]);
    }
    printf(".");
    for(int i=0;i<16;i++){
          if (frac_ar[i]==1 || frac_ar[i]==0) printf("%d",frac_ar[i]);
    }

    return 0;
}

void int_to_bin(int n,int a[16]){
    static int i=0;
    if (n==0) return;
    a[i++]=n%2;
    int_to_bin(n/2,a);
}

void dec_to_bin(float f,int b[16]){
    static int j=0;
    if (j==16) return;
    int in = (int)(2*f);
    b[j++] = in;
    float d = (float)(2*f-in);
    if(d==1 ) return;
    dec_to_bin(d,b);
}
