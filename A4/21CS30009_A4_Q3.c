/* Program to perform following game: 
    User enters number of buckets "N" and also number of balls in each of these buckets
    Keep iterating through and finding bucket(s) with least no. of balls and removing balls from those buckets
    Iteration is done until all buckets are empty
*/
#include<stdio.h>
int main(){
    /*n is no. of buckets, min keeps track of minimum element in each itr, 
        count_total keeps track of empty buckets, to see when program should terminate
        count_itr keeps track of number of buckets with min balls (ie empty buckets in each itr)
    */
    int n,min=100000,count_total=0,count_itr=0;
    //array which will store no. of balls in each bucket
    int ball[100];
    //taking user input for number of buckets 
    printf("Enter Number of Buckets: ");
    scanf("%d",&n);
    printf("Enter Positive Number of Balls fo Each %d Buckets: ",n);
    //taking user input through loop for no. of balls in each bucket
    for(int i=0;i<n;i++){
        scanf("%d",&ball[i]);
    }

    //looping through iterations until there are no more balls
    for(int j=1;count_total<n;j++){
        printf("-----Iteration %d-----\n",j);
        //loop to find minimum no. of balls, and skip those which are empty
        for(int k=0;k<n;k++){
            if(ball[k]!=0){
                if(ball[k]<min) min=ball[k];
            }
        }
        //loop to remove "min" no. of balls from each bucket and count empty buckets
        for(int l=0;l<n;l++){
                if(ball[l]!=0){
                    ball[l]-=min;
                if(ball[l]==0){
                    count_total++;
                    count_itr++;
                }
            }
        }
        //displaying result after each iteration
        printf("Number of buckets with least number of balls = %d\n",count_itr);
        printf("Number of balls in the Remaining buckets = ");
        //loop to print only those buckets with nonzero balls
        for(int m=0;m<n;m++){
            if(ball[m]!=0){
               printf("%d ",ball[m]);
            }
            //if all buckets are empty, we print NIL and terminate
            else if(count_total==n){
            printf("NIL\n");
            return 0;
        }
        }
        printf("\n");
        //resetting count_itr and min for next iteration
        count_itr=0;
        min=100000;
    }


    return 0;
}