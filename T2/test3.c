#include<stdio.h>



int main(int argc, char const *argv[])
{
    int sum=0;
    int n=5;
    int i=1;
    while(i++<n){
        sum+=i;
    }
    printf("%d",sum);
}
