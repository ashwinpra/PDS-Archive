/* Takes 'n' passwords from user as input and a structure is made which stores its
various attributes. Then we calculate similarity index for each pair of passwords.
Similarity index = % of same attributes (out of the 7 listed in structure) */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Making password structure
typedef struct{
    int length;
    int uppercase;
    int lowercase;
    int numbers;
    int special;
    int size;
    int strength;
    char content[50];
}password;

//Declaring required functions
void countChars(char*, int*, int*, int*, int*); //counts no. of uppercase, lowercase, numerical and special characters in a string
int findStrength(char*); //finds strength of the string (password)
float findSimilarity(password, password); //find similarity index of 2 passwords

int main() {
    //Declaring array of passwords and no. of passwords
    password *list;
    int n;
    //Taking user input for n
    printf("Enter number of passwords: ");
    scanf("%d", &n);
    //allocating required amount of memory for array
    list = (password*)malloc(n*sizeof(password));
    printf("Enter the %d passwords: \n",n);

    //loop to get user input for passwords and get all their parameters fin structure
    for(int i = 0; i < n; i++){
        //taking user input for each password
        scanf("%s", (list+i)->content);

        //length can be obtained from strlen()
        //since size of one character = 8 bits = 1 byte, size = length (in bytes)
        (list+i)->length = strlen((list+i)->content);
        (list+i)->size = strlen((list+i)->content);

        //calling function to get no. of uppercase, lowercase,numbers, special chars and store them in struct
        countChars((list+i)->content,&((list+i)->uppercase),&((list+i)->lowercase),&((list+i)->numbers),&(list+i)->special);

        //getting strength using function and storing in struct
        (list+i)->strength = findStrength((list+i)->content);

        //printf("uc = %d, lc = %d, nm = %d, sc = %d\n",(list+i)->uppercase,(list+i)->lowercase, (list+i)->numbers, (list+i)->special);
    }
    
    //loop to iterate through each pair of passwords and find their similarity index
    for(int i=0; i<n-1;i++){
        for(int j=i+1; j<n;j++){
            //finding similarity index using function
            float sim_index = findSimilarity(*(list+i),*(list+j));
            //displaying it approppriately 
            printf("For pair (%d-%d), similarity index = ",i+1,j+1);
            //just to avoid the trailing zeroes in case of 0 or 100
            if(sim_index == 0 || sim_index==100) printf("%d%%\n",(int)sim_index);
            else printf("%0.2f%%\n",sim_index);
        }   
    }

    return 0;
}

void countChars(char *str, int* u, int* l, int *n, int *s){
    *u=0,*l=0,*n=0,*s=0;
    for(int i=0; *(str+i) != '\0';i++){
        if(*(str+i) >= 'A' && *(str+i) <= 'Z') (*u)++;
        else if(*(str+i) >= 'a' && *(str+i) <= 'z') (*l)++;
        else if(*(str+i) >= '0' && *(str+i)<='9') (*n)++;
        else (*s)++;
    }

}

int findStrength(char *str){
    int strength = 0; //stores strength, which will be incremented
    int flag1=0,flag2=0;
    /* 1. strength is the number of chars between first uppercase and next lowercase letter (both included)
    2. if there is no lowercase after uppercase, strength = 1 
    3. if no uppercase, strength = 0 */
    
    for(int i=0; *(str+i) != '\0';i++){
        //looking for first uppercase
        //flag1=0 so that further uppercase characters are not counted
        if(*(str+i)>='A' && *(str+i)<='Z' && flag1==0){
            flag1++;
        }
        //once first uppercase has been found, strength is incremented from then
        if(flag1) strength++;

        //looking for next lowercase
        //flag1=1 to check if uppercase has already been found
        if(*(str+i)>='a' && *(str+i)<='z' && flag1==1){
            flag2++;
            break;
        }
    }
    if(flag2==0) return 1; //this means there was no lowercase after uppercase
    else return strength; //this also covers case 3 
}

float findSimilarity(password a, password b){
    //length, uppercase, lowercase, numbers, special, size, strength
    float sim=0;
    if(a.length == b.length) sim++;
    if(a.uppercase == b.uppercase) sim++;
    if(a.lowercase == b.lowercase) sim++;
    if(a.numbers == b.numbers) sim++;
    if(a.special == b.special) sim++;
    if(a.size == b.size) sim++;
    if(a.strength==b.strength) sim++;

    float percentage = (float)sim*100/7;
    return percentage;
}