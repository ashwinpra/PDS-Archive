#include<stdio.h>
int main(int argc, char const *argv[])
{
    int sum (int a, int b){
        return a+b;
    }
    void printstar(int n){
        int i;
        while(i<n){
            printf("*\n");
            i=i+1;
        }
        
    }
    int enterNumber(){
        int x;
        printf("Enter a number:\n");
        scanf("%d",&x);
        return x;
    }
    void welcome()
    {
        printf("Welcome to my calculator!\n");
    }
    welcome();
    int p=enterNumber();
    int q=enterNumber();
    int r = sum(p,q);
    printf("Their sum is %d\n",r);
    printstar(10);
    return 0;
}
