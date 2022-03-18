/* Prints n rows of binary bit patterns following given rules:
1) first row starts with 0
2) in each subsequent row, "0" is replaced with "01" and "1" is replaced with "10"
RECURSION MUST BE USED
 */
#include<stdio.h>
void theithSymbol(int [], int,int);
void clearArray(int [],int);
int main()
{
    //Declaring and taking user input for n(number of rows)
    int n;
    int a[100];
    printf("Enter the value of n: ");
    scanf("%d", &n);
    //Since C prints 01 integer as 1, we need to print 0 in the beginning everytime
    for (int i = 1; i <=n; i++)
    {
        theithSymbol(a,i,1);
        printf("Value of Row %d: ",i);
        for(int j=0;a[j]==0||a[j]==1;j++){
            printf("%d",a[j]);
        }
        printf("\n");
    }
    
    return 0;
}
void clearArray(int a[],int size){
    for(int i=0;i<size;i++){
        a[i]=2;
    }
}
void theithSymbol(int a[],int n,int size){
    clearArray(a,size);
    a[0]=0;
    if(n==size) return;
    if(a[n-1]==0){
        for(int i=size;i>=(n-1);i--){
            a[i]=a[i-1];
        }
        a[n-1]=1;
        theithSymbol(a,n+1,2*size);
    }
    else if(a[n-1]==1){
        for(int i=size;i>(n-1);i--){
            a[i]=a[i-1];
        }
        a[n-1]=0;
        theithSymbol(a,n+1,2*size);
    }
}