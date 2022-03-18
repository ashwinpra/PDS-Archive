//Program to find the absolute difference between consecutive elements of an array inputed by user
#include<stdio.h>
//Globally declaring number of elements in array so that it can be used by function
int num;
//Declaring functions
void abs_diff(int, int); //to find absolute difference between two numbers
void array_diff(int [],int); //to find absolute difference between consecutive elements of array

int main()
{
    //Declaring array
    int ar[100];
    //Taking user input for size of array and corresponding elements
    printf("Enter the number of elements of the array: ");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        printf("Enter a number: ");
        scanf("%d",&ar[i]);
    }
    //Executing the function in main()
    array_diff(ar,num);
    return 0;
}

void abs_diff(int a,int b){
    int c = a - b;
    printf("The absolute difference of %d and %d is: ",a,b);
    //Returning c or -c, based on sign of c, to make it positive eventually
    if(c>=0) printf("%d\n",c);
    else printf("%d\n",-c);
}
