//Remove duplicate characters from a string
#include<stdio.h>
#include<string.h>

void remove(char s[], char check){ 
    int count=0;
    if(check=='z') return;
    for(int i=0;s[i]!='\0';i++){
        //
    }
    remove(s, check+1);
}

int main(int argc, char const *argv[])
{
    char word[100];
    printf("Enter a random string: ");
    scanf("%s",word);
    int len=strlen(word);
    remove(word,'a');

    return 0;
}
