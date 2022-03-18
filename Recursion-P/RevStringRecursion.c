#include<stdio.h>
#include<string.h>
//if we make modifications within the string, we wont have to return anything
void swap (char *a,char *b){
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void revString(char s[],int k){
    static int i=0;
    if(s[k] == '\0') return;
    revString(s,k+1);
    if (i<=k) swap(&s[i++],&s[k]); 
    
}

int main(int argc, char const *argv[])
{
    char word[100];
    printf("Enter a word: ");
    scanf("%s",word);
    revString(word,0);
    printf("Its reverse is %s",word);
    return 0;
}
