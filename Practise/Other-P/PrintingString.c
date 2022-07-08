#include<stdio.h>

int main(int argc, char const *argv[])
{
    char str[50];
    printf("Enter a string: ");
    scanf("%s",str);
    printf("The string you have entered is: ");
    for(int i=0; str[i]!='\0';i++){
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}
