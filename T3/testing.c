#include<stdio.h>
 
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
    //strength is the number of chars between first uppercase and next lowercase letter (both included)
    //if there is no lowercase after uppercase, strength = 1
    //if no uppercase, strength = 0
    for(int i=0; *(str+i) != '\0';i++){
        //flag1=0 so that further uppercase characters are not counted
        if(*(str+i)>='A' && *(str+i)<='Z' && flag1==0){
            flag1++;
        }
        if(flag1) strength++;
        //flag1=1 to check if uppercase has already been found
        if(*(str+i)>='a' && *(str+i)<='z' && flag1==1){
            flag2++;
            break;
        }
    }
    if(flag2==0) return 1;
    else return strength; //this also covers case 3 
}

int main() {
    char s[100];
    scanf("%s",s);
    int uc,lc,nm,sc;
    countChars(s,&uc,&lc,&nm,&sc);
    printf("uc = %d, lc = %d, nm = %d, sc = %d\n",uc,lc,nm,sc);
    int str = findStrength(s);
    printf("Strength = %d\n",str);
    return 0;
}
