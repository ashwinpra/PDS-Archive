/* Program to perform following game: 
    User enters number of buckets "N" and also number of balls in each of these buckets
    Keep iterating through and finding bucket(s) with least no. of balls and removing balls from those buckets
    Iteration is done until all buckets are empty
*/
#include<stdio.h>
int main(){
    //declaing no. of buckets and array which will store no. of balls in each bucket
    int n,itr,min=100000,count_total=0,count_itr=0,check=0;
    int ball[100];
    //taking user input for number of buckets 
    printf("Enter Number of Buckets: ");
    scanf("%d",&n);
    printf("Enter Positive Number of Balls fo Each %d Buckets: ",n);
    //taking user input through loop for no. of balls in each bucket
    for(int i=0;i<n;i++){
        scanf("%d",&ball[i]);
    }


    for(int j=1;count_total<n;j++){
        printf("-----Iteration %d-----\n",j);
        //loop to find minimum no. of balls, and skip those which are empty
        for(int k=0;k<n;k++){
            if(ball[k]!=0){
                if(ball[k]<min) min=ball[k];
            }
        }
        //loop to remove all those buckets with this min no. and keep count of them
        for(int l=0;l<n;l++){
                if(ball[l]!=0){
                    ball[l]-=min;
                if(ball[l]==0){
                    count_total++;
                    count_itr++;
                }
            }
        }
        printf("Number of buckets with least number of balls = %d\n",count_itr);
        printf("Number of balls in the Remaining buckets = ");
        //loop to print only those buckets with nonzero balls
        for(int m=0;m<n;m++){
            if(ball[m]!=0){
               printf("%d ",ball[m]);
               check++;
            }
        }
        if(check==0){
            printf("NIL\n");
            return 0;
        }
        printf("\n");
        count_itr=0;
        min=100000;
        check=0;
    }


    return 0;
}