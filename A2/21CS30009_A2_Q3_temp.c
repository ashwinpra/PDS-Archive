//Program to output time of arrival when starting time, duration and direction is given
//Speed of airpane: 700km/h
#include<stdio.h>

int main(){
    //Declaring required variables
    int hr,min,duration;
    char dirn;

    //Taking user input for all parameters
    printf("Starting hour:");
    scanf("%d",&hr);
    printf("Starting minute:");
    scanf("%d",&min);
    printf("Duration:");
    scanf("%d",&duration);
    printf("Direction:");
    scanf("%c",&dirn);

    if(hr>0 && hr<24 && min>0 && min<60) {
        if(dirn=='e'){

        }
        else if (dirn =='w'){

        }
    }
    else{
        printf("Starting time is invalid.")
    }

return 0;
}
