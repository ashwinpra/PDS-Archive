#include<stdio.h>

int search(int a[], int n, int m){
    //ok
}

void sort(int a[], int i, int m){
    int temp;
    if(i>m) return;
    //put this in a for loop
    if (a[i]>a[i+1]){
        temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
    }
    sort(a,i+1,m);
}

int main(int argc, char const *argv[])
{
    int n,m, a[100],k;
    printf("Enter size of array: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter m (Between 1 to %d): ",n);
    scanf("%d",&m);
    printf("Smallest %d elements in order:  ",m);
    sort(a,0,m);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    //search(a,n,m);
    return 0;
}
