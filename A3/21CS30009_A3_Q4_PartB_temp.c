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

    //Code to be excecuted until we find "k" multiples of "n"
    do{
        scanf("%d",&temp);
        //Checking if input is a multiple
        if(temp%n==0){
            //Count is increased since it is a multiple
            count+=1;
            
        }
    }while (count<k);

   
    return 0;
}