//Program to print numbers which are multiple of either or both of two numbers (x and y) out of 'n' numbers
#include<stdio.h>

int main(){
    //Declaring required variables, also count to see if we got 0 numbers
    int n,x,y,count=0;
    //Taking user input for above variables
    printf("n: ");
    scanf("%d",&n);
    printf("x: ");
    scanf("%d",&x);
    printf("y: ");
    scanf("%d",&y);

    //looping through all the numbers from 1 to n to check if they are a multiple
    for(int i =1; i<=n;i++){

        if (i%x==0 || i%y==0){
            //printing those numbers which are multiple of either x or y or both
            printf("%d\n",i);
            count+=1;
        }

    }

    //if no numbers were chose, count would not have been incremented, ie, game lost
    if(count==0){
        printf("Game Lost");
    }

    return 0;
}