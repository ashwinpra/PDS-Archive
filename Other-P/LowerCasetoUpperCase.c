#include<stdio.h>

int main(int argc, char const *argv[])
{
    char c;
    printf("Enter a character: ");
    scanf(" %c",&c);

    if(c>='a' && c<='z'){
        c = ('A'+(c -'a'));
        printf("\nUppercase of the character is: %c",c);
    }
    else{
        printf("It is already uppercase");
    }
    return 0;
}
