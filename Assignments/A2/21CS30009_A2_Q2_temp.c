//Program to determine grade of steel based on Hardness, Carbon Content and Tensile Strength
//Condition 1: Hardness > 60
//Condition 2: Carbon content > 0 and <0.65
//Condition 3 : Tensile str > 6400

#include<stdio.h>
int main(){

    //Declaring all required variables
    int hardness,tensile;
    float carbon;

    //Taking user input for 3 parameters
    printf("Hardness: ");
    scanf("%d",&hardness);
    printf("Carbon Content: ");
    scanf("%f",&carbon);
    printf("Tensile Strength: ");
    scanf("%d",&tensile);


    //Displaying grade based on conditions satisfied
    if (hardness>60 && carbon>0 && carbon<0.65 && tensile>6400){
        printf("Grade: 10");
    }
