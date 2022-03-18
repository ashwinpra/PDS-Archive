//Program to print a pattern of length decided by user

//Observations: It is square of 2n+1 spaces, some of which is * and some blank
//First and last line are all starts
//First and last space of each line are also stars
//Distance of the line from (n+1)th line ("dist") = distance after which two stars come (one from first, one from last)
//An extra star in (n+1)th space of (n+1)th line

#include<stdio.h>
#include<math.h>
int main(){
    int n,dist,len;
    scanf("%d",&n);
    //len stores the length of row and column
    len=(2*n+1);
    //"i" is row, "j" is each entry of row
    for(int i=1;i<=len;i++){
        dist = abs(n+1-i);
        for(int j=1;j<=len;j++){
            if(i==1 || i==len) {
                //if it is either first or last line, its full stars
                printf(" * ");
            }
            else{
                if(j>1 && j<=(dist+1)) printf("   ");
                else if(j>=(len-dist) && j<len) printf("   ");
                else if (j==1 || j==len) printf(" * ");
                 else {
                    if((dist+j)%2==0){
                        printf(" * ");
                    }
                    else printf("   ");
                }
        }
            }
           
        //To go to next line after printing pattern in row
        printf("\n");
    }


    return 0;
}