// print rectangle, triangle, inverted triangle

#include<stdio.h>

int main(){
    int rows, cols; 
    int i,j;
    
    printf("Enter number of rows: ");
    scanf("%d",&rows);
    printf("Enter number of columns: ");
    scanf("%d",&cols);

    for (i=1;i<=rows;i++){
        
        for(j=1;j<=cols;j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}