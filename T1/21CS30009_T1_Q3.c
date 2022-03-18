//Program to print a pattern of length decided by user

/*Observations: 
It is square of 2n+1 spaces, some of which is * and some blank
First and last line are all *
First and last spaces of each line are also *
Distance of a line from (n+1)th line ("dist") = distance after which two *s come (one from first space, one from last space)
An extra * in (n+1)th space of (n+1)th line
*/
#include<stdio.h>
#include<math.h>
int main(){
    //n stores length of pattern, dist stores distance of line from (n+1)th line, len stores length of square (2n+1)
    int n,dist,len;
    //Taking user input for "n"
    scanf("%d",&n);
    len=(2*n+1);
    //"i" is row, "j" is each space of row
    for(int i=1;i<=len;i++){
        dist = abs(n+1-i);
        for(int j=1;j<=len;j++){
             //If it is either first or last line, its full *
            if(i==1 || i==len) printf(" * ");
            //Otherwise, first, last, and those spaces after "dist" length from first and last space, are *
            //All other spaces are blank, except for (n+1)th space in (n+1)th row
            else{
                if(j==1 || j==len || j==(dist+2)|| j==(len-dist-1)) printf(" * ");
                else{
                    if(j==(n+1) && i==(n+1)) printf(" * ");
                    else printf("   ");
                }
            }
        }
        //To go to next line after printing pattern in row
        printf("\n");
    }


    return 0;
}