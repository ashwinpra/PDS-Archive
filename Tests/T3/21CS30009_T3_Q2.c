/* Takes 'n' passwords from user as input and a structure is made which stores its
various attributes. Then we calculate similarity index for each pair of passwords.
Similarity index = % of same attributes (out of the 7 listed in structure) */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Making password structure
typedef struct{
    int length, uppercase, lowercase, numbers, special, size, strength;
    char content[50];
}password;

//Declaring required functions
void makeList(password*, int); //to populate the list(array) with user inputs and their attributes
void printList(password*, int); //to print attributes of each password in list(array)
void countChars(char*, int*, int*, int*, int*); //counts no. of uppercase, lowercase, numerical and special characters in a string(password)
int findStrength(char*); //finds strength of a string (password)
float findSimilarity(password, password); //finds similarity index of 2 passwords

int main() {
    //Declaring array of passwords and no. of passwords
    password *list;
    int n;

    //Taking user input for n
    printf("Enter number of passwords: ");
    scanf("%d", &n);

    //allocating required amount of memory for array
    list = (password*)malloc(n*sizeof(password));

    //taking passwords from user and calling approppriate functions
    printf("Enter the passwords: \n");
    makeList(list,n);
    printList(list,n);

    //loop to iterate through each pair of passwords and find their similarity index
    for(int i=0; i<n-1;i++){
        for(int j=i+1; j<n;j++){
            //finding similarity index using function
            float sim_index = findSimilarity(*(list+i),*(list+j));

            //displaying it approppriately 
            printf("\nSimilarity index between %d-%d: ",i+1,j+1);
            //just to avoid the trailing zeroes in case of 0 or 100
            if(sim_index == 0 || sim_index==100) printf("%d%%\n",(int)sim_index);
            else printf("%0.2f%%\n",sim_index);
        }   
    }

    return 0;
}

void makeList(password* list, int n){
    //loop to get user input for passwords and get all their attributes in structure
    for(int i = 0; i < n; i++){
        //taking user input for each password
        scanf("%s", (list+i)->content);

        //length can be obtained from strlen()
        //since size of one character = 8 bits = 1 byte, size = no. of characters = length (in bytes)
        (list+i)->length = strlen((list+i)->content);
        (list+i)->size = strlen((list+i)->content);

        //calling function to get no. of uppercase, lowercase, numerical and special characters and store them in struct
        countChars((list+i)->content,&((list+i)->uppercase),&((list+i)->lowercase),&((list+i)->numbers),&(list+i)->special);

        //calling function to get strength and storing in struct
        (list+i)->strength = findStrength((list+i)->content);

    }
}


void printList(password *list, int n){
    //iterating through the list(array)
    for(int i=0; i<n; i++){
        printf("\n%s: Length = %d, No. of uppercase = %d, No. of lowercase = %d, No. of digits = %d, No. of special characters = %d, Size = %d, Strength = %d\n",(list+i)->content,(list+i)->length,(list+i)->uppercase,(list+i)->lowercase,(list+i)->numbers,(list+i)->special,(list+i)->size,(list+i)->strength);
    }
    printf("\n"); //just for better appearance of output
}

void countChars(char *str, int* u, int* l, int *n, int *s){
    //using pointers as counters so that 4 variables can be returned
    *u=0,*l=0,*n=0,*s=0; //setting counters to 0 

    //iterating through characters of the string
    for(int i=0; *(str+i) != '\0';i++){
        //checking if a certain character is uppercase, lowercase, numerical or none of them (ie, special)
        //accordingly, counter is incremented
        if(*(str+i) >= 'A' && *(str+i) <= 'Z') (*u)++;
        else if(*(str+i) >= 'a' && *(str+i) <= 'z') (*l)++;
        else if(*(str+i) >= '0' && *(str+i)<='9') (*n)++;
        else (*s)++;
    }
}

int findStrength(char *str){
    int strength = 0; //stores strength, which will be incremented
    int flag1=0,flag2=0; //flag1 for uppercase, flag2 for lowercase

    /* 1. strength is the number of chars between first uppercase and next lowercase letter (both included)
    2. if there is no lowercase after uppercase, strength = 1 
    3. if no uppercase, strength = 0 */
    
    //iterating through characters of the string
    for(int i=0; *(str+i) != '\0';i++){
        //looking for first uppercase character
        //flag1=0 condition so that further uppercase characters are not counted
        if(*(str+i)>='A' && *(str+i)<='Z' && flag1==0){
            flag1++;
        }
        //once first uppercase has been found, strength is incremented from then
        if(flag1) strength++;

        //looking for next lowercase character
        //flag1=1 condition to check if uppercase has already been found
        if(*(str+i)>='a' && *(str+i)<='z' && flag1==1){
            flag2++;
            //stops iterating once lowercase is found, as we have obtained strength
            break; 
        }
    }
    if (flag1==0) return 0;  //this means that there was no uppercase (case 3)
    else if(flag1!=0 && flag2==0) return 1; //this means there was no lowercase after uppercase (case 2)
    else return strength; //case 1
}

float findSimilarity(password a, password b){
    //attributes: length, uppercase, lowercase, numbers, special, size, strength

    float sim=0; //counter to store no. of similarities

    //incrementing sim for each similar attribute
    if(a.length == b.length) sim++;
    if(a.uppercase == b.uppercase) sim++;
    if(a.lowercase == b.lowercase) sim++;
    if(a.numbers == b.numbers) sim++;
    if(a.special == b.special) sim++;
    if(a.size == b.size) sim++;
    if(a.strength == b.strength) sim++;

    //getting the percentage as required and returning it
    float percentage = (float)sim*100/7;
    return percentage;
}
