//First check if number is triangular, and if yes, print triangle pattern comprising from 1 to that number
#include<stdio.h>

int main(){
    int i,j,n,check,rows,count=1;
    printf("Enter a number: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        if (n==i*(i+1)/2) {
            check++;
            rows=i;
    }
    }
    i=1;
    if(check==1){
        //code to print triangle
        for(i=1;i<=rows;i++){
            count+=(i-1);
            for(j=count;j<(count+i);j++){
                printf(" %d ",j);
            }
            printf("\n");
        }
    }
    else printf("Not a triangular number");


    return 0;
}