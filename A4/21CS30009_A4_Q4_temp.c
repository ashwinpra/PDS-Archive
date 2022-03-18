/* Program where user inputs character array of size n and:
    In each iteration no. of vowels (k) are counted, and elements of array are printed after skipping
    first k elements. This becomes new array for next iteration
    Iterations are carried out until there are no more vowels or no more letters 
    Note: keep track of beginning index of new array and proceed from that index from next itr
*/
#include<stdio.h>
int main(){
    //declaring and taking user input for size of queue
    int n,vow_count,count_total=0,index=0;
    //q is the character array(queue)
    char q[100];
    printf("Enter size of queue: ");
    scanf("%d",&n);
    //taking user input for elements of queue
    printf("Note: please enter lowercase characters\n");
    printf("Original queue: ");
    for(int i=0;i<n;i++){
        scanf(" %c",&q[i]);
    }


    for(int j=1;j<n;j++){
        printf("-----Iteration %d-----\n",j);
        //looping through and finding number of vowels
        for(int k=index;k<n;k++){
            if(q[k]=='a' || q[k]=='e' || q[k]=='i' || q[k]=='o' || q[k]=='u'){
                vow_count++;
            }
        }
        index+=vow_count;
        vow_count=0;
        printf("New queue: ");
        for(int l=index;l<n;l++){
            printf("%c ",q[l]);
            count_total++;
            if(q[l]=='a' || q[l]=='e' || q[l]=='i' || q[l]=='o' || q[l]=='u'){
                vow_count++;
            }
        }
        printf("\n");
        if(count_total==0 || vow_count==0){
            if(count_total==0) printf("NIL");
            return 0;
        }
        vow_count=0;
        count_total=0;
    }
    return 0;
}
