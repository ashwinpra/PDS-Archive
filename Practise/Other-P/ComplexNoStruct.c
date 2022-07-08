#include <stdio.h>
int main(int argc, char const *argv[])
{
    struct complex{
        float real; 
        float imag;
    };

    struct complex c1,c2,c3;
    printf("Enter real and imaginary part of first complex number\n");
    scanf("%f %f",&c1.real,&c1.imag);
    printf("Enter real and imaginary part of second complex number\n");
    scanf("%f %f",&c2.real,&c2.imag);
    c3.real = c1.real + c2.real;
    c3.imag = c1.imag + c2.imag;
    printf("Sum is: %0.1f + %0.1f i",c3.real,c3.imag);

    return 0;
}
