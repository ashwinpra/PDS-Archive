#include <stdio.h>

int main(int argc, char const *argv[])
{
    //size of string includes null character
    //string constant::
    //treated as a pointer whose value is base address of string 
    char *p = "abc";
    printf("%s %s",p,p+1);//returns abc, bc
    
    //do practise problems
    
    return 0;
}
