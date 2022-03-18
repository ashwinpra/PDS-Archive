#include<stdio.h>
// actual parameters/argument - the parameters that are given to a function while calling it 
// for eg: for a function add(x,y) if we give int x=1; int y=2;
// formal parameters- the parameters that we use while making function -- they are assigned values of actual parameters
// eg: we make int add(int a, int b) then a and b are formal parameters

// we can call a function in two ways : by value and by reference
// call by value is what we normally do 
// call by reference is using address --> here original value changes
// it copies the address of the argument into the formal parameter

int swap (int *x, int *y){
    int temp; 
    temp = *x; // save the value at address x 
    *x = *y; // assign y into x 
    *y = temp; // assign temp, ie original value of x, to y 
    return;
}

void change(int *a){
    *a=4;
}
int main(int argc, char const *argv[])
{
    int a =5,b = 4,c=3;
    printf("a is %d and b is %d\n", a, b) ;
    swap(&a,&b);
    printf("a is %d and b is %d\n", a, b) ;
    printf("c is %d\n",c);
    change(&c);
    printf("c is %d\n",c);

    return 0;
}
