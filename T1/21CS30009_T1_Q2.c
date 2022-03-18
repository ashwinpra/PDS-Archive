//Program to take numbers from user continuously until 0 or -ve number is entered
//Then finds no. of non decreasing sub-sequences and the largest of such sub-sequences 
#include<stdio.h>

int main(){
    /* num to store each inputed number, count_ss to store no. of subsequences, 
    len to store length of sequence, temp to store previous input of user
    largest_len to store largest of "len" */
    int num=1,count_ss,len=0,temp,largest_len=0;

    //to terminate the program once 0 or -ve number is entered
    while(num>0){
        //temp stores the previous user input
        temp=num;
        scanf("%d",&num);
        
        //if new number is greater than or equal to previous number, then it is non decreasing
        if(num>=temp) len+=1;
        //length of sub-sequence incremented
            
        //if new number is lesser, that means the sub-sequence is over and new sub-sequence begins
        else{
            /* largest_len = length of first sub-sequence, after that if any sub-sequence has a larger
            length, it's length becomes largest_len */
            if(len>=largest_len) largest_len=len;
            //length starts from 1 again
            len=1;
            //count of sub-sequences is increased
            count_ss+=1;
        }
    }
    //displays required output
    printf("Total number of non-decreasing subsequences: %d\n",count_ss);
    printf("Length of longest non-decreasing subsequence: %d",largest_len);


    return 0;
}