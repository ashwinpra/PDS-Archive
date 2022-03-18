#include<stdio.h>

int main(){

    int n;
    int sort[100];
    int min,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&sort[i]);
    }    
    printf("Before sorting: ");
    for(int i=0;i<n;i++){
        printf(" %d",sort[i]);
    }  
    printf("\n");
    for(int i=0;i<(n-1);i++){
        min = i;
        for(int j=i+1;j<n;j++){
            if (sort[min]>sort[j]) min=j;
            }
        temp=sort[i];
        sort[i]=sort[min];
        sort[min]=temp;
    }
    printf("After sorting: ");
    for(int i=0;i<n;i++){
        printf(" %d",sort[i]);
    }  
    printf("\n");

    return 0;
}