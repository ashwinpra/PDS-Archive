/* Takes user input as 2D character array (ie, 1D array of strings)
    Following operations are performed on the array:
    1) void characterCount(char* str, int* vowel, int* consonant) - 
        finds number of vowels and consonants and assigns it through respective pointer
    2) int wordCount(char* str) - 
        returns no. of words in string 
    3) void excessWord(char* str1, char* str2) - 
        checks wordcount of both strings, and prints words which are excess in larger string
    4) void str_pair_compute(char **arr, int number_of_strings) - 
        takes entire 2d array + number of strings in it as input, displays positions that contain same word
    NOTE: only string function that can be used is strlen
*/
#include<stdio.h>
#include<string.h>
//Declaring functions
void characterCount(char*, int*, int*);
int wordCount(char*);
void excessWord(char*, char*);
void wordsInString(char* , char[][1000]); //extracts word from string and saves it as a new 2d array
int isEqual(char*, char*);//check if two strings are equal
void str_pair_compute(char [][1000], int);

int main() {
    char string[5][1000];
    int v,c,wc;
    //Taking user input for 5 strings
    printf("Enter 5 strings: ");
    for(int i=0; i<5;i++){
        fgets(string[i],1000,stdin);
    }
    for(int i=0; i<5;i++){
        characterCount(string[i],&v,&c);
        wc = wordCount(string[i]);
        printf("For string %d: Word count = %d, Vowels = %d, Consonants = %d\n",i+1,wc,v,c);
    }
    int m,n;
    printf("Enter position of two strings to print excess words: ");
    scanf("%d %d",&m,&n);
    excessWord(string[m-1],string[n-1]);
    printf("Pairs are: ");
    str_pair_compute(string,5);
    return 0;
}

void characterCount(char* str, int* vowel, int* consonant){
    int v=0,c=0; //to store vowel and consonant count temporarily
    for(int i=0;*(str+i)!='\0';i++){
        //if its vowel, increment vowel count
        if(*(str+i) == 'a' || *(str+i) == 'e' || *(str+i) == 'i' || *(str+i) == 'o' || *(str+i) == 'u') v++;
        else if(*(str+i)==' ') continue; //if its space, do nothing
        else c++; //since there will be no other characters, we can say this is a consonant
        //so we increment consonant count
    
    }
    //returning vowel and consonant count through the pointers
    *vowel = v;
    *consonant = c;
}

int wordCount(char* str){
    int words = 1;
    for(int i=0;*(str+i)!='\0';i++){
        if(*(str+i) == ' ') words++;
    }
    return words;
}
 
void excessWord(char* str1, char* str2){
    if(wordCount(str1) == wordCount(str2)){
        printf("No excess word\n");
        return;
    }    
    char *lr = (wordCount(str1)>wordCount(str2)) ? str1 : str2;
    char *sr = (wordCount(str1)>wordCount(str2)) ? str2 : str1;
    int lrc=0;
    printf("Excess word(s): ");
    for(int i=0;*(lr+i)!='\0';i++){
        if(*(lr+i) == ' ') lrc++;
        if(lrc >= wordCount(sr)){
            printf("%c",*(lr+i));
        }
    }
    printf("\n");
}

void wordInString(char *str1, char str2[][1000]){
    int j=0,k=0; //j for index of each char, k for index of word
    for(int i=0;*(str1+i)!='\0';i++){
        
        if(*(str1+i) == ' '){
            *(*(str2+k) + j) = '\0'; //ending that word with null character
            j=0; //resetting index for next wordCount
            k++; //moving on to next word
            if(k==wordCount(str1)+1) return;
        }
        else{ //if it is not a space, it is copied to array
            *(*(str2+k) + j) = *(str1+i); 
            j++; //incrementing character index
        }
    }
}

int isEqual(char* str1, char* str2){
    //if lengths are not same, they are not equal
    if(strlen(str1)!=strlen(str2)) return 0;
    else{
        for(int i=0;*(str1+i)!='\0';i++){
            //if at any time characters are diff, they are not equal
            if(*(str1+i) != *(str2+i) && *(str1+i) !=' ' && *(str2+i) !=' ') return 0;
        }
    }
    return 1;
} 

void str_pair_compute(char arr[5][1000],int number_of_strings){
    //we will separate the words in two strings pairwise, and check if any are equal
    int ct=0,flag=0; //ct to check if the pair has been checked already, flag to check if there is any pair at all
    char words1[100][1000],words2[100][1000]; //2 arrays that will store words of arr[i] and arr[j] in each iteration
    for(int i=0;i<number_of_strings;i++){
        wordInString(arr[i],words1);//extracting words from arr[i]
        for(int j=i+1; j<number_of_strings; j++){
            wordInString(arr[j],words2); //extracting words from arr[j]
            //now we iterate within words1 and words2 to see if any words are equal
            for(int k=0;k<wordCount(arr[i]);k++){
                for(int l=0;l<wordCount(arr[j]);l++){
                    if(isEqual(words1[k],words2[l]) && ct==0){
                        printf("(%d, %d) ",i+1,j+1);
                        ct++; //incrementing ct and flag
                        flag++;
                    }
                }
            }
            ct=0; //resetting value of ct
        }
    }
    if(flag ==0) printf("Not applicable"); //if no pairs, print not applicable
    
}