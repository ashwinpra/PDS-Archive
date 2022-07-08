//Program to calculate relative grade of 10 students based on their scores
#include<stdio.h>
#include<math.h>
const int size = 10;
int main(){
    //defining array 
    int marks[size];
    //i is looping variable, n is temp variable to store marks, avg is average and sd is standard deviation
    int i=0,n=1;
    float avg=0,sd=0;
    //taking user input and ensuring marks are in range of 0-100
    while(i<size){
        scanf("%d",&n);
        if(n>=0 && n<=100){
            marks[i]=n;
            //adding each marks to avg to eventually find average
            avg+=marks[i];
            i++;
        }
        else {
            printf("Please enter again\n");
            continue;
        }
    }
    //dividing sum by size to get average
    avg/=size;
    //iterating through each marks to find standard deviation
    for(int j=0;j<size;j++){
        sd+=pow((marks[i]-avg),2);
    }
    //diving by size and taking sqrt to get standard deviation
    sd=sqrt(sd/size);

    //assigning grade to each student based on marks 
    for(int k=0;k<size;k++){
        if(marks[k]>=(avg+1.5*sd)) printf("Grade of student %d = 10",(k+1));
        else if(marks[k]>=(avg+sd) && marks[k]<(avg+1.5*sd)) printf("Grade of student %d = 9",(k+1));
        else if(marks[k]>=(avg+0.5*sd) && marks[k]<(avg+sd)) printf("Grade of student %d = 8",(k+1));
        else if(marks[k]>=(avg) && marks[k]<(avg+0.5*sd)) printf("Grade of student %d = 7",(k+1));
        else if(marks[k]>=(avg-0.5*sd) && marks[k]<(avg)) printf("Grade of student %d = 6",(k+1));
        else if(marks[k]>(avg-sd) && marks[k]<(avg-0.5*sd) ) printf("Grade of student %d = 5",(k+1));
        else if(marks[k]>=(avg-1.5*sd) && marks[k]<(avg-sd)) printf("Grade of student %d = 4",(k+1));
    }
    
return 0;
}