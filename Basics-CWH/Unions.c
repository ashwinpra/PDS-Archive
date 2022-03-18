#include<stdio.h>

int main(int argc, char const *argv[])
{
    union ashwin {
        int a; 
        float b;
        char c;
    };

    union ashwin s1;
    
    return 0;
}

//very similar to structure, it is user defined data type
// it cannot handle all members at once, it handles a shared memory for all variables, from which we can access one at a time
// memory used by structure - sum (var1, var2, var 3...)
// memory used by union - max (var1, var2, var3...)