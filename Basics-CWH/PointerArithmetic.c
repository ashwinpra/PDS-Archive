#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a = 5;
    int* ptra = &a;
    printf("%d\n",ptra);
    printf("%d\n",ptra+1);// adds to the size of ptra (here, adds one size)

    char b = '5';
    char* ptrb = &b; 
    printf("%d\n",ptrb);
    printf("%d\n",ptrb+1);
    return 0;
}
