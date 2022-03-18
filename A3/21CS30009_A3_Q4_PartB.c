//Program that will run until "k" multiples of "n" are inputed by user
//Then displays the maximum and minimum of these inputs 
#include<stdio.h>

int main(){
    //Declaring required variables
    //Also min and max to store minimum and maximum multiples respectively
    //temp to store user input in each iteration
    //count to keep track of number of multiples inputed
    int n,k,min=999999999,max=0,temp,count=0;
    //Taking user input for above variables
    printf("n=");
    scanf("%d",&n);
    printf("k=");
    scanf("%d",&k);

    //To prevent 0 or -ve input
    while(n<=0 || k<=0){
        printf("Please enter again\n");
        printf("n=");
        scanf("%d",&n);
        printf("k=");
        scanf("%d",&k);
    }

    //Code to be excecuted until we find "k" multiples of "n"
    do{
        scanf("%d",&temp);  //Taking user input for numbers

        if(temp<=0) continue;  //To prevent considering 0 or -ve numbers as valid input

        //Checking if input is a multiple
        if(temp%n==0){
            //Count is increased since it is a multiple
            count+=1;
            //First multiple will always become max, then if other multiples are greater than it, then they become max
            if(temp>max){
                max=temp;
            }
            //First multiple will always become min, then if other multiples are lesser than it, then they become min
            if(temp<min){
                min=temp;
            }
        }
    }while (count<k);

    //Printing maximum and minimum multiples which were found above
    printf("\nMaximum multiple: %d\n",max);
    printf("Minimum multiple: %d\n",min);
   
    return 0;
}