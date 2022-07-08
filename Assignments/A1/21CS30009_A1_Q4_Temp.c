//Program to get height of cylinder, given radius and total surface area
//Also to calculate the cost of storing a perfume to fill (2/3)rd of cylinder at Rs.10 per cm^3 and rest with N2 gas at Rs.2 per cm^3

#include<stdio.h>
#include<math.h>
const float pi = 3.141;


int main(){

float r,tsa,h,vol,cost;

//printf and scanf to get radius and total surface area
printf("Enter radius and total surface area of cylinder (in cm):\n");
scanf("%f %f",&r,&tsa);

// TSA = 2*pi*r*h + 2*pi*r*r, from this h is found
// h = (TSA-2*pi*r^2/2*pi*r)
h = (float)((tsa - 2*pi*r*r)/(2*pi*r));


return 0;
}
