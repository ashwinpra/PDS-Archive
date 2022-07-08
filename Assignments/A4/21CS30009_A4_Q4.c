/* Program where user inputs character array of size n and:
    In each iteration no. of vowels (k) are counted, and elements of array are printed after skipping
    first k elements. This becomes new array for next iteration
    Iterations are carried out until there are no more vowels or no more letters 
    Note: keep track of beginning index of new array and proceed from that index from next itr
*/
#include<stdio.h>
int main(){
    //n for size of queue, vow_count for keeping count of vowels
    //count_total to check if number of letters have become 0, and index to keep track of new index
    int n,vow_count=0,count_total=0,index=0;
    //q is the character array(queue)
    char q[100];
    //taking user input for size of queue
    printf("Enter size of queue: ");
    scanf("%d",&n);
    //taking user input for elements of queue
    printf("Note: please enter lowercase characters\n");
    printf("Original queue: ");
    for(int i=0;i<n;i++){
        scanf(" %c",&q[i]);
    }

    //iteration loop
    for(int j=1;j<n;j++){
        printf("-----Iteration %d-----\n",j);
        //looping through and finding number of vowels
        for(int k=index;k<n;k++){
            if(q[k]=='a' || q[k]=='e' || q[k]=='i' || q[k]=='o' || q[k]=='u'){
                vow_count++;
            }
        }
        //after each loop, index will change from current to current+vowel count
        index+=vow_count;
        //resetting vowel count for checking below
        vow_count=0;
        //displaying new queue
        printf("New queue: ");
        for(int l=index;l<n;l++){
            printf("%c ",q[l]);
            //checking if either number of letters are 0 or number of vowels are 0
            count_total++;
            if(q[l]=='a' || q[l]=='e' || q[l]=='i' || q[l]=='o' || q[l]=='u'){
                vow_count++;
            }
        }
        printf("\n");
        //if they are zero, then program is terminated
        if(count_total==0 || vow_count==0){
            if(count_total==0) printf("NIL");
            return 0;
        }
        //vow_count and count_total resetted for next itr
        vow_count=0;
        count_total=0;
    }
    return 0;
}
