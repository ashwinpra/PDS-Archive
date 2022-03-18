#include <stdio.h>
// Variable which stores "address" of another variable
// asterisk (*) used to declare it
// for some variable var, &var gives its "address"
//  (*) is dereference operator, used to get value at a given address
// null pointer does not store anything eg: int *ptr = NULL
// we use it to initialize a pointer variable when it isnt assigned any value YET

int main(int argc, char const *argv[])
{
    int a = 5;
    int *p = &a;
    printf("address of a is %x\n", p);  // x for hexadecimal (format of address)
    printf("address of a is %x\n", &a); //%p is used to reference pointer
    printf("Value of a is %d\n", *p);   //dereferencing pointer

    return 0;
}
