#include<stdio.h>

int main(int argc, char const *argv[])
{
    int age;
    printf("Enter your age:\n");
    scanf("%d",&age);
    
    if(age>18){
        printf("You are elligible!");
    }
    else if(age<10){
        printf("You are noob");
    }
    else if(age>18)
{
    printf("You are elligible!");
}
    return 0;
}
