//Input a long sentence as string, output the same sentence after removing non-alphabet characters
#include<stdio.h>

 
int main() {
    //Declaring string variable and taking user input 
    char str[200];
    printf("Enter sentence: ");
    scanf("%[^\n]s",str);
    
    //looping through characters of string
    for (int i = 0; str[i] != '\0'; i++) 
    {
        //printing character if it is an uppercase/lowercase letter
        if(str[i] >= 'a' && str[i] <= 'z') printf("%c",str[i]);
        else if(str[i] >= 'A' && str[i] <= 'Z') printf("%c",str[i]);
        //we will check for space(s) and replace it with " "
        else if(str[i] == ' ') {
            printf(" ");
            //skipping extra spaces if any
            while (str[i+1] == ' ') i++; 
            
        }
    }
    
    return 0;
}
