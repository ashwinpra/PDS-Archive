#include<stdio.h>
#include<string.h>

void anagramCheck(char a[],char b[]){
    int len = strlen(a);
    int count=0;
     if(strlen(b)==len){
        for(int i=0;a[i]!='\0';i++){
            if(a[i]==b[len-i-1]) {
                count++;
            }
        }
        if (count==len) printf("They are anagrams");
        else printf("They are not anagrams");
    }
    else printf("They are not anagrams");
}
int main(){
   anagramCheck("ratio","oitar");
    return 0;
}