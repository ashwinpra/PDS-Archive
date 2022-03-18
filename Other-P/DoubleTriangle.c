#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n,count1=0,count2=0;
    scanf("%d",&n);
    //number of lines
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            if(j>i && j<=(2*n-i)) printf(" ");
            else printf("%d",i);
            

                
        }
        printf("\n");
    }
    return 0;
}
