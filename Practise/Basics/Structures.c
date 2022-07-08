#include <stdio.h>

//user-defined datatypes
// allows to combine data of different types together
// used to create complex data type which contains diverse information
// similar to arrays but more useful

//structures can be assigned to one another like s1 = s2, unlike arrays 
//but they cannot be compared, like s1==s2
//we can even make an array of structures


struct info //"info" is the new data type
    {
        int id;
        int marks;
        char favchar;
    } s1, s2, s3; // or we can also declare like struct s1,s2,s3; in separate line
    // here s1, s2, s3 have become global variables
    //each sub-variable in a structure is accesed by using dot, eg: info.id

int main(int argc, char const *argv[])
{
    int i;
    s1.id=1;
    s2.id=2;
    s1.marks=100;
    s2.marks=92;
    s1.favchar='a';
    s2.favchar='b';
    struct info s3 = {3,93,'c'};//this is also valid
    
    printf("%d",s3.marks);
    

    return 0;
}
