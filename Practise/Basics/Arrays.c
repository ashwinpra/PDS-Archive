#include<stdio.h>
int main(int argc, char const *argv[])
{
    int num,i,j;
    printf("Enter number of students:\n");
    scanf("%d",&num);
    int marks [num];
    for(i=1;i<=num;i++){
        printf("Enter mark of student %d:\n",i);
        scanf("%d", &marks[i]);  
    }
    for(j=1;j<=num;j++){
        printf("Mark of student %d is %d\n",j, marks[j]); 
    }
   return 0;
}