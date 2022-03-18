#include<stdio.h>
#include<string.h>
int countChar(char, char[]);

int main() {
    //find first and last occurence of a character
    char s[100];
    printf("Enter string: ");
    scanf("%s", s);
    char c;
    printf("Enter character to check occurence: ");
    scanf(" %c", &c);
    int ct= countChar(c,s);
    printf("Number of occurences : %d\n",ct);
    if(ct==0) printf("Character not found\n");
    else if(ct==1) {
        for (int i = 0; i < strlen(s); i++)
        {
            if(s[i]==c) printf("First and only occurence at index %d",i);
        }
        
    }
    else {
        int count=0,flaga=0,flagb=0;
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i]==c) count++;
            if (count==1 && flaga==0) {
                printf("First occurence at index %d\n",i);
                flaga++;
            }
                
            if(count==ct && flagb==0) {
                printf("Last occurence at index %d\n",i);
                flagb++;
            }
            
        }
    }
    return 0;
}

int countChar(char c, char s[]){
    int count=0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i]==c) count++;
    }
    return count;
}