#include<stdio.h>
#include<math.h>

//check whether a number cn be written as a sum of two primes 
int isPrime(int n){
    int count=0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) count++;
    }
    if (count==0) return 1;
    else return 0;
}
int sumOfPrimes(int n){
    int check=0;
    for(int i=1;i<n;i++){
        if(isPrime(i)==1 && isPrime(n-i)==1){
            printf("It can be expressed as a sum of primes\n");
            check++;
            break;
        }
    }
    printf("%d",check);
    if(check==0)  printf("It cannot be expressed as a sum of primes\n");
}
int main(int argc, char const *argv[])
{   
    int x;
    printf("Enter number to check: ");
    scanf("%d",&x);
    sumOfPrimes(x);

    return 0;
}