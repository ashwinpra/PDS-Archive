#include <stdio.h>
//Program to find transpose of user-inputted matrix
//make a[i][j]=a[j][i]
int main(int argc, char const *argv[])
{
    int m,n,i,j,temp;
    int a[100][100];
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m,&n);

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Original matrix: \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
            //prevent it from swithing twice
        }
    }

    printf("Transposed matrix: \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
