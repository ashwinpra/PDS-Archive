//Program to calculate fuel sold(s) and total price based on day of the week and no.of vehicles(v)
//Monday(1), s=v/3
//Wednesday(3), s=2v/7 (rounded off to lowest int)
//Tues,Thurs,Fri(2,4,5), s = v^2+2v
//Sat,Sun(6,7), s = 3(v^2+2v)
//Cost = 120s + 25%(120s)
#include<stdio.h>
#include<math.h>

int main(){
    //Declaring all required variables
    int day;
    float v,s,cost;
    //Taking user input for all parameters
    printf("Day: ");
    scanf("%d",&day);
    printf("Vehicles sighted: ");
    scanf("%f",&v);

    //Assigning different values to s based on day
    switch(day){
    case 1:
        s=(float)(v/3);
        break;
    case 3:
        s=floor(2*v/7);
        break;
    case 2:
    case 4:
    case 5:
        s=(pow(v,2)+2*v);
        break;
    case 6:
    case 7:
        s=(3*(pow(v,2)+2*v));
        break;
    }
    //cost = s*120 + 25% of s*120 = s*120*(1+25/100) = s*120*(5/4) = s*150
    cost = (float)(150*s);
    //Displaying litres of fuel sold and total price
    printf("\nFuel sold 's': %0.2f\n",s);
    printf("Total price: %0.2f\n",cost);


return 0;
}
