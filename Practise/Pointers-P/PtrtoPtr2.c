#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
    char word[20], **w;
    int n;
    scanf("%d", &n);
    w = (char**)malloc((n) * sizeof(char*));
    //w is an array of arrays (strings) basically 
    for (int i = 0; i < n; i++)
    { 
        scanf("%s",word);
        *(w+i)=(char*)malloc((strlen(word) + 1)* sizeof(char));
        strcpy(*(w+i), word);
    }
    for (int i = 0; i < n; i++)
    {
        printf("w[%d] = %s\n",i,*(w+i));
    }
    
    
    return 0;
}
