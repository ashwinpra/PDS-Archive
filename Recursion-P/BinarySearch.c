#include<stdio.h>
//to search for a specific element in a sorted array
//first check if a[n/2] = k, else check first half of array or second half based on if it is > or <
int binSearch(int A[], int low, int high,int k){
    int mid; 
    printf("low = %d, high = %d\n",low,high);
    if (low>high) return 0;
    mid = (low+high)/2;
    printf("mid = %d, A[%d] = %d\n\n",mid,mid,A[mid]); 
    if (A[mid]==k) return 1;
    else{
        if(A[mid]>k) return binSearch(A,low,mid-1,k);
        else return binSearch(A,mid+1,high,k);
    }
}

int main(int argc, char const *argv[])
{
    int a[25],n,k,i,found;
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    found = binSearch(a,0,n-1,k);

    if (found==1) printf("%d is present in the array\n",k);
    else printf("%d is not present in the array\n",k);
    
    
    return 0;
}
