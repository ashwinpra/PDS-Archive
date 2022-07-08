//accept integers from user until they press enter
//find largest and second largest out of these
#include<stdio.h>
#include<windows.h>
int main(int argc, char const *argv[])
{
    int num=0, temp1=0,temp2=0, max=0,semax=0; 
    while (getchar()!='\n'){
        
        temp1=num;
        temp2=max;
        
        scanf("%d",&num);
        if (num>temp1) {
            max = num;
            semax= temp2;
        }
    }
    printf("Greatest number is: %d\n",max);
    printf("Second greatest number is: %d",semax);
    
    
    return 0;
}
