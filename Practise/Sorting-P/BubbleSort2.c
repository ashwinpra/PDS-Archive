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
    int count=0;
    for(int i=0;i<(n-1);i++){
        for(int j=0;j<(n-i-1);j++){
            if (sort[j]>sort[j+1]){
                count++;
                temp=sort[j];
                sort[j]=sort[j+1];
                sort[j+1]=temp;
            }
        }
    }  
    printf("After sorting: ");
    for(int i=0;i<n;i++){
        printf(" %d",sort[i]);
    }  
    printf("\n");
    printf("%d",count);

    return 0;
}