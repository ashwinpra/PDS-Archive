#include<stdio.h>
#include<string.h>
int isPair(char *str1, char *str2){
    if(strlen(str1)!=strlen(str2)) return 0;
    else{
        for(int i=0;i<*(str1+i)!='\0';i++){
            if(*(str1+i) != *(str2+i)) return 0;
        }
    }
    return 1;
} 

int main() {
    // printf("%d, ",isPair("lol","lmao"));
    // printf("%d, ",isPair("lol","lol"));
    // printf("%d ",isPair("lol","lox"));
    return 0;
}
