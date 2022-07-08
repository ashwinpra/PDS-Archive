#include<stdio.h>
// break used to exit from loop 
// continue used to skip some code inside loop and continue from next iteration
int main(int argc, char const *argv[])
{
    int i, age;

    for(i=0; i<=10;i++)
    {
        printf("Enter your age:\n");
        scanf("%d",&age);
        // if(age<10)
        // {
        //     break; // only breaks out of the loop you are currently in (imp in case of nested loops!)
        // }
        if(age>10){
            continue;
        }
        printf("Sorry!\n");
    }
    return 0;
}
