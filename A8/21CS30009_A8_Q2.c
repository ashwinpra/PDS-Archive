/* Input a string in camel case notation and write 2 fns: 
1. numberOfWords -> calculate no. of words in it
2. camelToReverse -> store the words in reverse order separated by string
                     and prints it
*/
#include<stdio.h>
#include<string.h>
//Declaring required functions
int numberOfWords(char *);
void camelToReverse(char *, char *);

int main() {
    //declaring and taking user input for camel case string, also declaring array to store reverse
    char s[200],r[200];
    printf("Enter string in camel case format: ");
    scanf("%s", s);
    //displaying number of words by calling approppriate function
    printf("Number of words: %d\n", numberOfWords(s));
    //calling function to store and print reverse of string
    camelToReverse(s,r);
    return 0;
}

int numberOfWords(char *s){
    //initializing count variable
    int count = 0;
    //looping through each character of string
    for (int i = 0; *(s+i) != '\0'; i++)
    {
        //adds one to the count whenever uppercase is used (ie new word is typed)
        if(*(s+i) >= 'A' && *(s+i) <= 'Z') count++;
    }
    //retunring count
    return count;
}

void camelToReverse(char *s, char *r){
    int i=0, j= 0; //i for required index in s, j for required index in r (reverse)
    int start = strlen(s)-1, end = strlen(s)-1; //stores start and end index of each word in s 

    //looping through characters in s in reverse order
    while(start>=0){
        //checking for new word (identified by uppercase letter)

        if(*(s+start) >= 'A' && *(s+start) <= 'Z') {
            //this new word is transferred to r 
            //we copy s to r from this start index till the ending index
            i = start; //we start from this index 

            while(i<=end){ //ending at "end" index
                *(r+j) = *(s+i); //copying characters of s to r 
                i++;//incrementing index of s 
                j++; //incrementing index of r 

                //end + 1 instead of end because we have incremented i before it
                if(i==end+1){
                    //to add space at the end of each word 
                    *(r+j) = ' ';
                    j++; //incrementing index of r 
                }
            }
            
            if(start==0) break;//start = 0 implies we are done with all words, so loop is terminated
            else if(start!=0) end = start-1;//ending index for new word becomes starting index of prev word -1
        }
        
        start--; //decrementing index of s 

    }
    //adding null character to the end to complete the string 
    r[j]='\0';
    //printing reverse string
    printf("Reverse string:%s",r);
}