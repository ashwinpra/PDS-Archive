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

    //Assiging different values to s based on day
    switch(day){


    }
    return 0;
}
