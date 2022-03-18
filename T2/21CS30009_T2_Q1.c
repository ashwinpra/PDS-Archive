/* Store n integer values in 1D array, searches for a key value pair
//if key value present, shift elements on the right to the left and puts key element at the end
if not found then display error message */
#include<stdio.h>

int search(int, int, int[]); //To search for key value in array

int main()
{
    //Declaring variables for key value and integer array
    int key,a[100];
    //Declaring and taking user input for number of elements in array
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    //For loop for getting elements of array from user 
    printf("Enter the values in the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the key value: ");
    scanf("%d", &key);
    //getting index of key value (if present) from the function
    int index = search(key,n,a);
    if(index!=-1) {
        for (int i = index; i < n; i++)
        {   
            a[i]=a[i+1];
        }
        a[n-1]=key;
        for (int i = 0; i < n; i++)
        {
            printf("%d ",a[i]);
        }
        
    }
    else printf("Key element not found!");
    return 0;
}
//takes parameters as key value, size of array, and array respectively
//returns index if its present, -1 otherwise
int search(int x, int n, int a[]){
    //searches through the array using for loop, if match is found, returns index
    for(int i=0; i<n; i++){
        if(a[i]==x) return i; 
    }
    //else it returns -1
    return -1;
}