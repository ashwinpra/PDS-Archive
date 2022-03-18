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
    //vol = pi*r*r*h
    vol=(float)(pi*r*r*h);
    //displaying height and vol
    printf("Height of the cylinder: %0.2f cm\nVolume: %0.2f cm^3\n",h,vol);

    //(2/3)vol * Rs. 10 + (1/3)vol + Rs. 2 = (22*vol)/3
    cost = (float)((22*vol)/3);
    //displaying required cost
    printf("Cost required to store with nitrogen gas: Rs. %0.2f",cost);


    return 0;
    }
