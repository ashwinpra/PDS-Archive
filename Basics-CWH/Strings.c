#include <stdio.h>

void printStr(char str[]){
    int i=0;
    while(str[i]!='\0');
    {
        printf("%c",str[i]);
        i++;
    }
} // simply


int main(int argc, char const *argv[])
{
    //we use array to represent string --> string is a null terminated character array
    //it is an array of characters which terminates in null character ("\0")

    char name[7] = "Ashwin"; //OR char name[]= {'A','s','h','w','i','n','\0'};
    char hi[6] = "hello";    // it is 6 instead of 5  because we also need to store \0
    printf("%s,%s\n", name, hi);
    char str[20];
    gets(str);
    printf("%s", str); //OR puts(str);
    return 0;
}