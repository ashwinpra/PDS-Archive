#include<stdio.h>
 
int main() {
    int x=10, *p, **q;
    p = &x, q=&p;
    printf("%d %d %d\n", x,*p,**q);
    int **r,*s[3];
    r = (int **)malloc(3*sizeof(int*));
    return 0;
}
