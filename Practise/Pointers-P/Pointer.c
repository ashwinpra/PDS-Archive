#include<stdio.h>
 
//when we add or subtract from a pointer, we actually add/subtract that value*scale factor
//scale factor depends upon data type storage req.
//& returns address of variable, * returns variable pointed at by pointer
//we pass a pointer to a function when we wish to edit the variable in main directly 
//for example: 

void swap(int *x, int *y){
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
//we can return multiple variables from a function by just 
//assigning the return values through pointers to variables
typedef struct{
    int id,age;
}person;

int main() {
    int n=5;
    printf("%u is address\n",&n);
    person *p1; 
    //int*p = p1->id; //this is to access address of elements of strct
    int a=4,b=3;
    printf("a = %d,b = %d\n",a,b);
    // int *p = &a;
    // b=*p;
    // printf("a = %d,b = %d\n",a,b);
    swap(&a,&b);
    printf("a = %d,b = %d\n",a,b);

    int *ptr;
    *ptr=5;
    printf("*ptr = %d,ptr = %u\n",*ptr,ptr);

    // a[i] => *(a+i)
    //a[i][j] => *(*(a+i)+j)

    return 0;
}
