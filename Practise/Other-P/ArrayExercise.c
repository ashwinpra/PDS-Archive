//read two arrays A and B of sizes m and n (decided by user)
//find two elements A - x,y and one in B - z such that x+y = z
//also find union, intersection and difference of both arrays 
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int m,n;
    int x,y,z;
    int A[100];
    int B[100];
    printf("Enter size of A: ");
    scanf("%d",&m);
    printf("Enter elements of A: \n");
    for(int i=0;i<m;i++){
        scanf("%d",&A[i]);
    }
    printf("Enter size of B: ");
    scanf("%d",&n);
    printf("Enter elements of B: \n");
    for(int j=0;j<n;j++){
        scanf("%d",&B[j]);
    }
    //loop through A one inside other, inside that loop through B and see if any pair adds up to B[i]
    for(int j=0;j<(m-1);j++){
        x=A[j];
        printf("x is %d\n",x);
        for(int k=(j+1);k<m;k++){
            y=A[k];
            printf("y is %d\n",y);
            for(int i=0;i<n;i++){
                z=B[i];
                printf("z is %d\n",z);
                if(x+y==z) printf("%d+%d=%d\n",x,y,z);
                else printf("No %d+%d != %d\n",x,y,z);
            }
           
        }
    }
    return 0;
}
