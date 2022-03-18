#include<stdio.h>
//search for a specifc element in an array

int search (int a[], int l, int u, int k){
    int h=(l+u)/2;
    if(a[h]==k) printf("%d is a part of the array", k, h);
    else if (a[h]>k) return search(a,l,h-1,k);
    else return search(a,h+1,u,k);

}

void sort (int a[], int n){
    //let us use bubble sort 
    int temp;
    for (int j=0;j<n-1;j++){
        for (int i=0;i<j;i++){
            if(a[i-1]>a[i]){
                temp = a[i-1];
                a[i-1] = a[i];
                a[i] = temp;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int n, a[100],k;
    printf("Enter size of array: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    sort(a,n);

    printf("Check element to be searched: ");
    scanf("%d",&k);

    search(a,0,n-1,k);

    return 0;
}
