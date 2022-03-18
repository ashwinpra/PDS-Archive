#include <stdio.h>
//using euclidean algorithm
int main(int argc, char const *argv[])
{
    int a,b,hcf;
    
    printf("Enter first number:");
    scanf("%d",&a);
    printf("Enter second number:");
    scanf("%d",&b);
    
    //making b>a for the code to run as required
    if (a>b){
        hcf=a;
        a=b;
        b=hcf;
    }
    while(b%a !=0){
        hcf = b%a; 
        b=a;
        a=hcf;
    }
    printf("The hcf is %d\n",hcf);
    printf("The lcm is %d",a*b/hcf);
    return 0;
}

