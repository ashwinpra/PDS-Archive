#include<stdio.h>
int main(int argc, char const *argv[])
{
    // we can do it in two ways:
    //1. by declaring array as parameter of function
    //2. by declaring pointer in function to hold base address(arr[0]) of array
    // if you change the value of array it gets reflected in the main function

    // Method 1.
    int fn1(int arr[]){
        int s,i;
        for (i=0;i<3;i++)
        {
            s=s+arr[i];
        }
        return s;
    }
    int arr[] = {1,2,3};
    int sum = fn1(arr);
    printf("Sum of elements is %d\n",sum);

    //Method 2.

    int fn2(int* ptr)
    {   
        *(ptr+2)=4;
        return 0;
    }
    int j;
    fn2(arr);
    for (j=0;j<3;j++)
        {
            printf("%d\n",arr[j]);
        }

    return 0;
}
