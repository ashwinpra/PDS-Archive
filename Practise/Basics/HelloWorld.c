#include <stdio.h>
#include <stdlib.h>
//define lol = 3
int main()
{
    char characterName[] = "John Doe";
    int characterAge = 5;
    double lol = 3.53;
    char lmao = 's';
    //#d  --> integer
    //%s --> string
    //%f --> float
    //% lf --> double
    //% l --> long
    // we have to use double slash in order to give it effect of one slash, otherwise it is considered like in /n
    // const before variable to make it constant , it cant be modified anymore
    printf("%s is %d years old\n",characterName,characterAge);
    return 0;
}
