//Program to print number of digits of 3 numbers inputed by user
//Also to check whether a triangle can be made with these 3 number of digits as sides
#include<stdio.h>

int main(){
    //Declaring required variables
    long int n1,n2,n3;
    int d1=0,d2=0,d3=0;
    //Taking user input for n1,n2,n3
    scanf("%ld",&n1);
    scanf("%ld",&n2);
    scanf("%ld",&n3);
    //Finding number of digits of n1,n2,n3 (d1,d2,d3 respectively)
    while(n1!=0){
        d1+=1;
        n1/=10;
    }
    while(n2!=0){
        d2+=1;
        n2/=10;
    }
    while(n3!=0){
        d3+=1;
        n3/=10;
    }
    //Displaying d1,d2 and d3
    printf("%d\n",d1);
    printf("%d\n",d2);
    printf("%d\n",d3);

    //Checking whether triangle is possible, using triangle inequality
    if(d1<(d2+d3) && d2<(d1+d3) && d3<(d1+d2)){
        printf("Yes\n");
        //Checking type of triangle as triangle is possible
        if(d1==d2 && d2==d3 && d1==d3) printf("Equilateral");
        else if (d1!=d2 && d2!=d3 && d1!=d3)  printf("Scalene");
        else printf("Isosceles");
        }
    else printf("Triangle not possible");

    return 0;
}