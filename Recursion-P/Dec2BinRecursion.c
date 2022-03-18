#include<stdio.h>
#include<math.h>
int decToBin(int n){
    static float i=0.1;
    int rem;
    if (n>=1) {
        rem = n%2;
        i*=10;
        return (int)(i)*rem + decToBin(n/2);
        
    }
    else return 0;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);  
    printf("Its binary form is %d",decToBin(n));
    return 0;
}
