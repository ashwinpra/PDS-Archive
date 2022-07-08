#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sortArray(char**, int);

int main() {
    int n;
    printf("Enter number of words: \n");
    scanf("%d", &n);
    char **words, word;
    words = (char**)malloc(n*sizeof(char*));
    printf("Enter words: ");
    for(int i=0; i<n; i++) {
        scanf("%s", word);
        words[i] = (char*)malloc((strlen(word)+1)*sizeof(char));
        strcpy(words[i], word);
    }
    sortArray(words,n);
    printf("Sorted words: ");
    for(int i=0; i<n; i++) printf("%s ",words[i]);
    printf("\n");
    char ***dict; 

    

    return 0;
}

void sortArray(char **s, int n){
    char *temp;
    for(int i=0; i<n-1; i++){
        for(int j=0;j<n-1-i;j++){
                 if(strcmp(s[j],s[j+1])>1){
                    temp = (char *)malloc((strlen(s[j])+1)*sizeof(char));
                    strcpy(temp,s[j]);
                    strcpy(s[j],s[j+1]);
                    strcpy(s[j+1],temp);
            }
        }
    }
}