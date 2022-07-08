/* Program to input an array of user-defined size and do the following operations:
//Numbers in even positions are copied in reverse order
//Numbers in odd position is square root of sum of squares of all numbers to its right, rounded
Note: positions not indices */
#include<stdio.h>
#include<math.h>
int main(){
    //arr will store original array, newarr will store modified one
    int arr[100],newarr[100];
    //n to store size of array
    //sqsum to store sqrt of sum of square of array elements
    int n;
    float rms=0;
    //accepting user input for size and elements of array
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("Enter elements of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //loop to assign elements to newarr
    for(int j=0;j<n;j++){
        //even indices means odd positions, and vice versa
        if(j%2==0){
            for(int k=(j+1);k<n;k++){
                //adding square of each elements after corresponding element
                rms+=pow(arr[k],2);
            }
            //taking sqrt of rms and multiplying with corresponding element
            newarr[j] = (int)(arr[j]*sqrt(rms));
            //reseting value of rms for next iteration
            rms=0;
        }
        else{
            //since it is even positions, we store them in reverse order
            if(n%2==0){
                //if n is even, the indices of even positions we have to switch always add up to n
                newarr[j]=arr[n-j];
        }
            else {
                //if n is odd, the indices add up to n-1
                newarr[j]=arr[n-1-j];
        }
        }
        

    }
        printf("\n");
        for(int i=0;i<n;i++){
            printf("%d ",newarr[i]);
        }

    return 0;
}
