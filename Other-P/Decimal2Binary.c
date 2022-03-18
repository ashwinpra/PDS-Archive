#include<stdio.h>

int main(int argc, char const *argv[])
{
    int dec;
    printf("Enter decimal to be converted to binary: ");
    scanf("%d",&dec);
    do{
        printf("%d",(dec%2));
        dec/=2;
    }while(dec!=0);

    return 0;
}
