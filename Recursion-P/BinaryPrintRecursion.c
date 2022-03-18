#include<stdio.h>
#include<string.h>
int n,k;
void char_buffer_rec(char number[],int n,int k, int a) {
    static int zerocount = 0;
    if(a>0) {
        if(zerocount<=k){
            number[n-a] = '0';
            zerocount++;
            char_buffer_rec(number,n,k-1, a-1);
        }
        number[n-a] = '1';
        char_buffer_rec(number,n,k, a-1);
    }
    else {
        printf("%s\n", number);
    }
}
 
int main(int argc, char const *argv[])
{   
    // int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter k: ");
    scanf("%d", &k);
    
    char number[100] = {0};
    char_buffer_rec(number, n,k,n);
    return 0;
}
