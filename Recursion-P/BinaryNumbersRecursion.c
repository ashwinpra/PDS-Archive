#include<stdio.h>
#include<string.h>
//Print all binary numbers of length n containing k zeroes
//It will be union of '1'+(n-1,k) and '0'+(n,k-1)

void binary(int n, int k, char bin[]){
    if(n<k) return;
    if(n==0) printf("%s",bin);
    if(n==1 && k==0) strcat(bin,"1");
    else if(n==1 && k==1) strcat(bin,"0");
    binary(n-1,k,strcat(bin,"1"));
    binary(n-1,k-1,strcat(bin,"0"));
}

int countBinary(int n, int k){
    if (n<k) return 0;
    if (n==1) return 1;
    if (k==0) return 1;
    return countBinary(n-1,k) + countBinary (n-1,k-1);
}

int main(int argc, char const *argv[])
{
    int n,k;
    char bi[100];
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter k: ");
    scanf("%d",&k);
    printf("Total count: %d", countBinary(n,k));
    binary(n,k,bi);
    return 0;
}
