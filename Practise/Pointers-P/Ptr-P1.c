#include<stdio.h>
void checkChars(char[], int*, int*, int*);
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s",str);
    printf("String is %s\n",str);
    

    int lc=0,uc=0,dc=0;
   
   
    checkChars(str,&lc,&uc,&dc);
    printf("Number of lowercase characters: %d\n",lc);
    printf("Number of uppercase characters: %d\n",uc);
    printf("Number of digit characters: %d\n",dc);
    return 0;
}

void checkChars(char s[], int* l, int* u, int* d){
    for(int i=0; s[i] != '\0'; i++){
        if (s[i]>='a' && s[i]<='z') *l+=1;
        else if(s[i]>='A' && s[i]<='Z') *u+=1;
        else if(s[i]>='0' && s[i]<='9') *d+=1;
    }
}