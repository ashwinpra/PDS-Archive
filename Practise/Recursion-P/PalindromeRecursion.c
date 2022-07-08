//check if string is palindrome using recursion
#include<stdio.h>
#include<string.h>
//FIX IT
int palindromeCheck(char s[], int ul, int ll){
    int len=strlen(s);
    if(len%2!=0){
        if(s[ul]==s[ll] && ul==ll) return 1;
        if(s[ul]==s[ll]) return palindromeCheck(s,ul+1,ll-1);
        else return 0;
    }
    else return 0;
}

int main(int argc, char const *argv[])
{   
    char word[100];
    printf("Enter a word: ");
    scanf("%s",word);
    int len = strlen(word);
    if(palindromeCheck(word, 0, len-1)==1) printf("It is a palindrome");
    else printf("It is not a palindrome");
    return 0;
}
