/*
Discs of increasing size are sacked on the left pole, smallest at the top and largest at the bottom
It is required to transfer all discs to the right pole, following the rules: 
1) Only one disc can be moved at a time
2) Larger disc cannot be placed on a smaller disc 
3) A middle pole canbeused for temporary storage only
*/
#include<stdio.h>

void toh(int n, char from, char to, char aux){
    if(n==1) {
        printf("Disk 1: %c --> %c\n",from,to);
        return;
    }
    toh(n-1,from,aux,to);
    printf("Disk %d: %c --> %c\n",n,from,to);
    toh(n-1,aux,to,from);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    toh(n,'A','C','B');
    return 0;
}
