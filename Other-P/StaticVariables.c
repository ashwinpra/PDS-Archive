#include<stdio.h>
int fib(int,int);
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    if (n==0 || n==1) printf("F(%d)=%d\n",n,1);
    else printf("F(%d)=%d\n",n,fib(n,2));
    return 0;
}

int fib(int n,int i){
    static int m1,m2; //these remain in existence rather than coming and going everytime fn is called
    //otherwise new variables of same name are formed everytime fn is called 
    int res,temp;
    if(i==2){m1=1;m2=1;}
    if(n==i)res=m1+m2;
    else{
        temp=m1;
        m1=m1+m2;
        m2=temp;
        res=fib(n,i+1);
    }
    return res;
}
