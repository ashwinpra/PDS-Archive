//Program to output time of arrival when starting time, duration and direction is given
//Speed of airplane: 700km/h
#include<stdio.h>

int main(){
    //Declaring required variables
    int hr,min,duration,time_change,hr_change,min_change,day;
    char dirn;
    //Taking user input for all parameters
    printf("Starting hour: ");
    scanf("%d",&hr);
    printf("Starting minute: ");
    scanf("%d",&min);
    printf("Duration: ");
    scanf("%d",&duration);
    printf("Direction: ");
    scanf(" %c",&dirn);

    if(hr>=0 && hr<24 && min>0 && min<60) {
        printf("\nStarting time is valid.\n");
        //700*duration will be distance, and every 500 km distance, time changes by 1hr
        //Also multiplying by 10 in order to get hr and min by modulus
        time_change = ((70*duration)/5);
        min_change = (time_change%10)*6;
        hr_change = (time_change-(time_change%10))/10;
        //this time change is incremented in case of e and decremented in case of w

        if(dirn=='e'){
            hr+=hr_change;
            min+=min_change;
            //Adjusting min and/or hr in case of overflow
            //"day" variable used to keep track of which day (-1 => previous day, 0=> same day,1=> next day)
            if (min>=60){
                min=min-60;
                hr+=1;
            }
            else{
                min=min;
            }
            if (hr>=24){
                hr=hr-24;
                day=1;
            }
            else{
                day=0;
            }
            }
        else if(dirn=='w'){
            hr-=hr_change;
            min-=min_change;
            //Adjusting min and/or hr in case of underflow
            if (min<0){
                min=min+60;
                hr-=1;
            }
            else{
                min=min;
            }
            if (hr<0){
                hr=hr+24;
                day= -1;
            }
            else{
                day=0;
            }


        }

        printf("Arrival time hour: %d\n",hr);
        printf("Arrival time minute: %d\n",min);

        switch(day){
        case -1:
            printf("Arrival day: previous day\n");
            break;
        case 0:
            printf("Arrival day: same day\n");
            break;
        case 1:
            printf("Arrival day: next day\n");
            break;
        }
    }
    else{
        printf("Starting time is invalid.\n");
    }

return 0;
}
