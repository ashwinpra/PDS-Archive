//Program to display reflection complex number about y axis
//Also to compute area of rectangle formed by the line joining complex number and its reflection, and the x axis

#include<stdio.h>

int main()
{
    int re, im, refl_re, refl_im, area;

    //printf and scanf statement to get real and imaginary part of complex number
    printf("Enter real and imaginary part of the complex number:\n");
    scanf("%d %d",&re,&im);

    //about y axis, real part will get negated, imaginary part will remain same
    refl_re = -re;
    refl_im = im;
    //displaying reflected complex number
    printf("Reflected complex number: %d + i%d\n",refl_re,refl_im);

    //area of rectangle with length 2*re and height im
    area = 2*re*im;


    //displaying obtained area
    printf("Required area: %d units^2",area);

    return 0;
}

