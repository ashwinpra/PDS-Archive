//Input a long sentence as string, output the same sentence after removing non-alphabet characters
#include<stdio.h>
int spaces(char *, int);
void replace(char *, int);
 
int main() {
    //Declaring string variable and taking user input 
    char str[200];
    printf("Enter sentence: ");
    scanf("%[^\n]s",str);
    int flag=0;
    //looping through characters of string
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if(str[i] >= 'a' && str[i] <= 'z') continue;
        else if(str[i] >= 'A' && str[i] <= 'Z') continue; 
        //we will check for space(s) and replace it with " "
        else if(str[i] == ' ') {
            //if there are spaces, it is removed until only one space is left
            while(spaces(str,i)!=1) replace(str,i);
        }
        else {
            //if it is an unwanted character, we remove it by shifting each subsequent character back by one
            replace(str,i);
            i--;
            //in this case since everything is shifted backwards, we must continue with same index to go to next char, so i--
    }
    }
    printf("%s",str);
    
    return 0;
}
//to give number of consecutive spaces in a string starting from certain index
//parameters; string, index from which checking starts
int spaces(char *str, int index){
    int i = index;
    int spacecount = 0;
    while(str[i++]==' '){
        spacecount++;
    }
    return spacecount;
}
//to replace an unwanted character by shifting all the characters to the right if it backward by 1
//parameters: string, index of unwanted character
void replace(char *str, int index){
    int li;
    for(int j=index;str[j] != '\0';j++){
         *(str+j) = *(str+j+1);
        li=j;
    }
    str[li+1]='\0'; //adding null character at end 
}