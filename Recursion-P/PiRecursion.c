#include<stdio.h>
#include<string.h>
//Accept a random string from user, and replace all occurences of "pi" with 3.14

void pi(char s[],int n){
    if(s[n]=='\0') return;
    if(s[n]=='p' && s[n+1]=='i'){
        printf("3.14");
        pi(s,n+1);
    }
    else 
    {
        printf("%c",s[n]);
        pi(s,n+2);
    }
}
int main(int argc, char const *argv[])
{
    char word[100];
    printf("Enter a random string: ");
    scanf("%s",word);
    int len=strlen(word);
    pi(word,0);    
    return 0;
}
