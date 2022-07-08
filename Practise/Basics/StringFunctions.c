#include<stdio.h>
#include<string.h>

//strcat() -- used to concatenate/combine two given strings
//strcat([string to be stored in],pointer of other string)
//strlen() -- gives length of string
//sttrev() -- gives reverse of string
//strcpy() -- used to copy one string to another  --> used to assign value to string
//strcmp() -- used to compare two given strings --> returns integer
// for more, search "string.h reference"

int main(int argc, char const *argv[])
{
    char firstname[]="Ashwin";
    char secondname[]="Prasanth";
    char fullname[30];

    int i;
    i = strlen(firstname);
    printf("Ur name is %s and Length of ur name is %d\n",firstname,i);
    
    strcpy(fullname,strcat(firstname,secondname)); //IMP: we cant do fullname = strcat(firstname,secondname)
    puts(fullname);
    return 0;
}
