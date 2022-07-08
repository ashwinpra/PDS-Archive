#include<stdio.h>
//go one by one swapping adjacent elements if they are in wrong order
int main(int argc, char const *argv[])
{
    int num[50];
    int n=1,i=0,count=0;
    int temp;
    while(n>0){
        scanf("%d",&n);
        if (n>0)  
        {
            num[i]=n;
            count++;
            i++;
        }
        else break;
    }
    printf("Before sorting: ");
    for (int j=0;j<count;j++){
        printf("%d ",num[j]);
    }
    printf("\n");
   // printf("Count is %d\n",count);
    
    for(i=0;i<(count-1);i++){
        for(int j=0;j<(count-i-1);j++)
        if(num[j]>num[j+1]){
            temp = num[j];
            num[j]=num[j+1];
            num[j+1]=temp;
        }
    }
    printf("After sorting: ");
    
    for (int j=0;j<count;j++){
        printf("%d ",num[j]);
    }

    return 0;
}
